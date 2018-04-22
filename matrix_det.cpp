#include "matrix_det.h"
#include "ui_matrix_det.h"
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QWidget>
#include "matrix_det_2x2.h"
#include "matrix_det_3x3.h"
#include "matrix_det_4x4.h"
#include "matrix_det_5x5.h"

matrix_det::matrix_det(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_det)
{
    ui->setupUi(this);
}

matrix_det::~matrix_det()
{
    delete ui;
}


void matrix_det::on_pushButton_clicked()
{
    QString dim = ui->comboBox_matrix_det->currentText();
    if(dim == "2x2")
    {
        matrix_det_2x2 *matrix_2x2 = new matrix_det_2x2;
        matrix_2x2->show();

    } else if(dim == "3x3")
    {
        matrix_det_3x3 *matrix_3x3 = new matrix_det_3x3;
        matrix_3x3->show();

    } else if(dim == "4x4")
    {
        matrix_det_4x4 *matrix_4x4 = new matrix_det_4x4;
        matrix_4x4->show();

    } else if(dim == "5x5")
    {
        matrix_det_5x5 *matrix_5x5 = new matrix_det_5x5;
        matrix_5x5->show();
    }
}

void matrix_det::on_pushButton_2_clicked()
{
    close();
}
