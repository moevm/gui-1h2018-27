#include "matrix_inverse_5x5.h"
#include "ui_matrix_inverse_5x5.h"
#include <QMessageBox>

matrix_inverse_5x5::matrix_inverse_5x5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_inverse_5x5)
{
    ui->setupUi(this);

    ui->pushButton_inverse_5x5->setDefault(true);//принажатии кнопки enter, будет нажиматься ok
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
    ui->lineEdit_17->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_18->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_19->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_20->setValidator(new QRegExpValidator(exp, this));

    ui->lineEdit_21->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_22->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_23->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_24->setValidator(new QRegExpValidator(exp, this));
    ui->lineEdit_25->setValidator(new QRegExpValidator(exp, this));
}

matrix_inverse_5x5::~matrix_inverse_5x5()
{
    delete ui;
}

void matrix_inverse_5x5::getMatrixWithoutRowAndCol(double **matrix, int size, int row, int col, double **newMatrix)
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

double matrix_inverse_5x5::matrixDet(double **matrix, int size)
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

double **matrix_inverse_5x5::InverseMatrix(double **a, double **b, bool &error, int size)
{
    double chast = 0;
    double mnoj = 0;
    double **c = new double*[size];
    for (int i = 0; i < size; i++) { // åä ìàòðèöà
        c[i] = new double[size];
    }

    for (int i = 0; i < size; i++){ // åä ìàòðèöà
        for (int k = 0; k < size; ++k){
            if (i == k) c[i][k] = 1;
            else c[i][k] = 0;
        }
    }
    if (matrixDet(a, size) == 0){
        error = true;
        return a;
    }
    else{
        for (int gli = 0; gli < size; ++gli){
            chast = a[gli][gli];
            for (int k = 0; k < size; ++k){
                c[gli][k] = c[gli][k] / chast;
                a[gli][k] = a[gli][k] / chast;
            }
            for (int k = 0; k < size; ++k){
                if (k != gli){
                    mnoj = a[k][gli];
                    for (int l = 0; l < size; ++l){
                        a[k][l] = a[k][l] - a[gli][l] * mnoj;
                        c[k][l] = c[k][l] - c[gli][l] * mnoj;
                    }
                }
            }
        }
    }
    b = c;
    return b;
}

void matrix_inverse_5x5::on_pushButton_clear_clicked()
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
    ui->lineEdit_17->setText("");
    ui->lineEdit_18->setText("");
    ui->lineEdit_19->setText("");
    ui->lineEdit_20->setText("");

    ui->lineEdit_21->setText("");
    ui->lineEdit_22->setText("");
    ui->lineEdit_23->setText("");
    ui->lineEdit_24->setText("");
    ui->lineEdit_25->setText("");
}

void matrix_inverse_5x5::on_pushButton_clear_res_clicked()
{
    ui->label_inverse_5x5_res_1->setText("");
    ui->label_inverse_5x5_res_2->setText("");
    ui->label_inverse_5x5_res_3->setText("");
    ui->label_inverse_5x5_res_4->setText("");
    ui->label_inverse_5x5_res_5->setText("");

    ui->label_inverse_5x5_res_6->setText("");
    ui->label_inverse_5x5_res_7->setText("");
    ui->label_inverse_5x5_res_8->setText("");
    ui->label_inverse_5x5_res_9->setText("");
    ui->label_inverse_5x5_res_10->setText("");

    ui->label_inverse_5x5_res_11->setText("");
    ui->label_inverse_5x5_res_12->setText("");
    ui->label_inverse_5x5_res_13->setText("");
    ui->label_inverse_5x5_res_14->setText("");
    ui->label_inverse_5x5_res_15->setText("");

    ui->label_inverse_5x5_res_16->setText("");
    ui->label_inverse_5x5_res_17->setText("");
    ui->label_inverse_5x5_res_18->setText("");
    ui->label_inverse_5x5_res_19->setText("");
    ui->label_inverse_5x5_res_20->setText("");

    ui->label_inverse_5x5_res_21->setText("");
    ui->label_inverse_5x5_res_22->setText("");
    ui->label_inverse_5x5_res_23->setText("");
    ui->label_inverse_5x5_res_24->setText("");
    ui->label_inverse_5x5_res_25->setText("");
}

void matrix_inverse_5x5::on_pushButton_inverse_5x5_clicked()
{
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
    if(ui->lineEdit_17->text().isEmpty()){ ui->lineEdit_17->setText("0"); }
    if(ui->lineEdit_18->text().isEmpty()){ ui->lineEdit_18->setText("0"); }
    if(ui->lineEdit_19->text().isEmpty()){ ui->lineEdit_19->setText("0"); }
    if(ui->lineEdit_20->text().isEmpty()){ ui->lineEdit_20->setText("0"); }

    if(ui->lineEdit_21->text().isEmpty()){ ui->lineEdit_21->setText("0"); }
    if(ui->lineEdit_22->text().isEmpty()){ ui->lineEdit_22->setText("0"); }
    if(ui->lineEdit_23->text().isEmpty()){ ui->lineEdit_23->setText("0"); }
    if(ui->lineEdit_24->text().isEmpty()){ ui->lineEdit_24->setText("0"); }
    if(ui->lineEdit_25->text().isEmpty()){ ui->lineEdit_25->setText("0"); }


    int dim = 5;
    bool error = false;

    double **matrix = new double*[dim];
    for(int i = 0; i < dim; i++)
    {
        matrix[i] = new double[dim];
    }

    matrix[0][0] = (ui->lineEdit_1->text()).toDouble();
    matrix[0][1] = (ui->lineEdit_2->text()).toDouble();
    matrix[0][2] = (ui->lineEdit_3->text()).toDouble();
    matrix[0][3] = (ui->lineEdit_4->text()).toDouble();
    matrix[0][4] = (ui->lineEdit_5->text()).toDouble();

    matrix[1][0] = (ui->lineEdit_6->text()).toDouble();
    matrix[1][1] = (ui->lineEdit_7->text()).toDouble();
    matrix[1][2] = (ui->lineEdit_8->text()).toDouble();
    matrix[1][3] = (ui->lineEdit_9->text()).toDouble();
    matrix[1][4] = (ui->lineEdit_10->text()).toDouble();

    matrix[2][0] = (ui->lineEdit_11->text()).toDouble();
    matrix[2][1] = (ui->lineEdit_12->text()).toDouble();
    matrix[2][2] = (ui->lineEdit_13->text()).toDouble();
    matrix[2][3] = (ui->lineEdit_14->text()).toDouble();
    matrix[2][4] = (ui->lineEdit_15->text()).toDouble();

    matrix[3][0] = (ui->lineEdit_16->text()).toDouble();
    matrix[3][1] = (ui->lineEdit_17->text()).toDouble();
    matrix[3][2] = (ui->lineEdit_18->text()).toDouble();
    matrix[3][3] = (ui->lineEdit_19->text()).toDouble();
    matrix[3][4] = (ui->lineEdit_20->text()).toDouble();

    matrix[4][0] = (ui->lineEdit_21->text()).toDouble();
    matrix[4][1] = (ui->lineEdit_22->text()).toDouble();
    matrix[4][2] = (ui->lineEdit_23->text()).toDouble();
    matrix[4][3] = (ui->lineEdit_24->text()).toDouble();
    matrix[4][4] = (ui->lineEdit_25->text()).toDouble();

    double **res = new double*[dim];
    for(int i = 0; i < dim; i++){
        res[i] = new double[dim];
    }

    res = InverseMatrix(matrix, res, error, dim);

    if (error == true) {
        QMessageBox::warning(this, "Error!", "Обратная матрица не существует!!!");
    } else {

        ui->label_inverse_5x5_res_1->setText(QString::number(res[0][0]));
        ui->label_inverse_5x5_res_2->setText(QString::number(res[0][1]));
        ui->label_inverse_5x5_res_3->setText(QString::number(res[0][2]));
        ui->label_inverse_5x5_res_4->setText(QString::number(res[0][3]));
        ui->label_inverse_5x5_res_5->setText(QString::number(res[0][4]));

        ui->label_inverse_5x5_res_6->setText(QString::number(res[0][0]));
        ui->label_inverse_5x5_res_7->setText(QString::number(res[0][1]));
        ui->label_inverse_5x5_res_8->setText(QString::number(res[0][2]));
        ui->label_inverse_5x5_res_9->setText(QString::number(res[0][3]));
        ui->label_inverse_5x5_res_10->setText(QString::number(res[0][4]));

        ui->label_inverse_5x5_res_11->setText(QString::number(res[0][0]));
        ui->label_inverse_5x5_res_12->setText(QString::number(res[0][1]));
        ui->label_inverse_5x5_res_13->setText(QString::number(res[0][2]));
        ui->label_inverse_5x5_res_14->setText(QString::number(res[0][3]));
        ui->label_inverse_5x5_res_15->setText(QString::number(res[0][4]));

        ui->label_inverse_5x5_res_16->setText(QString::number(res[0][0]));
        ui->label_inverse_5x5_res_17->setText(QString::number(res[0][1]));
        ui->label_inverse_5x5_res_18->setText(QString::number(res[0][2]));
        ui->label_inverse_5x5_res_19->setText(QString::number(res[0][3]));
        ui->label_inverse_5x5_res_20->setText(QString::number(res[0][4]));

        ui->label_inverse_5x5_res_21->setText(QString::number(res[0][0]));
        ui->label_inverse_5x5_res_22->setText(QString::number(res[0][1]));
        ui->label_inverse_5x5_res_23->setText(QString::number(res[0][2]));
        ui->label_inverse_5x5_res_24->setText(QString::number(res[0][3]));
        ui->label_inverse_5x5_res_25->setText(QString::number(res[0][4]));

    }

}
