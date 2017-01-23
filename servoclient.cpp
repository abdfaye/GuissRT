#include "servoclient.h"

Servoclient::Servoclient(QObject *parent) :
    QObject(parent)
{
    connect(this, SIGNAL(dataChange()), SLOT(sendData()));
}

void Servoclient::connectTcp()
{
    if(isConnected == false ){
        servosocket = new QTcpSocket( this );
        connect( servosocket, SIGNAL(readyRead()), SLOT(readTcpData()) );
        connect( servosocket, SIGNAL(connected()), SLOT(setBool()) );

        servosocket->connectToHost("192.168.1.110", 1234);
        servosocket->waitForConnected();
    }
}

void Servoclient::setData(QByteArray carac){
    data = carac;
    emit dataChange();
}

void Servoclient::setBool(){
    isConnected = true;
}


void Servoclient::sendData(){
    if(isConnected == true ) {
        servosocket->write( data );
    }
    else{
        qDebug() << "NOT CONNECTED";
    }
}


void Servoclient::readTcpData()
{
    qDebug() << "Client =>" + servosocket->readAll();
}
