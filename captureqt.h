#ifndef CAPTUREQT_H
#define CAPTUREQT_H

#include <QObject>
#include <QAbstractVideoSurface>
#include <QList>
#include <QImage>
#include <QDebug>
#include <opencv2/opencv.hpp>

class CaptureQT : public QAbstractVideoSurface
{
    Q_OBJECT
public:
    explicit CaptureQT(QObject *parent = 0);

    QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const;

    bool present(const QVideoFrame &frame);

signals:
    void frameAvailable(const cv::Mat &);
    void frameAvailable(QImage frame);

public slots:

};

#endif // CAPTUREQT_H
