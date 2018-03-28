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
    bool is_number(char a);
    bool correctcont(char a);
    double value_at_a_point(std::string string, int& counter, double x, int& brct, bool& error);
    double degree(std::string string, int& counter, double x, int& brct, bool& error);
    double multiplication(std::string string, int& counter, double x, int& brct, bool& error);
    double Integral(std::string string, double a, double b);


private:
    Ui::integral *ui;

private slots:
    void on_pushButton_clear_clicked();
    void on_pushButton_help_clicked();
    void on_pushButton_clear_res_clicked();
    void on_pushButton_calculate_clicked();
    void on_pushButton_clear_limits_clicked();
    void on_write_integral_textChanged(const QString &arg1);
};

#endif // INTEGRAL_H
