#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);
    connect (mSocket, &QUdpSocket::readyRead, [&] () {
        if (mSocket->hasPendingDatagrams()) {
        QByteArray datagramma;
        datagramma.resize(mSocket->pendingDatagramSize());
        mSocket->readDatagram(datagramma.data(), datagramma.size());
        ui->listWidget->addItem(QString(datagramma));
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_connect_clicked()
{
    mSocket->bind(ui->port->value(), QUdpSocket::ShareAddress);
}
