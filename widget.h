#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
class QTcpServer;
class QTcpSocket;
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_enviar_clicked();

private:
    Ui::Widget *ui;
    QTcpServer *mServer;
    QTcpSocket *mSocket;
};
#endif // WIDGET_H
