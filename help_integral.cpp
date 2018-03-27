#include "help_integral.h"
#include "ui_help_integral.h"

help_integral::help_integral(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help_integral)
{
    ui->setupUi(this);
}

help_integral::~help_integral()
{
    delete ui;
}
