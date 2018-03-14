#include "integral.h"
#include "ui_integral.h"
#include "mainwindow.h"
#include <QMessageBox>

integral::integral(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::integral)
{
    ui->setupUi(this);

    //numbers
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(write_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(write_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(write_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(write_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(write_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(write_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(write_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(write_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(write_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(write_numbers()));

    //clear
    connect(ui->pushButton_clear_res, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_clear_res_clicked));
    connect(ui->pushButton_clear, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_clear_clicked(bool)));

    //math_functions
    connect(ui->pushButton_sin, SIGNAL(clicked(bool)), this, SLOT(write_basic_math_func()));
    connect(ui->pushButton_cos, SIGNAL(clicked(bool)), this, SLOT(write_basic_math_func()));
    connect(ui->pushButton_tan, SIGNAL(clicked(bool)), this, SLOT(write_basic_math_func()));
    connect(ui->pushButton_asin, SIGNAL(clicked(bool)), this, SLOT(write_basic_math_func()));
    connect(ui->pushButton_acos, SIGNAL(clicked(bool)), this, SLOT(write_basic_math_func()));
    connect(ui->pushButton_atan, SIGNAL(clicked(bool)), this, SLOT(write_basic_math_func()));
    connect(ui->pushButton_log, SIGNAL(clicked(bool)), this, SLOT(write_basic_math_func()));
    connect(ui->pushButton_exp, SIGNAL(clicked(bool)), this, SLOT(write_basic_math_func()));
    connect(ui->pushButton_abs, SIGNAL(clicked(bool)), this, SLOT(write_basic_math_func()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked(bool)), this, SLOT(write_basic_math_func()));

    //operations
    connect(ui->pushButton_left_bracket, SIGNAL(clicked(bool)), this, SLOT(write_operations()));
    connect(ui->pushButton_right_bracket, SIGNAL(clicked(bool)), this, SLOT(write_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked(bool)), this, SLOT(write_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked(bool)), this, SLOT(write_operations()));
    connect(ui->pushButton_deg, SIGNAL(clicked(bool)), this, SLOT(write_operations()));
    connect(ui->pushButton_devide, SIGNAL(clicked(bool)), this, SLOT(write_operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked(bool)), this, SLOT(write_operations()));
    connect(ui->pushButton_dot, SIGNAL(clicked(bool)), this, SLOT(write_operations()));

    //variable
    connect(ui->pushButton_variable, SIGNAL(clicked(bool)), this, SLOT(write_operations()));

    connect(ui->pushButton_calculate, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_calculate_clicked()));
}

integral::~integral()
{
    delete ui;
}

void integral::write_numbers()
{
    QPushButton *button = (QPushButton *)sender();//возвращает кнопку, на которую было произведено нажатие
    //теперь каким-то образом будет все зашибись
    double all_numbers;
    QString new_label;

    all_numbers = (ui->write_integral->text()+button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 30);//конвертация из типа double в строку, чтобы вывести в результат
                                            //30 - количество чиселок, которых можно ввести
    ui->write_integral->setText(new_label);
}

void integral::on_pushButton_clear_clicked()
{
    ui->write_integral->setText(" ");
}

void integral::on_pushButton_help_clicked()
{
    QMessageBox::information(this, "Справка", "Ну, серьезно, так как справкой пользуются единицы, поэтому появится только после обновления приложения!");
}

void integral::on_pushButton_clear_res_clicked()
{
    ui->label_res->setText("");
}

void integral::write_basic_math_func()
{
    QPushButton *button = (QPushButton *)sender();//возвращает кнопку, на которую было произведено нажатие
    //теперь каким-то образом будет все зашибись
    QString new_label;
    QString left_bracket = "(";
    new_label = ui->write_integral->text() + button->text();
    new_label = new_label + left_bracket;
    ui->write_integral->setText(new_label);
}

void integral::write_operations()
{
    QPushButton *button = (QPushButton *)sender();//возвращает кнопку, на которую было произведено нажатие
    //теперь каким-то образом будет все зашибись
    QString new_label;
    new_label = ui->write_integral->text() + button->text();
    ui->write_integral->setText(new_label);
}


void integral::on_pushButton_calculate_clicked()
{
    QString res_label;
    res_label = ui->write_integral->text();
    ui->label_res->setText(res_label);
}
