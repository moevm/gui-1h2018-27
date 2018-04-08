#include "matrix_inverse_2x2.h"
#include "ui_matrix_inverse_2x2.h"

matrix_inverse_2x2::matrix_inverse_2x2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_inverse_2x2)
{
    ui->setupUi(this);

    connect(ui->pushButton_clear, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_clear_clicked()));
    connect(ui->pushButton_clear_res, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_clear_res_clicked()));

    QRegExp exp("[-]{0,1}[0-9]{1,4}[.]{0,1}[0-9]{1,5}");
    ui->lineEdit_1->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_2->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_3->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_4->setValidator(new QRegExpValidator(exp, this));
}

matrix_inverse_2x2::~matrix_inverse_2x2()
{
    delete ui;
}

void matrix_inverse_2x2::on_pushButton_clear_clicked()
{
    ui->lineEdit_1->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
}

void matrix_inverse_2x2::on_pushButton_clear_res_clicked()
{
    ui->label_inverse_2x2_res_1->setText("");
    ui->label_inverse_2x2_res_2->setText("");
    ui->label_inverse_2x2_res_3->setText("");
    ui->label_inverse_2x2_res_4->setText("");
}
