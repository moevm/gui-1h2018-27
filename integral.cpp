#include "integral.h"
#include "ui_integral.h"
#include "mainwindow.h"
#include "help_integral.h"
#include <QMessageBox>

integral::integral(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::integral)
{
    ui->setupUi(this);
    ui->pushButton_calculate->setDefault(true);//принажатии кнопки enter, будет нажиматься ok
    ui->pushButton_calculate->setEnabled(false);//делаем кнопку пока недоступной
    //clear
    connect(ui->pushButton_clear_res, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_clear_res_clicked));
    connect(ui->pushButton_clear, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_clear_clicked(bool)));
    connect(ui->pushButton_calculate, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_calculate_clicked()));

    QRegExp exp("[-]{0,1}[0-9]{1,9}[.]{0,1}[0-9]{1,6}");
    ui->lineEdit_a->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_b->setValidator(new QRegExpValidator(exp, this));

}

integral::~integral()
{
    delete ui;
}

void integral::on_write_integral_textChanged(const QString &arg1)
{
    ui->pushButton_calculate->setEnabled(!arg1.isEmpty());//если строка не пустая
}

void integral::on_pushButton_calculate_clicked()
{
    QString str = ui->write_integral->text();
    std::string strr = str.toUtf8().constData();

    double a = (ui->lineEdit_a->text()).toDouble();
    double b = (ui->lineEdit_b->text()).toDouble();

    double res = Integral(strr, a, b);

    QString new_res = QString::number(res);
    ui->label_res->setText(new_res);

}

void integral::on_pushButton_clear_clicked()
{
    ui->write_integral->setText("");
}

void integral::on_pushButton_help_clicked()
{
      help_integral *new_help_integral = new help_integral(this);
      new_help_integral->show();
}

void integral::on_pushButton_clear_res_clicked()
{
    ui->label_res->setText("");
}

void integral::on_pushButton_clear_limits_clicked()
{
    ui->lineEdit_a->setText("");
    ui->lineEdit_b->setText("");
}




bool integral::is_number(char a){
    if ((a == '0') || (a == '1') || (a == '2') || (a == '3') || (a == '4') || (a == '5') || (a == '6') || (a == '7') || (a == '8') || (a == '9')){
        return true;
    }
    else{
        return false;
    }
}

bool integral::correctcont(char a){
    if (is_number(a) || a == 'x' || a == '(' || a == 's' || a == 'c' || a == 't' || a == 'a' || a == 'l' || a == 'e') return true;
    else return false;
}

double integral::value_at_a_point(std::string string, int& counter, double x, int& brct, bool& error){
    double res = 0;

    while (counter < string.length()){ // !!!

        if ((string[counter] >= '0') && (string[counter] <= '9')){
            bool pointchecker = false;
            int subcounter = counter; // ñ÷åò÷èê äëÿ ñ÷èòûâàíèÿ ÷èñëà
            while (((string[counter] >= '0') && (string[counter] <= '9')) || (string[counter] == '.')){ // !!!!

                if ((string[counter] == '.') && pointchecker){
                    error = true;
                    return 0;
                }
                if (string[counter] == '.') pointchecker = true;
                counter++;
            }
            res = stod(string.substr(subcounter, counter+1)); // ïàðñèì ÷èñëî â äàáë !!!
        }

        if (string[counter] == '+'){
            ++counter;
            if (correctcont(string[counter]))  res = res + value_at_a_point(string, counter, x, brct, error);
            else {
                error = true;
                return 0;
            }
        }

        if (string[counter] == '-'){
            ++counter;
            if (correctcont(string[counter]))  res = res - value_at_a_point(string, counter, x, brct, error);
            else {
                error = true;
                return 0;
            }
        }

        if (string[counter] == '*'){
            ++counter;
            if (correctcont(string[counter])) { res = res * multiplication(string, counter, x, brct, error); }
            else {
                error = true;
                return 0;
            }
        }

        if (string[counter] == '/'){
            ++counter;
            if (correctcont(string[counter])) res = res / multiplication(string, counter, x, brct, error);
            else {
                error = true;
                return 0;
            }
        }

        if (string[counter] == '^'){
            ++counter;
            if (correctcont(string[counter]))  res = pow(res, degree(string, counter, x, brct, error));
            else {
                error = true;
                return 0;
            }
        }

        if (string[counter] == '('){
            counter++; // âîçìîæíî ïîòîì äîáàâèòü ñ÷åò÷èê  ñêîáîê
            ++brct;
        }

        if (string[counter] == ')'){
            if (brct <= 0) {
                error = true;
                return 0;
            }
            ++counter;
            if (counter == string.length()){
                --brct;
                return res;
            }
            else{
                if (string[counter] == '+' || string[counter] == '-' || string[counter] == '*' || string[counter] == '/' || string[counter] == '^'){
                    --brct;
                    return res;
                }
                else{
                    error = true;
                    return 0;
                }
            }
        }

        if (string[counter] == 's'){
            ++counter;
            if (string[counter] == 'q'){
                if ((string[counter + 1] == 'r') && (string[counter + 2] == 't') && (string[counter + 3]) == '('){
                    counter = counter + 3;
                    res = sqrt(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true;
                    return 0;
                }
            }
            if (string[counter] == 'i'){
                if ((string[counter + 1] == 'n') && (string[counter + 2] == '(')){
                    counter = counter + 2;
                    res = sin(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true;
                    return 0;
                }
            }

        }

        if (string[counter] == 'c'){
            if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
                counter = counter + 3;
                res = cos(value_at_a_point(string, counter, x, brct, error));
            }
            else{
                error = true; return 0;
            }
        }

        if (string[counter] == 't'){
            if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
                counter = counter + 3;
                res = tan(value_at_a_point(string, counter, x, brct, error));
            }
            else{
                error = true; return 0;
            }
        }

        if (string[counter] == 'l'){
            if ((string[counter + 1] == 'o') && (string[counter + 2] == 'g') && (string[counter + 3] == '(')){
                counter = counter + 3;
                res = log(value_at_a_point(string, counter, x, brct, error));
            }
            else{
                error = true; return 0;
            }
        }

        if (string[counter] == 'e'){
            if ((string[counter + 1] == 'x') && (string[counter + 2] == 'p') && (string[counter + 3] == '(')){
                counter = counter + 3;
                res = exp(value_at_a_point(string, counter, x, brct, error));
            }
            else{
                error = true; return 0;
            }
        }

        if (string[counter] == 'a'){
            ++counter;
            if (string[counter] == 's'){
                if ((string[counter + 1] == 'i') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
                    counter = counter + 3;
                    res = asin(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }
            if (string[counter] == 'c'){
                if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
                    counter = counter + 3;
                    res = acos(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }
            if (string[counter] == 't'){
                if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
                    counter = counter + 3;
                    res = atan(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }
            if (string[counter] == 'b'){
                if ((string[counter + 1] == 's') && (string[counter + 2] == '(')){
                    counter = counter + 2;
                    res = abs(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }
        }
        if (string[counter] == 'x'){
            res = x;
            counter++;
        }

        if (string[counter] == '.'){
            error = true;
            return 0;
        }
    }
    return res;
}

double integral::Integral(std::string string, double a, double b){
    bool error = false;
    double res = 0;
    int counter = 0;
    int brct = 0;
    double help1, help2, help3;
    const int n = 10000; // êîëè÷åñòâî òî÷åê. Âëèÿåò íà ñêîðîñòü ðàáîòû.
    double x[n+1] = { 0 };
    x[0] = a;
    double h = (b - a) / n;
    for (int i = 1; i < n+1 ; ++i){
        x[i] = x[i - 1] + h;
    }
    for (int k = 1; k < n; k = k + 2){
        counter = 0;
        brct = 0;
        help1 = value_at_a_point(string, counter, x[k - 1], brct, error);
        if (error)
        {
            return QMessageBox::warning(this, "Error!", "Введите корректную функцию! Пример: sin(x)*x.");
            //return -1000; // error
        }
        counter = 0;
        brct = 0;
        help2 = value_at_a_point(string, counter, x[k], brct, error);
        counter = 0;
        brct = 0;
        help3 = value_at_a_point(string, counter, x[k + 1], brct, error);
        res = res + help1 + 4 * help2 + help3;
    }
    res = res * h / 3;
    return res;
}

double integral::multiplication(std::string string, int& counter, double x, int& brct, bool& error){
    double res = 0;
    bool pointchecker = false;
    bool mmarker = false;
    int subcounter = counter; // óêàçàòåëü íà êîíå÷ ÷èñëà

    while (counter < string.length()){

        if ((string[counter] >= '0') && (string[counter] <= '9')){
            bool pointchecker = false;
            int subcounter = counter; // ñ÷åò÷èê äëÿ ñ÷èòûâàíèÿ ÷èñëà
            if (mmarker) subcounter--; // -
            while (((string[counter] >= '0') && (string[counter] <= '9')) || (string[counter] == '.')){ // !!!!

                if ((string[counter] == '.') && pointchecker){
                    error = true; return 0;
                }
                if (string[counter] == '.') pointchecker = true;
                counter++;
            }
            res = stod(string.substr(subcounter, counter+1)); // ïàðñèì ÷èñëî â äàáë !!!
        }

        if (string[counter] == '+'){
            if (brct != 0){
                ++counter;
                if (correctcont(string[counter])) res = res + value_at_a_point(string, counter, x, brct, error);
                else {
                    error = true; return 0;
                }
            }
            else return res;
        }

        if (string[counter] == '-'){
            if (brct != 0){
                ++counter;
                if (correctcont(string[counter])) res = res - value_at_a_point(string, counter, x, brct, error);
                else {
                    error = true; return 0;
                }
            }
            else return res;
        }

        if (string[counter] == '*'){
            ++counter;
            if (correctcont(string[counter])) res = res * multiplication(string, counter, x, brct, error);
            else {
                error = true; return 0;
            }
        }

        if (string[counter] == '/'){
            ++counter;
            if (correctcont(string[counter])) res = res / multiplication(string, counter, x, brct, error);
            else {
                error = true; return 0;
            }
        }

        if (string[counter] == '^'){
            ++counter;
            if (correctcont(string[counter])) res = pow(res, degree(string, counter, x, brct, error));
            else {
                error = true; return 0;
            }
        }

        if (string[counter] == '('){
            ++counter; // âîçìîæíî ïîòîì äîáàâèòü ñ÷åò÷èê  ñêîáîê
            ++brct;
            if ((string[counter] == '-') && is_number(string[counter + 1])){
                mmarker = true;
            }
        }

        if (string[counter] == ')'){
            if (brct <= 0) {
                error = true;
                return 0;
            }
            ++counter;
            if (counter == string.length()){
                --brct;
                return res;
            }
            else{
                if (string[counter] == '+' || string[counter] == '-' || string[counter] == '*' || string[counter] == '/' || string[counter] == '^'){
                    --brct;
                    return res;
                }
                else{
                    error = true;
                    return 0;
                }
            }
        }

        if (string[counter] == 's'){
            ++counter;
            if (string[counter] == 'q'){
                if ((string[counter + 1] == 'r') && (string[counter + 2] == 't') && (string[counter + 3]) == '('){
                    counter = counter + 3;
                    res = sqrt(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }
            if (string[counter] == 'i'){
                if ((string[counter + 1] == 'n') && (string[counter + 2] == '(')){
                    counter = counter + 2;
                    res = sin(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }
        }

        if (string[counter] == 'c'){
            if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
                counter = counter + 3;
                res = cos(value_at_a_point(string, counter, x, brct, error));
            }
            else{
                error = true; return 0;
            }
        }

        if (string[counter] == 't'){
            if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
                counter = counter + 3;
                res = tan(value_at_a_point(string, counter, x, brct, error));
            }
            else{
                error = true; return 0;
            }
        }

        if (string[counter] == 'l'){
            if ((string[counter + 1] == 'o') && (string[counter + 2] == 'g') && (string[counter + 3] == '(')){
                counter = counter + 3;
                res = log(value_at_a_point(string, counter, x, brct, error));
            }
            else{
                error = true; return 0;
            }
        }

        if (string[counter] == 'e'){
            if ((string[counter + 1] == 'x') && (string[counter + 2] == 'p') && (string[counter + 3] == '(')){
                counter = counter + 3;
                res = exp(value_at_a_point(string, counter, x, brct, error));
            }
            else{
                error = true; return 0;
            }
        }

        if (string[counter] == 'a'){
            ++counter;
            if (string[counter] == 's'){
                if ((string[counter + 1] == 'i') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
                    counter = counter + 3;
                    res = asin(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }

            if (string[counter] == 'c'){
                if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
                    counter = counter + 3;
                    res = acos(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }

            if (string[counter] == 't'){
                if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
                    counter = counter + 3;
                    res = atan(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }

            if (string[counter] == 'b'){
                if ((string[counter + 1] == 's') && (string[counter + 2] == '(')){
                    counter = counter + 2;
                    res = abs(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }
        }

        if (string[counter] == 'x'){
            res = x;
            counter++;
        }
        if (string[counter] == '.'){
            error = true;
            return 0;
        }
    }
    return res;
}

double integral::degree(std::string string, int& counter, double x, int& brct, bool& error){
    double res = 0;
    bool pointchecker = false;
    bool mmarker = false;
    int subcounter = counter; // óêàçàòåëü íà êîíå÷ ÷èñëà

    while (counter < string.length()){

        if ((string[counter] >= '0') && (string[counter] <= '9')){
            bool pointchecker = false;
            int subcounter = counter; // ñ÷åò÷èê äëÿ ñ÷èòûâàíèÿ ÷èñëà
            if (mmarker) subcounter--; // -
            while (((string[counter] >= '0') && (string[counter] <= '9')) || (string[counter] == '.')){ // !!!!

                if ((string[counter] == '.') && pointchecker){
                    error = true; return 0;
                }
                if (string[counter] == '.') pointchecker = true;
                counter++;
            }
            res = stod(string.substr(subcounter, counter + 1)); // ïàðñèì ÷èñëî â äàáë !!!
        }

        if (string[counter] == '+'){
            if (brct != 0){
                ++counter;
                if (correctcont(string[counter])) res = res + value_at_a_point(string, counter, x, brct, error);
                else {
                    error = true; return 0;
                }
            }
            else return res;
        }

        if (string[counter] == '-'){
            if (brct != 0){
                ++counter;
                if (correctcont(string[counter])) res = res - value_at_a_point(string, counter, x, brct, error);
                else {
                    error = true; return 0;
                }
            }
            else return res;
        }

        if (string[counter] == '*'){
            if (brct != 0){
                ++counter;
                if (correctcont(string[counter])) res = res * multiplication(string, counter, x, brct, error);
                else {
                    error = true; return 0;
                }
            }
            else return res;
        }

        if (string[counter] == '/'){
            if (brct != 0){
                ++counter;
                if (correctcont(string[counter])) res = res / multiplication(string, counter, x, brct, error);
                else {
                    error = true; return 0;
                }
            }
            else return res;
        }
        if (string[counter] == '^'){
            ++counter;
            if (correctcont(string[counter])) res = pow(res, degree(string, counter, x, brct, error));
            else {
                error = true; return 0;
            }
        }

        if (string[counter] == '('){
            ++counter; // âîçìîæíî ïîòîì äîáàâèòü ñ÷åò÷èê  ñêîáîê
            ++brct;
            if ((string[counter] == '-') && is_number(string[counter + 1])){
                mmarker = true;
            }
        }

        if (string[counter] == ')'){
            if (brct <= 0) {
                error = true;
                return 0;
            }
            ++counter;
            if (counter == string.length()){
                --brct;
                return res;
            }
            else{
                if (string[counter] == '+' || string[counter] == '-' || string[counter] == '*' || string[counter] == '/' || string[counter] == '^'){
                    --brct;
                    return res;
                }
                else{
                    error = true;
                    return 0;
                }
            }
        }

        if (string[counter] == 's'){
            ++counter;

            if (string[counter] == 'q'){
                if ((string[counter + 1] == 'r') && (string[counter + 2] == 't') && (string[counter + 3]) == '('){
                    counter = counter + 3;
                    res = sqrt(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }

            if (string[counter] == 'i'){
                if ((string[counter + 1] == 'n') && (string[counter + 2] == '(')){
                    counter = counter + 2;
                    res = sin(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }
        }

        if (string[counter] == 'c'){
            if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
                counter = counter + 3;
                res = cos(value_at_a_point(string, counter, x, brct, error));
            }
            else{
                error = true; return 0;
            }
        }

        if (string[counter] == 't'){
            if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
                counter = counter + 3;
                res = tan(value_at_a_point(string, counter, x, brct, error));
            }
            else{
                error = true; return 0;
            }
        }

        if (string[counter] == 'l'){
            if ((string[counter + 1] == 'o') && (string[counter + 2] == 'g') && (string[counter + 3] == '(')){
                counter = counter + 3;
                res = log(value_at_a_point(string, counter, x, brct, error));
            }
            else{
                error = true; return 0;
            }
        }

        if (string[counter] == 'e'){
            if ((string[counter + 1] == 'x') && (string[counter + 2] == 'p') && (string[counter + 3] == '(')){
                counter = counter + 3;
                res = exp(value_at_a_point(string, counter, x, brct, error));
            }
            else{
                error = true; return 0;
            }
        }

        if (string[counter] == 'a'){
            ++counter;

            if (string[counter] == 's'){
                if ((string[counter + 1] == 'i') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
                    counter = counter + 3;
                    res = asin(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }

            if (string[counter] == 'c'){
                if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
                    counter = counter + 3;
                    res = acos(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }

            if (string[counter] == 't'){
                if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
                    counter = counter + 3;
                    res = atan(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }

            if (string[counter] == 'b'){
                if ((string[counter + 1] == 's') && (string[counter + 2] == '(')){
                    counter = counter + 2;
                    res = abs(value_at_a_point(string, counter, x, brct, error));
                }
                else{
                    error = true; return 0;
                }
            }
        }

        if (string[counter] == 'x'){
            res = x;
            counter++;
        }
        if (string[counter] == '.'){
            error = true;
            return 0;
        }
    }
    return res;
}


