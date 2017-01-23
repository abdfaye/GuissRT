#ifndef CTXSENDER_H
#define CTXSENDER_H

#include <QObject>
#include<QTcpSocket>
#include<QImageWriter>
#include <QImage>
#include<QDebug>

class CtxSender : public QObject
{
    Q_OBJECT
public:
    explicit CtxSender(QObject *parent = 0);
    QImage image;
    QTcpSocket * imagesocket;
    bool isConnected = false;

signals:
    void imageChange();

public slots:
    void sendData();
    void readTcpData();
    void setData();
    void connectTcp();
    void setBool();
};

#endif // CTXSENDER_H
