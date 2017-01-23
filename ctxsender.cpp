#include "ctxsender.h"

CtxSender::CtxSender(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(imageChange()), SLOT(sendData()));
}

void CtxSender::connectTcp()
{
    if(isConnected == false ){
        imagesocket = new QTcpSocket( this );
        connect( imagesocket, SIGNAL(readyRead()), SLOT(readTcpData()) );
        connect( imagesocket, SIGNAL(connected()), SLOT(setBool()) );

        imagesocket->connectToHost("192.168.1.110", 4321);
        imagesocket->waitForConnected();
    }
}

void CtxSender::setData(){
    QImage img("image.png");
    image = img;
   qDebug() << img.byteCount();
    emit imageChange();
}

void CtxSender::setBool(){
    isConnected = true;
}


void CtxSender::sendData(){
    if(isConnected == true ) {
        QImageWriter writer;
        writer.setDevice(imagesocket);
        writer.setFormat("png");
        writer.write(image);
        //imagesocket->flush();
    }
    else{
        qDebug() << "NOT CONNECTED";
    }
}


void CtxSender::readTcpData()
{
    qDebug() << "Client =>" + imagesocket->readAll();
}
