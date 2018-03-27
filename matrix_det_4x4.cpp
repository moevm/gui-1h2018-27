#include "matrix_det_4x4.h"
#include "ui_matrix_det_4x4.h"

matrix_det_4x4::matrix_det_4x4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_det_4x4)
{
    ui->setupUi(this);
}

matrix_det_4x4::~matrix_det_4x4()
{
    delete ui;
}

void matrix_det_4x4::on_pushButton_clear_clicked()
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
    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->lineEdit_12->setText("");

    ui->lineEdit_13->setText("");
    ui->lineEdit_14->setText("");
    ui->lineEdit_15->setText("");
    ui->lineEdit_16->setText("");
}
