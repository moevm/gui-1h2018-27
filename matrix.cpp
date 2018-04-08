#include "matrix.h"
#include "ui_matrix.h"
#include "matrix_det.h"
#include "matrix_inverse.h"

matrix::matrix(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix)
{
    ui->setupUi(this);
}

matrix::~matrix()
{
    delete ui;
}

void matrix::on_pushButton_matrix_det_clicked()
{
    matrix_det *new_matrix_det = new matrix_det(this);
    new_matrix_det->show();
}

void matrix::on_pushButton_clicked()
{
    close();
}

void matrix::on_pushButton_2_clicked()
{
    matrix_inverse *new_matrix_inverse = new matrix_inverse(this);
    new_matrix_inverse->show();
}
