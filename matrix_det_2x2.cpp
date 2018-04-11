#include "matrix_det_2x2.h"
#include "ui_matrix_det_2x2.h"
#include "matrix_det.h"
#include <QMessageBox>
#include <iostream>
#include <QString>
#include <QTextStream>
QTextStream cout(stdout);
QTextStream cin(stdin);

matrix_det_2x2::matrix_det_2x2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_det_2x2)
{
    ui->setupUi(this);

    QRegExp exp("[-]{0,1}[0-9]{1,4}[.]{0,1}[0-9]{1,5}");
    ui->lineEdit_1->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_2->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_3->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_4->setValidator(new QRegExpValidator(exp, this));
}

matrix_det_2x2::~matrix_det_2x2()
{
    delete ui;
}

void matrix_det_2x2::getMatrixWithoutRowAndCol(double **matrix, int size, int row, int col, double **newMatrix)
{
    int offsetRow = 0; //Ñìåùåíèå èíäåêñà ñòðîêè â ìàòðèöå
        int offsetCol = 0; //Ñìåùåíèå èíäåêñà ñòîëáöà â ìàòðèöå
        for (int i = 0; i < size - 1; i++) {
            //Ïðîïóñòèòü row-óþ ñòðîêó
            if (i == row) {
                offsetRow = 1; //Êàê òîëüêî âñòðåòèëè ñòðîêó, êîòîðóþ íàäî ïðîïóñòèòü, äåëàåì ñìåùåíèå äëÿ èñõîäíîé ìàòðèöû
            }

            offsetCol = 0; //Îáíóëèòü ñìåùåíèå ñòîëáöà
            for (int j = 0; j < size - 1; j++) {
                //Ïðîïóñòèòü col-ûé ñòîëáåö
                if (j == col) {
                    offsetCol = 1; //Âñòðåòèëè íóæíûé ñòîëáåö, ïðîóñêàåì åãî ñìåùåíèåì
                }
                newMatrix[i][j] = matrix[i + offsetRow][j + offsetCol];
            }
        }
}

double matrix_det_2x2::matrixDet(double **matrix, int size)
{
    double det = 0;
        int degree = 1;


        if (size == 1) {
            return matrix[0][0];
        }
        else if (size == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }
        else {
            //Ìàòðèöà áåç ñòðîêè è ñòîëáöà
            double **newMatrix = new double*[size - 1];
            for (int i = 0; i < size - 1; i++) {
                newMatrix[i] = new double[size - 1];
            }

            //Ðàñêëàäûâàåì ïî 0-îé ñòðîêå, öèêë áåæèò ïî ñòîëáöàì
            for (int j = 0; j < size; j++) {
                //Óäàëèòü èç ìàòðèöû i-þ ñòðîêó è j-ûé ñòîëáåö
                //Ðåçóëüòàò â newMatrix
                getMatrixWithoutRowAndCol(matrix, size, 0, j, newMatrix);
                det = det + (degree * matrix[0][j] * matrixDet(newMatrix, size - 1));
                degree = -degree;
            }
            //×èñòèì ïàìÿòü íà êàæäîì øàãå ðåêóðñèè(âàæíî!)
            for (int i = 0; i < size - 1; i++) {
                delete[] newMatrix[i];
            }
            delete[] newMatrix;
        }

        return det;
}


void matrix_det_2x2::on_pushButton_clear_clicked()
{
    ui->lineEdit_1->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
}

void matrix_det_2x2::on_pushButton_det_2x2_clicked()
{

    if(ui->lineEdit_1->text().isEmpty()){ ui->lineEdit_1->setText("0"); }
    if(ui->lineEdit_2->text().isEmpty()){ ui->lineEdit_2->setText("0"); }
    if(ui->lineEdit_3->text().isEmpty()){ ui->lineEdit_3->setText("0"); }
    if(ui->lineEdit_4->text().isEmpty()){ ui->lineEdit_4->setText("0"); }

    int dim = 2;
    //double det_2x2;

    double **matrix = new double*[dim];
    for(int i = 0; i < dim; i++)
    {
        matrix[i] = new double[dim];
    }

    matrix[0][0] = (ui->lineEdit_1->text()).toDouble();
    matrix[0][1] = (ui->lineEdit_2->text()).toDouble();
    matrix[1][0] = (ui->lineEdit_3->text()).toDouble();
    matrix[1][1] = (ui->lineEdit_4->text()).toDouble();

    double det_2x2 = matrixDet(matrix, dim);
    QString new_det_2x2 = QString::number(det_2x2);
    ui->label_det_2x2_res->setText(new_det_2x2);

}

