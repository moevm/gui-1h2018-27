#include "matrix_multiplication.h"
#include "ui_matrix_multiplication.h"
#include <QLineEdit>
#include <QWidget>
#include <QMessageBox>
#include <QCoreApplication>
#include <string>
#include <iostream>
#include <QObject>
#include <QString>


matrix_multiplication::matrix_multiplication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_multiplication)
{
    ui->setupUi(this);
//    ui->pushButton_3->setDefault(true);//принажатии кнопки enter, будет нажиматься ok
    ui->pushButton_3->setEnabled(false);//делаем кнопку пока недоступной

}

matrix_multiplication::~matrix_multiplication()
{
    delete ui;
}

double **matrix_multiplication::MultiplicationMatrix(double **a, double **b, int lsize, int msize, int nsize)
{
    double **c = new double*[lsize];
    for (int i = 0; i < lsize; i++) {
        c[i] = new double[nsize];
    }

    for (int i = 0; i < lsize; i++) {
        for (int l = 0; l < nsize; l++) {
            double s = 0;
            for (int j = 0; j < msize; j++) {
                s += a[i][j] * b[j][l];
            }
            c[i][l] = s;
        }
    }

    return c;
}


void matrix_multiplication::on_pushButton_clicked()
{
    ui->pushButton_3->setEnabled(true);

    a = ui->comboBox_A_a->currentText().toDouble();
    b = ui->comboBox_A_b->currentText().toDouble();
    c = ui->comboBox_B_b->currentText().toDouble();

    //матрица А
    ui->tableWidget_A->setRowCount(a);
    ui->tableWidget_A->setColumnCount(b);
    //матрица В
    ui->tableWidget_B->setRowCount(b);
    ui->tableWidget_B->setColumnCount(c);



    for(int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            QTableWidgetItem *item = new QTableWidgetItem;

            item -> setText(QString::number(0));
            ui->tableWidget_A->setItem(i, j, item);
            ui->tableWidget_A->setColumnWidth(j, 388/b+1);
            ui->tableWidget_A->setRowHeight(i, 233/a+1);
            ui->tableWidget_A->verticalHeader()->hide();
            ui->tableWidget_A->horizontalHeader()->hide();
            const QModelIndex index = ui->tableWidget_A->model()->index(i, j);
            ui->tableWidget_A->model()->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
        }
    }

    for(int i = 0; i < b; i++){
        for (int j = 0; j < c; j++){
            QTableWidgetItem *item = new QTableWidgetItem;

            item -> setText(QString::number(0));
            ui->tableWidget_B->setItem(i, j, item);
            ui->tableWidget_B->setColumnWidth(j, 390/c);
            ui->tableWidget_B->setRowHeight(i, 235/b);
            ui->tableWidget_B->verticalHeader()->hide();
            ui->tableWidget_B->horizontalHeader()->hide();
            const QModelIndex index = ui->tableWidget_B->model()->index(i, j);
            ui->tableWidget_B->model()->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
        }
    }

}


void matrix_multiplication::on_pushButton_3_clicked()
{
    ui->tableWidget_C->setRowCount(a);
    ui->tableWidget_C->setColumnCount(c);

    //доп матрица А
    double **matrix_A = new double*[a];
    for(int i = 0; i < a; i++)
    {
        matrix_A[i] = new double[b];
    }
    //доп матрица В
    double **matrix_B = new double*[b];
    for(int i = 0; i < b; i++)
    {
        matrix_B[i] = new double[c];
    }
    //доп матрица С
    double **matrix_C = new double*[a];
    for(int i = 0; i < a; i++)
    {
        matrix_C[i] = new double[c];
    }

    for(int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            matrix_A[i][j] = ui->tableWidget_A->item(i, j)->text().toDouble();
        }
    }

    for(int i = 0; i < b; i++){
        for (int j = 0; j < c; j++){
            matrix_B[i][j] = ui->tableWidget_B->item(i, j)->text().toDouble();
        }
    }

    bool ok= true;
    QString str;
    double val=0;
    for(int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            str = ui->tableWidget_A->item(i, j)->text();
            val = str.toDouble(&ok);
            if(ok) {
                matrix_A[i][j] = ui->tableWidget_A->item(i, j)->text().toDouble();
                matrix_C = MultiplicationMatrix(matrix_A, matrix_B, a, b, c);
            }
            else {
                QMessageBox::warning(this, "Error!", "Введенные вами данные некорректны!!!");
            }//obrabotka
        }
    }

    for(int i = 0; i < b; i++){
        for (int j = 0; j < c; j++){
            str = ui->tableWidget_B->item(i, j)->text();
            val = str.toDouble(&ok);
            if(ok){
                matrix_B[i][j] = ui->tableWidget_B->item(i, j)->text().toDouble();
                matrix_C = MultiplicationMatrix(matrix_A, matrix_B, a, b, c);
            }

            else{
                QMessageBox::warning(this, "Error!", "Введенные вами данные некорректны!!!");
            }//obrabotka
        }
    }


    for(int i = 0; i < a; i++){
        for (int j = 0; j < c; j++){
            std::cout << matrix_C[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < a; i++){
        for (int j = 0; j < c; j++){
            QTableWidgetItem *item = new QTableWidgetItem;
            item -> setText(QString::number(0));
            ui->tableWidget_C->setItem(i, j, item);
            ui->tableWidget_C->setColumnWidth(j, 418/c);
            ui->tableWidget_C->setRowHeight(i, 235/a);
            ui->tableWidget_C->verticalHeader()->hide();
            ui->tableWidget_C->horizontalHeader()->hide();
            const QModelIndex index = ui->tableWidget_C->model()->index(i, j);
            ui->tableWidget_C->model()->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
        }
    }

    //cделать вывод неактивным
    for(int i = 0; i < a; i++){
        for (int j = 0; j < c; j++){
            ui->tableWidget_C->item(i, j)->setText(QString::number(matrix_C[i][j]));
            ui->tableWidget_C->item(i, j)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        }
    }
}
