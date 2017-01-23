#ifndef SERVOCLIENT_H
#define SERVOCLIENT_H

#include <QObject>
#include <QTcpSocket>

class Servoclient : public QObject
{
    Q_OBJECT
public:
    explicit Servoclient(QObject *parent = 0);
    QByteArray data;
    QTcpSocket * servosocket;
    bool isConnected = false;

signals:
    void dataChange();

public slots:
    void sendData();
    void readTcpData();
    void setData(QByteArray carac);
    void connectTcp();
    void setBool();

};

#endif // SERVOCLIENT_H
