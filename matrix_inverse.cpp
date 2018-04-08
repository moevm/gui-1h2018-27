#include "matrix_inverse.h"
#include "ui_matrix_inverse.h"
#include "matrix_inverse_2x2.h"
#include "matrix_inverse_3x3.h"
#include "matrix_inverse_4x4.h"
#include "matrix_inverse_5x5.h"

matrix_inverse::matrix_inverse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_inverse)
{
    ui->setupUi(this);


}

matrix_inverse::~matrix_inverse()
{
    delete ui;
}

void matrix_inverse::on_pushButton_clicked()
{
    QString dim = ui->comboBox_matrix_inverse->currentText();
    if(dim == "2x2")
    {
        matrix_inverse_2x2 *matrix_2x2 = new matrix_inverse_2x2;
        matrix_2x2->show();

    } else if(dim == "3x3")
    {
        matrix_inverse_3x3 *matrix_3x3 = new matrix_inverse_3x3;
        matrix_3x3->show();

    } else if(dim == "4x4")
    {
        matrix_inverse_4x4 *matrix_4x4 = new matrix_inverse_4x4;
        matrix_4x4->show();

    } else if(dim == "5x5")
    {
        matrix_inverse_5x5 *matrix_5x5 = new matrix_inverse_5x5;
        matrix_5x5->show();
    }
}
