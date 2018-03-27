#ifndef HELP_INTEGRAL_H
#define HELP_INTEGRAL_H

#include <QDialog>

namespace Ui {
class help_integral;
}

class help_integral : public QDialog
{
    Q_OBJECT

public:
    explicit help_integral(QWidget *parent = 0);
    ~help_integral();

private:
    Ui::help_integral *ui;
};

#endif // HELP_INTEGRAL_H
