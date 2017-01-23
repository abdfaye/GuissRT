#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>


class Myserver : public QObject
{
    Q_OBJECT
     Q_PROPERTY( QString data_string READ getData WRITE setData NOTIFY dataChanged)
public:
    explicit Myserver(QObject *parent = 0);
    QTcpServer *server;
    QTcpSocket *mysocket;
    QString data;

    Q_INVOKABLE QString getData();
    Q_INVOKABLE void setData(QString pData);

signals:
    void dataChanged();


public slots:
    void newConnection();
    void readTcpData();
    void runServerTcp();
};

#endif // MYSERVER_H
