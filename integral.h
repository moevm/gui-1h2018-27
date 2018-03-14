#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPixmap>

namespace Ui {
    class integral;
}

class integral : public QDialog
{
    Q_OBJECT

public:
    explicit integral(QWidget *parent = 0);
    ~integral();

private:
    Ui::integral *ui;

private slots:
    void write_numbers();
    //void write_symbols();
    void on_pushButton_clear_clicked();
    void on_pushButton_help_clicked();
    void on_pushButton_clear_res_clicked();
    void write_basic_math_func();
    void write_operations();

    void on_pushButton_calculate_clicked();
};

#endif // INTEGRAL_H
