#include "matrix_det_3x3.h"
#include "ui_matrix_det_3x3.h"

matrix_det_3x3::matrix_det_3x3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_det_3x3)
{
    ui->setupUi(this);
}

matrix_det_3x3::~matrix_det_3x3()
{
    delete ui;
}

void matrix_det_3x3::on_pushButton_clear_clicked()
{
    ui->lineEdit_1->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");

    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");

    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");
}