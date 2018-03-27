#include "matrix_det_2x2.h"
#include "ui_matrix_det_2x2.h"

matrix_det_2x2::matrix_det_2x2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_det_2x2)
{
    ui->setupUi(this);
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
