#include "matrix_det_4x4.h"
#include "ui_matrix_det_4x4.h"


matrix_det_4x4::matrix_det_4x4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_det_4x4)
{
    ui->setupUi(this);

    ui->pushButton_det_4x4->setDefault(true);//принажатии кнопки enter, будет нажиматься ok
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

void matrix_det_4x4::getMatrixWithoutRowAndCol(double **matrix, int size, int row, int col, double **newMatrix)
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

double matrix_det_4x4::matrixDet(double **matrix, int size)
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

    int dim = 4;

    double **matrix = new double*[dim];
    for(int i = 0; i < dim; i++)
    {
        matrix[i] = new double[dim];
    }

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


    double det_4x4 = matrixDet(matrix, dim);
    QString new_det_4x4 = QString::number(det_4x4);
    ui->label_det_4x4_res->setText(new_det_4x4);

}
