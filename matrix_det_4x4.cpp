#include "matrix_det_4x4.h"
#include "ui_matrix_det_4x4.h"


matrix_det_4x4::matrix_det_4x4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_det_4x4)
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

void matrix_det_4x4::on_pushButton_det_4x4_clicked()
{
    //int dim = 4;

    if(ui->lineEdit_1->text().isEmpty()){ ui->lineEdit_1->setText("0"); }
    if(ui->lineEdit_2->text().isEmpty()){ ui->lineEdit_2->setText("0"); }
    if(ui->lineEdit_3->text().isEmpty()){ ui->lineEdit_3->setText("0"); }
    if(ui->lineEdit_4->text().isEmpty()){ ui->lineEdit_4->setText("0"); }

    if(ui->lineEdit_5->text().isEmpty()){ ui->lineEdit_5->setText("0"); }
    if(ui->lineEdit_6->text().isEmpty()){ ui->lineEdit_6->setText("0"); }
    if(ui->lineEdit_7->text().isEmpty()){ ui->lineEdit_7->setText("0"); }
    if(ui->lineEdit_8->text().isEmpty()){ ui->lineEdit_8->setText("0"); }

    if(ui->lineEdit_9->text().isEmpty()){ ui->lineEdit_9->setText("0"); }
    if(ui->lineEdit_10->text().isEmpty()){ ui->lineEdit_10->setText("0"); }
    if(ui->lineEdit_11->text().isEmpty()){ ui->lineEdit_11->setText("0"); }
    if(ui->lineEdit_12->text().isEmpty()){ ui->lineEdit_12->setText("0"); }

    if(ui->lineEdit_13->text().isEmpty()){ ui->lineEdit_13->setText("0"); }
    if(ui->lineEdit_14->text().isEmpty()){ ui->lineEdit_14->setText("0"); }
    if(ui->lineEdit_15->text().isEmpty()){ ui->lineEdit_15->setText("0"); }
    if(ui->lineEdit_16->text().isEmpty()){ ui->lineEdit_16->setText("0"); }

    double matrix[4][4];
    matrix[0][0] = (ui->lineEdit_1->text()).toDouble();
    matrix[0][1] = (ui->lineEdit_2->text()).toDouble();
    matrix[0][2] = (ui->lineEdit_3->text()).toDouble();
    matrix[0][3] = (ui->lineEdit_4->text()).toDouble();

    matrix[1][0] = (ui->lineEdit_5->text()).toDouble();
    matrix[1][1] = (ui->lineEdit_6->text()).toDouble();
    matrix[1][2] = (ui->lineEdit_7->text()).toDouble();
    matrix[1][3] = (ui->lineEdit_8->text()).toDouble();

    matrix[2][0] = (ui->lineEdit_9->text()).toDouble();
    matrix[2][1] = (ui->lineEdit_10->text()).toDouble();
    matrix[2][2] = (ui->lineEdit_11->text()).toDouble();
    matrix[2][3] = (ui->lineEdit_12->text()).toDouble();

    matrix[3][0] = (ui->lineEdit_13->text()).toDouble();
    matrix[3][1] = (ui->lineEdit_14->text()).toDouble();
    matrix[3][2] = (ui->lineEdit_15->text()).toDouble();
    matrix[3][3] = (ui->lineEdit_16->text()).toDouble();

}
