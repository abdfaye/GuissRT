#include "ctxprovider.h"

CtxProvider::CtxProvider():
    QQuickImageProvider(QQuickImageProvider::Image)
{
    imageServer = new QTcpServer(this);
    data = new QByteArray();
    connect(imageServer, SIGNAL(newConnection()),this, SLOT(newConnection())) ;
    if(!imageServer->listen(QHostAddress::Any, 4321))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started";
    }
}

CtxProvider::~CtxProvider()
{

}

QImage CtxProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{

    QString strID = id;
    if (m_img.isNull()){
        return QImage();
    }
    QImage image = m_img;
    return image;
}

void CtxProvider::newConnection()
{
    connection = new QTcpSocket(this);
    connection = imageServer->nextPendingConnection();
    connection->write("Hello Client\r\n");
    connection->flush();
    connect(connection,SIGNAL(readyRead()),SLOT(readData()));
}

void CtxProvider::readData()
{
    //Append Data to QByteArray Buffer
    *data = *data + connection->readAll();
    //*data = connection->readAll();
    //Image Size is 19893 bytes
    //If all image data has been sent then show image
    //as QWidget Background

   // if( data->size()>8000)
    //{
        QImage image;
        image.loadFromData(*data);
        qDebug() << image.byteCount();
        if (image.byteCount() == 9216000)
        {
            setImage(image);
        }
    //}
}


void CtxProvider::setImage(const QImage & img) {
        m_img = img;
        data = new QByteArray();
        emit newImageReceive();
}
