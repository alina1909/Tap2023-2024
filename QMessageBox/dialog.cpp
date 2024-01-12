#include "dialog.h"
#include "./ui_dialog.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //info
    QMessageBox::information(this,"title","Text here");
}


void Dialog::on_pushButton_2_clicked()
{
    //question
    QMessageBox::StandardButton reply;
    reply =  QMessageBox::question(this,"title","Do you like sports?",QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        QMessageBox::information(this,"title","Good");
    }


}


void Dialog::on_pushButton_3_clicked()
{
    //warning
    QMessageBox::warning(this,"title","Exit!");
}


void Dialog::on_pushButton_4_clicked()
{
    //custom
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"title","My text here", QMessageBox::YesToAll | QMessageBox::Yes |
                                                             QMessageBox::No | QMessageBox::NoToAll);

}

