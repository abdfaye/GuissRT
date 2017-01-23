#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>
#include <QBasicTimer>
#include <QDateTime>
#include <QThread>
#include <QImage>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

class Converter : public QObject
{
    Q_OBJECT
    static void matDeleter(void* mat);
    void queue(const cv::Mat & frame);
    void process(cv::Mat frame);
    void timerEvent(QTimerEvent * ev);
public:
    explicit Converter(QObject * parent = 0);
    QBasicTimer m_timer;
    cv::VideoWriter m_videoWriter;
    cv::Mat m_frame;
    bool m_processAll;
    bool m_record = 0;
    void setProcessAll(bool all);
    Q_SIGNAL void imageReady(const QImage &);
    Q_SIGNAL void startRecord();
    Q_SIGNAL void stopRecord();
    Q_SLOT void initRecord();
    Q_SLOT void endRecord();
    Q_SLOT void processFrame(const cv::Mat & frame);
};

#endif // CONVERTER_H
