#include "matrix_inverse_5x5.h"
#include "ui_matrix_inverse_5x5.h"

matrix_inverse_5x5::matrix_inverse_5x5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_inverse_5x5)
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
    ui->lineEdit_17->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_18->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_19->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_20->setValidator(new QRegExpValidator(exp, this));

    ui->lineEdit_21->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_22->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_23->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_24->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_25->setValidator(new QRegExpValidator(exp, this));
}

matrix_inverse_5x5::~matrix_inverse_5x5()
{
    delete ui;
}

void matrix_inverse_5x5::on_pushButton_clear_clicked()
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

void matrix_inverse_5x5::on_pushButton_clear_res_clicked()
{
    ui->label_inverse_5x5_res_1->setText("");
    ui->label_inverse_5x5_res_2->setText("");
    ui->label_inverse_5x5_res_3->setText("");
    ui->label_inverse_5x5_res_4->setText("");
    ui->label_inverse_5x5_res_5->setText("");

    ui->label_inverse_5x5_res_6->setText("");
    ui->label_inverse_5x5_res_7->setText("");
    ui->label_inverse_5x5_res_8->setText("");
    ui->label_inverse_5x5_res_9->setText("");
    ui->label_inverse_5x5_res_10->setText("");

    ui->label_inverse_5x5_res_11->setText("");
    ui->label_inverse_5x5_res_12->setText("");
    ui->label_inverse_5x5_res_13->setText("");
    ui->label_inverse_5x5_res_14->setText("");
    ui->label_inverse_5x5_res_15->setText("");

    ui->label_inverse_5x5_res_16->setText("");
    ui->label_inverse_5x5_res_17->setText("");
    ui->label_inverse_5x5_res_18->setText("");
    ui->label_inverse_5x5_res_19->setText("");
    ui->label_inverse_5x5_res_20->setText("");

    ui->label_inverse_5x5_res_21->setText("");
    ui->label_inverse_5x5_res_22->setText("");
    ui->label_inverse_5x5_res_23->setText("");
    ui->label_inverse_5x5_res_24->setText("");
    ui->label_inverse_5x5_res_25->setText("");
}
