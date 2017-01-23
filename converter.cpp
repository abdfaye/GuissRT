#include "converter.h"

using namespace cv;
Converter::Converter(QObject *parent) :
    QObject(parent), m_processAll(true)
{
    connect(this, SIGNAL(startRecord()), SLOT(initRecord()));
    connect(this, SIGNAL(stopRecord()), SLOT(endRecord()));
}

void Converter::matDeleter(void* mat)
{
    delete static_cast<cv::Mat*>(mat);
}
void Converter::queue(const cv::Mat & frame) {
    if (!m_frame.empty()) qDebug() << "Converter dropped frame!";
    m_frame = frame;
    if (! m_timer.isActive()) m_timer.start(0, this);
}

void Converter::process(cv::Mat frame) {
    //cv::resize(frame, frame, cv::Size(),1, 1, cv::INTER_AREA);
    //cv::transpose(frame, frame); //shield
    //cv::flip(frame, frame, 1); //shield
    if (m_record ==1){
        m_videoWriter.write(frame);
    }
//    qDebug() << frame.type();
//    qDebug() << frame.channels();
    cv::cvtColor(frame, frame, CV_RGB2BGR);

    const QImage image(frame.data, frame.cols, frame.rows, frame.step,
                       QImage::Format_RGB888, &matDeleter, new cv::Mat(frame));
//    qDebug() << image.constBits();
//    qDebug() << frame.data;

//    Q_ASSERT(image.constBits() == frame.data);
    emit imageReady(image);
}
void Converter::timerEvent(QTimerEvent * ev) {
    if (ev->timerId() != m_timer.timerId()) return;
    process(m_frame);
    m_frame.release();
    m_timer.stop();
}
void Converter::setProcessAll(bool all) { m_processAll = all; }
void Converter::processFrame(const cv::Mat & frame) {
//        qDebug() << "converter----------------------------------------------------------------------------------------";
    if (m_processAll) process(frame); else queue(frame);
}

void Converter::initRecord(){
    QDateTime now = QDateTime::currentDateTime();
    QString name = now.toString("ddMMyyhhmmss");
    int format = m_videoWriter.fourcc('M','J','P','G');
    double fps = 15;
    cv::Size videoS;
    videoS.height = 1080;
     videoS.width = 1920;
    m_videoWriter.open(name.toStdString()+".mpeg", format  ,  fps , videoS , true);
    m_record = 1;
}
void Converter::endRecord(){
    m_record = 0;
   // m_videoWriter.release();
}

