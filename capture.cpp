#include "capture.h"

Capture::Capture(QObject *parent) :
    QObject(parent)
{

}

void Capture::start() {
    if (!m_videoCapture)
        //m_videoCapture.reset(new cv::VideoCapture("rtspsrc location=rtsp:///admin:123456@192.168.0.123:554/mpeg4 ! queue ! decodebin ! autovideoconvert ! appsink", CV_CAP_GSTREAMER));
        //m_videoCapture.reset(new cv::VideoCapture(videoAdresse, CV_CAP_ANY));
        m_videoCapture.reset(new cv::VideoCapture(0));


        //m_videoCapture->set(CV_CAP_PROP_BUFFERSIZE,3);
        //m_videoCapture->set(CV_CAP_PROP_FPS,60);
    if (m_videoCapture->isOpened()) {
        m_timer.start(0, this);
        emit started();
    }
}

void Capture::stop() { m_timer.stop(); }

void Capture::timerEvent(QTimerEvent * ev) {
    if (ev->timerId() != m_timer.timerId()) return;

    if (!m_videoCapture->read(frame)) { // Blocks until a new frame is ready
        m_timer.stop();
        return;
    }
    emit matReady(frame);
}

