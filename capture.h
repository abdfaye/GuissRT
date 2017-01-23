#ifndef CAPTURE_H
#define CAPTURE_H

#include <QObject>
#include <QBasicTimer>
#include <QThread>
#include <QImage>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <opencv2/opencv.hpp>

class Capture : public QObject
{
    Q_OBJECT
    QBasicTimer m_timer;
    QScopedPointer<cv::VideoCapture> m_videoCapture;
public:
    explicit Capture(QObject *parent = 0);
    cv::Mat frame;
    const std::string videoAdresse = "rtsp://admin:123456@192.168.1.200:554/mpeg4";
    //const std::string videoAdresse = "rtsp://admin:123456@192.168.1.123:554/mpeg4";
    //const std::string videoAdresse = "rtsp://169.254.46.229:554/MediaInput/h264";
    Q_SIGNAL void started();
    Q_SLOT void start();
    Q_SLOT void stop();
    Q_SIGNAL void matReady(const cv::Mat &);
private:
    void timerEvent(QTimerEvent * ev);

};

#endif // CAPTURE_H
