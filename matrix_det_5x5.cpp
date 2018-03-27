#include "matrix_det_5x5.h"
#include "ui_matrix_det_5x5.h"

matrix_det_5x5::matrix_det_5x5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_det_5x5)
{
    ui->setupUi(this);
}

matrix_det_5x5::~matrix_det_5x5()
{
    delete ui;
}

void matrix_det_5x5::on_pushButton_clear_clicked()
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
     ui->lineEdit_17->setText("");
     ui->lineEdit_18->setText("");
     ui->lineEdit_19->setText("");
     ui->lineEdit_20->setText("");

     ui->lineEdit_21->setText("");
     ui->lineEdit_22->setText("");
     ui->lineEdit_23->setText("");
     ui->lineEdit_24->setText("");
     ui->lineEdit_25->setText("");

}
