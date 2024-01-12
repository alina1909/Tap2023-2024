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
    if(ui->radioButton1->isChecked())
    {
        QMessageBox::information(this,"Language",ui->radioButton1->text());
    }

    if(ui->radioButton2->isChecked())
    {
        QMessageBox::information(this,"Language",ui->radioButton2->text());
    }
}

