#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class QUdpSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_connect_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket *mSocket;
    QString username;
};

#endif // WIDGET_H
