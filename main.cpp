#include <QApplication>
#include <QBasicTimer>
#include <QThread>
#include <QImage>
#include <QMediaPlayer>
#include<QMediaRecorder>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QQuickView>
#include <QQmlContext>
#include <QPushButton>
#include <QtCore/QStandardPaths>
#include <QtCore/QStringList>
#include <opencv2/opencv.hpp>
#include <QQmlApplicationEngine>
#include <libONVIF/devicesearcher.h>
#include <libONVIF/client.h>
#include <libONVIF/devicemanagement.h>
#include <libONVIF/mediamanagement.h>
#include <libONVIF/ptzmanagement.h>



#include "capture.h"
#include "converter.h"
#include "imageviewer.h"
#include "imageprovider.h"
#include "servoclient.h"
#include "myserver.h"
#include "ctxprovider.h"
#include "ctxsender.h"
#include "captureqt.h"

using namespace ONVIF;

Q_DECLARE_METATYPE(cv::Mat)



int main(int argc, char *argv[])
{
    qRegisterMetaType<cv::Mat>();
    QApplication app(argc, argv);


    //ImageViewer view;
   Capture capture;
   Converter converter;
   QThread captureThread, converterThread,ctxThread;
    //Everything runs at the same priority as the gui, so it won't supply useless frames.
    converter.setProcessAll(false);
    captureThread.start();
    converterThread.start();
    //ctxThread.start();
    capture.moveToThread(&captureThread);
    converter.moveToThread(&converterThread);

//    QmlVlcPlayer* player = new QmlVlcPlayer;
//    player->set_mrl("rtsp://admin:123456@192.168.1.200:554/mpeg4");
    QObject::connect(&capture, SIGNAL(matReady(cv::Mat)),&converter,SLOT( processFrame(cv::Mat)));
//    player->play();


//    MediaManagement *mm = new MediaManagement("http://192.168.1.200/onvif/device_service", "admin", "123456");
//    //MediaManagement *mm = new MediaManagement("http://192.168.1.123/onvif/device_service", "admin", "123456");
//    StreamUri *stru = new StreamUri;
//    stru = mm->getStreamUri();
//    qDebug() << "=============================================================================================================";
//    qDebug() << stru->uri();

//    PtzManagement *ptz = new PtzManagement("http://192.168.1.200/onvif/device_service", "admin", "123456");
//    Configurations* configptz = ptz->getConfigurations();
//    ContinuousMove *move= new ContinuousMove;
//    move->setProfileToken(configptz->getToken()[0]);
//    //move->setPanTiltY(config->getPanTiltYRangeMin()[0]);
//    move->setPanTiltSpace(configptz->getDefaultContinuousPanTiltVelocitySpace()[0]);
//    move->setPanTiltX(configptz->getPanTiltX()[0]);
//    move->setTimeout(configptz->getDefaultPTZTimeout()[0]);
//    move->setZoomSpace(configptz->getZoomSpace()[0]);
//    move->setZoomX(configptz->getZoomX()[0]);
//    ptz->continuousMove(move);




    QQuickView view;
    ImageProvider *imagep = new ImageProvider;
    CtxProvider* ctxp = new CtxProvider;
    CtxSender* ctxs = new CtxSender;
    Servoclient *myservo = new Servoclient;
    Myserver *myserver = new Myserver;

    view.rootContext()->engine()->addImageProvider("myprovider",imagep);
    view.rootContext()->engine()->addImageProvider("myctxprovider",ctxp);

    QObject::connect(&converter, SIGNAL(imageReady(QImage)),imagep,SLOT(setImage(QImage)));
//    view.rootContext()->setContextProperty("ptz",ptz);
//    view.rootContext()->setContextProperty("move",move);
//    view.rootContext()->setContextProperty("config",configptzf);
    view.rootContext()->setContextProperty("myprovider",imagep);
    view.rootContext()->setContextProperty("myctxprovider",ctxp);
    view.rootContext()->setContextProperty("myservo",myservo);
    view.rootContext()->setContextProperty("myctxclient",ctxs);
    view.rootContext()->setContextProperty("myserver",myserver);
    view.rootContext()->setContextProperty("capture", &capture);
    view.rootContext()->setContextProperty("converter", &converter);


    const QUrl appPath(QUrl::fromLocalFile(app.applicationDirPath()));
    const QStringList picturesLocation = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    const QUrl imagePath = picturesLocation.isEmpty() ? appPath : QUrl::fromLocalFile(picturesLocation.first());
    view.rootContext()->setContextProperty("imagePath", imagePath);


    view.setMinimumSize( QSize( 1920, 1080 ) );
    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    //view.showFullScreen();
    view.show();



    QObject::connect((QObject*)view.engine(), SIGNAL(quit()), &app, SLOT(quit()));
    QObject::connect(&capture, &Capture::started, [](){ qDebug() << "capture started"; });
    QMetaObject::invokeMethod(&capture, "start");


    int rc = app.exec();
    //capThread->quit();
    captureThread.quit();
    converterThread.quit();
    captureThread.wait();
    converterThread.wait();
    return rc;
}
