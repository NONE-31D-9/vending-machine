#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::setMoney(int money){
    this->money += money;
    ui->lcdNumber->display(this->money);
    if(this->money >= 100) ui->pbCoffee->setEnabled(true);
    if(this->money >= 150) ui->pbTea->setEnabled(true);
    if(this->money >= 200) ui->pbMilk->setEnabled(true);
}

void Widget::buyDrink(int price){

    if(this->money - price < 0) return;
    this->money -= price;
    ui->lcdNumber->display(this->money);
    if(this->money < 100) ui->pbCoffee->setEnabled(false);
    if(this->money < 150) ui->pbTea->setEnabled(false);
    if(this->money < 200) ui->pbMilk->setEnabled(false);
}


void Widget::on_pb10_clicked()
{
    setMoney(10);
}

void Widget::on_pb100_clicked()
{
    setMoney(100);
}

void Widget::on_pb50_clicked()
{
    setMoney(50);
}

void Widget::on_pb500_clicked()
{
    setMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
   buyDrink(100);
}

void Widget::on_pbMilk_clicked()
{
    buyDrink(200);
}

void Widget::on_pbTea_clicked()
{
    buyDrink(150);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msgBox;
    msgBox.setText(QString("Your change is %1").arg(money));
    msgBox.exec();

    this->money = 0;
    ui->lcdNumber->display(this->money);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}
