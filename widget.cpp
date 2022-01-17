#include "widget.h"
#include "ui_widget.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mServer = new QTcpServer(this);
    mSocket = nullptr;

    connect(mServer, &QTcpServer::newConnection,[&](){
       mSocket = mServer->nextPendingConnection();
               ui->estado->setText("Estado: Conectado");
    });
    mServer->listen(QHostAddress::Any,3333);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_enviar_clicked()
{
    if (mSocket == nullptr){
        return;
    }
    QTextStream T(mSocket);
    T << ui->texto->text();
    mSocket->flush();
}
