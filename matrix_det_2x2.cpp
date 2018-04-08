#include "matrix_det_2x2.h"
#include "ui_matrix_det_2x2.h"
#include <QMessageBox>
//#include <iostream>
//#include <QString>
//#include <QTextStream>
//QTextStream cout(stdout);
//QTextStream cin(stdin);

matrix_det_2x2::matrix_det_2x2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_det_2x2)
{
    ui->setupUi(this);

    QRegExp exp("[-]{0,1}[0-9]{1,4}[.]{0,1}[0-9]{1,5}");
    ui->lineEdit_1->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_2->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_3->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_4->setValidator(new QRegExpValidator(exp, this));
}

matrix_det_2x2::~matrix_det_2x2()
{
    delete ui;
}

void matrix_det_2x2::on_pushButton_clear_clicked()
{
    ui->lineEdit_1->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
}

void matrix_det_2x2::on_pushButton_det_2x2_clicked()
{
    //int dim = 2;

    if(ui->lineEdit_1->text().isEmpty()){ ui->lineEdit_1->setText("0"); }
    if(ui->lineEdit_2->text().isEmpty()){ ui->lineEdit_2->setText("0"); }
    if(ui->lineEdit_3->text().isEmpty()){ ui->lineEdit_3->setText("0"); }
    if(ui->lineEdit_4->text().isEmpty()){ ui->lineEdit_4->setText("0"); }


    double matrix[2][2];

    matrix[0][0] = (ui->lineEdit_1->text()).toDouble();
    matrix[0][1] = (ui->lineEdit_2->text()).toDouble();
    matrix[1][0] = (ui->lineEdit_3->text()).toDouble();
    matrix[1][1] = (ui->lineEdit_4->text()).toDouble();

}
