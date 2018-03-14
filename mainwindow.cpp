#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QMovie>
#include "integral.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_close_triggered()
{
    close();
}

void MainWindow::on_pushButton_integral_clicked()
{
    integral *new_integral = new integral(this);
    new_integral->show();
}

void MainWindow::on_help_triggered()
{
    QMessageBox::about(this, "Справка", "Ей кто-то пользуется?! Если нет, то можно просто оставить это так?..");
}
