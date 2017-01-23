#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QImage>
#include <QObject>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <opencv2/opencv.hpp>

class ImageProvider : public QObject,public QQuickImageProvider
{
Q_OBJECT
public:
    //explicit ImageProvider(QObject * parent = 0);
    ImageProvider();
    ~ImageProvider();
    QImage m_img;
    virtual QImage requestImage(const QString & id, QSize * size, const QSize & requestedSize);
    Q_SLOT void setImage(const QImage & img);
    Q_SIGNAL void newImageReceive();

};

#endif // IMAGEPROVIDER_H
