#include "myserver.h"

Myserver::Myserver(QObject *parent) : QObject(parent)
{
     server  =  new QTcpServer(this);
     connect(server, SIGNAL(newConnection()),this, SLOT(newConnection())) ;
}

void Myserver::runServerTcp()
{
    if(!server->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started";
    }
}


void Myserver::newConnection()
{
    mysocket = new QTcpSocket(this);
    mysocket = server->nextPendingConnection();
    mysocket->write("Hello Client\r\n");
    mysocket->flush();
    connect( mysocket, SIGNAL(readyRead()), SLOT(readTcpData()) );
}

QString Myserver::getData()  {
        return data ;
}

void Myserver::setData(QString pData)  {
        data = pData;
        emit dataChanged();
}


void Myserver::readTcpData()
{
    QByteArray pData = mysocket->readAll();
    QString dataR = QVariant(pData).toString();
    setData(dataR);
    qDebug() << "Server=>" + dataR;
}


