#ifndef CTXPROVIDER_H
#define CTXPROVIDER_H

#include <QQuickImageProvider>
#include <QImage>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

class CtxProvider : public QObject, public QQuickImageProvider
{
    Q_OBJECT
public:
    //explicit CtxProvider(QObject *parent = 0);
    CtxProvider();
    ~CtxProvider();
    QImage m_img;
    QTcpSocket* connection;
    QByteArray* data;
    QTcpServer* imageServer;
    virtual QImage requestImage(const QString & id, QSize * size, const QSize & requestedSize);

signals:
    void newImageReceive();

public slots:
        void newConnection();
        void setImage(const QImage & img);
        void readData();
};

#endif // CTXPROVIDER_H
