#include "matrix_det.h"
#include "ui_matrix_det.h"
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QWidget>
#include "matrix_det_2x2.h"
#include "matrix_det_3x3.h"
#include "matrix_det_4x4.h"
#include "matrix_det_5x5.h"

matrix_det::matrix_det(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_det)
{
    ui->setupUi(this);
}

matrix_det::~matrix_det()
{
    delete ui;
}


void matrix_det::on_pushButton_clicked()
{
    QString dim = ui->comboBox_matrix_det->currentText();
    if(dim == "2x2")
    {
        matrix_det_2x2 *matrix_2x2 = new matrix_det_2x2;
        matrix_2x2->show();

    } else if(dim == "3x3")
    {
        matrix_det_3x3 *matrix_3x3 = new matrix_det_3x3;
        matrix_3x3->show();

    } else if(dim == "4x4")
    {
        matrix_det_4x4 *matrix_4x4 = new matrix_det_4x4;
        matrix_4x4->show();

    } else if(dim == "5x5")
    {
        matrix_det_5x5 *matrix_5x5 = new matrix_det_5x5;
        matrix_5x5->show();
    }
}

/*
void matrix_det::on_pushButton_clicked()
{
    QString dim = ui->comboBox_matrix_det->currentText();
    /*while(true){
        QVBoxLayout *v_layout = new QVBoxLayout;
        for (int i = 0; i < v_layout->count();)
          {
            QLayoutItem *item = v_layout->itemAt(i);
            if (item->layout() != nullptr)     // Check whether item contains a layout
                delete v_layout->takeAt(i);  // Delete item with layout on it
            else i++;
          }
        if(dim == "2x2")
        {
            //delete ui->verticalLayout;

            line1 = new QLineEdit;
            line2 = new QLineEdit;
            line3 = new QLineEdit;
            line4 = new QLineEdit;

            QHBoxLayout *h_layout1 = new QHBoxLayout;
            QHBoxLayout *h_layout2 = new QHBoxLayout;
            QVBoxLayout *v_layout = new QVBoxLayout;

            h_layout1->addWidget(line1);
            h_layout1->addWidget(line2);

            h_layout2->addWidget(line3);
            h_layout2->addWidget(line4);


            v_layout->addLayout(h_layout1);
            v_layout->addLayout(h_layout2);

            //matrix_det_widget *new_matrix = new matrix_det_widget();
            ui->verticalLayout->addLayout(v_layout);


        } else if (dim == "3x3")
        {
            line1 = new QLineEdit;
            line2 = new QLineEdit;
            line3 = new QLineEdit;
            line4 = new QLineEdit;
            line5 = new QLineEdit;
            line6 = new QLineEdit;
            line7 = new QLineEdit;
            line8 = new QLineEdit;
            line9 = new QLineEdit;

            QHBoxLayout *h_layout1 = new QHBoxLayout;
            QHBoxLayout *h_layout2 = new QHBoxLayout;
            QHBoxLayout *h_layout3 = new QHBoxLayout;
            QVBoxLayout *v_layout = new QVBoxLayout;

            h_layout1->addWidget(line1);
            h_layout1->addWidget(line2);
            h_layout1->addWidget(line3);

            h_layout2->addWidget(line4);
            h_layout2->addWidget(line5);
            h_layout2->addWidget(line6);

            h_layout3->addWidget(line7);
            h_layout3->addWidget(line8);
            h_layout3->addWidget(line9);

            v_layout->addLayout(h_layout1);
            v_layout->addLayout(h_layout2);
            v_layout->addLayout(h_layout3);

            ui->verticalLayout->addLayout(v_layout);

        } else if (dim == "4x4")
        {

            line1 = new QLineEdit;
            line2 = new QLineEdit;
            line3 = new QLineEdit;
            line4 = new QLineEdit;
            line5 = new QLineEdit;
            line6 = new QLineEdit;
            line7 = new QLineEdit;
            line8 = new QLineEdit;
            line9 = new QLineEdit;
            line10 = new QLineEdit;
            line11 = new QLineEdit;
            line12 = new QLineEdit;
            line13 = new QLineEdit;
            line14 = new QLineEdit;
            line15 = new QLineEdit;
            line16 = new QLineEdit;

            QHBoxLayout *h_layout1 = new QHBoxLayout;
            QHBoxLayout *h_layout2 = new QHBoxLayout;
            QHBoxLayout *h_layout3 = new QHBoxLayout;
            QHBoxLayout *h_layout4 = new QHBoxLayout;
            QVBoxLayout *v_layout = new QVBoxLayout;

            h_layout1->addWidget(line1);
            h_layout1->addWidget(line2);
            h_layout1->addWidget(line3);
            h_layout1->addWidget(line4);

            h_layout2->addWidget(line5);
            h_layout2->addWidget(line6);
            h_layout2->addWidget(line7);
            h_layout2->addWidget(line8);

            h_layout3->addWidget(line9);
            h_layout3->addWidget(line10);
            h_layout3->addWidget(line11);
            h_layout3->addWidget(line12);

            h_layout4->addWidget(line13);
            h_layout4->addWidget(line14);
            h_layout4->addWidget(line15);
            h_layout4->addWidget(line16);

            v_layout->addLayout(h_layout1);
            v_layout->addLayout(h_layout2);
            v_layout->addLayout(h_layout3);
            v_layout->addLayout(h_layout4);

            ui->verticalLayout->addLayout(v_layout);


        } else if(dim == "5x5")
        {
            line1 = new QLineEdit;
            line2 = new QLineEdit;
            line3 = new QLineEdit;
            line4 = new QLineEdit;
            line5 = new QLineEdit;
            line6 = new QLineEdit;
            line7 = new QLineEdit;
            line8 = new QLineEdit;
            line9 = new QLineEdit;
            line10 = new QLineEdit;
            line11 = new QLineEdit;
            line12 = new QLineEdit;
            line13 = new QLineEdit;
            line14 = new QLineEdit;
            line15 = new QLineEdit;
            line16 = new QLineEdit;
            line17 = new QLineEdit;
            line18 = new QLineEdit;
            line19 = new QLineEdit;
            line20 = new QLineEdit;
            line21 = new QLineEdit;
            line22 = new QLineEdit;
            line23 = new QLineEdit;
            line24 = new QLineEdit;
            line25 = new QLineEdit;

            QHBoxLayout *h_layout1 = new QHBoxLayout;
            QHBoxLayout *h_layout2 = new QHBoxLayout;
            QHBoxLayout *h_layout3 = new QHBoxLayout;
            QHBoxLayout *h_layout4 = new QHBoxLayout;
            QHBoxLayout *h_layout5 = new QHBoxLayout;
            QVBoxLayout *v_layout = new QVBoxLayout;

            h_layout1->addWidget(line1);
            h_layout1->addWidget(line2);
            h_layout1->addWidget(line3);
            h_layout1->addWidget(line4);
            h_layout1->addWidget(line5);

            h_layout2->addWidget(line6);
            h_layout2->addWidget(line7);
            h_layout2->addWidget(line8);
            h_layout2->addWidget(line9);
            h_layout2->addWidget(line10);

            h_layout3->addWidget(line11);
            h_layout3->addWidget(line12);
            h_layout3->addWidget(line13);
            h_layout3->addWidget(line14);
            h_layout3->addWidget(line15);

            h_layout4->addWidget(line16);
            h_layout4->addWidget(line17);
            h_layout4->addWidget(line18);
            h_layout4->addWidget(line19);
            h_layout4->addWidget(line20);

            h_layout5->addWidget(line21);
            h_layout5->addWidget(line22);
            h_layout5->addWidget(line23);
            h_layout5->addWidget(line24);
            h_layout5->addWidget(line25);

            v_layout->addLayout(h_layout1);
            v_layout->addLayout(h_layout2);
            v_layout->addLayout(h_layout3);
            v_layout->addLayout(h_layout4);
            v_layout->addLayout(h_layout5);

            ui->verticalLayout->addLayout(v_layout);

        }

    }





void matrix_det::on_pushButton_2_clicked()
{
    /*QLayoutItem *child;
    while ((child = ui->verticalLayout->takeAt(0)) != 0) {

        delete child;
    }*/
/*
    QLayout* layout = ui->verticalLayout;//ui.scrollAreaWidgetContents->layout();
        for(int i = 0; i < layout->count(); ++i)
        {
            QLayoutItem* item = layout->itemAt(i);
            if(item)
            {
                layout->removeItem( item );
                QWidget* widget = item->widget();
                if(widget)
                {
                    layout->removeWidget(widget);
                    delete widget;
                }
                delete item;
            }
        }
*/


    /*
    for (int i = 0; i < ui->verticalLayout->count(); )
      {
        QLayoutItem *item = ui->verticalLayout->itemAt(i);
        if (item->layout() != nullptr)     // Check whether item contains a layout
            delete ui->verticalLayout->takeAt(i);  // Delete item with layout on it
        else i++;
      }
}
*/


void matrix_det::on_pushButton_2_clicked()
{
    close();
}
