#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QWidget>
#include <QBasicTimer>
#include <QThread>
#include <QImage>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <opencv2/opencv.hpp>


class ImageViewer : public QWidget
{
    Q_OBJECT

    void paintEvent(QPaintEvent *);
public:
    QImage m_img;
    ImageViewer(QWidget * parent = 0);
    Q_SLOT void setImage(const QImage & img);
};


#endif // IMAGEVIEWER_H
