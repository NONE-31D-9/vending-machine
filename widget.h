#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    int money {0};
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //void on_pb10_clicked();

private:
    void setMoney(int money);
    void buyDrink(int price);

private slots:
    void on_pb10_clicked();

    void on_pb100_clicked();

    void on_pb50_clicked();

    void on_pb500_clicked();


    void on_pbCoffee_clicked();

    void on_pbMilk_clicked();

    void on_pbTea_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
