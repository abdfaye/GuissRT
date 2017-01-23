#include "imageprovider.h"


ImageProvider::ImageProvider() :
    QQuickImageProvider(QQuickImageProvider::Image)
{
}

ImageProvider::~ImageProvider()
{
}

QImage ImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{

    QString strID = id;
    if (m_img.isNull()){
           return QImage();
    }
    QImage image = m_img;
   // image = image.scaled(1200, 1920, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    return image;
}

void ImageProvider::setImage(const QImage & img) {
        if (!m_img.isNull()) qDebug() << "Viewer dropped frame!";
        m_img = img;

        emit newImageReceive();
}
