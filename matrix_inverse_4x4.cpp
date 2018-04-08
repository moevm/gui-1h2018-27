#include "matrix_inverse_4x4.h"
#include "ui_matrix_inverse_4x4.h"

matrix_inverse_4x4::matrix_inverse_4x4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_inverse_4x4)
{
    ui->setupUi(this);

    QRegExp exp("[-]{0,1}[0-9]{1,4}[.]{0,1}[0-9]{1,5}");
    ui->lineEdit_1->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_2->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_3->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_4->setValidator(new QRegExpValidator(exp, this));

    ui->lineEdit_5->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_6->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_7->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_8->setValidator(new QRegExpValidator(exp, this));

    ui->lineEdit_9->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_10->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_11->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_12->setValidator(new QRegExpValidator(exp, this));

    ui->lineEdit_13->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_14->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_15->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_16->setValidator(new QRegExpValidator(exp, this));
}

matrix_inverse_4x4::~matrix_inverse_4x4()
{
    delete ui;
}

void matrix_inverse_4x4::on_pushButton_clear_clicked()
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

void matrix_inverse_4x4::on_pushButton_clear_res_clicked()
{
    ui->label_inverse_4x4_res_1->setText("");
    ui->label_inverse_4x4_res_2->setText("");
    ui->label_inverse_4x4_res_3->setText("");
    ui->label_inverse_4x4_res_4->setText("");

    ui->label_inverse_4x4_res_5->setText("");
    ui->label_inverse_4x4_res_6->setText("");
    ui->label_inverse_4x4_res_7->setText("");
    ui->label_inverse_4x4_res_8->setText("");

    ui->label_inverse_4x4_res_9->setText("");
    ui->label_inverse_4x4_res_10->setText("");
    ui->label_inverse_4x4_res_11->setText("");
    ui->label_inverse_4x4_res_12->setText("");

    ui->label_inverse_4x4_res_13->setText("");
    ui->label_inverse_4x4_res_14->setText("");
    ui->label_inverse_4x4_res_15->setText("");
    ui->label_inverse_4x4_res_16->setText("");
}
