#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QUdpSocket(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_send_clicked()
{
    auto datagrama = ui->msj->text().toUtf8();
    mSocket->writeDatagram(datagrama, QHostAddress::Broadcast,
                           ui->port->value());
}
