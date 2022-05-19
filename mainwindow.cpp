#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //auto mypalette = ui->plainTextEdit->palette();
    //auto mypalette = ui->pushButton->palette();
    //mypalette.setColor(QPalette::Text, Qt::green);
    //setPalette(mypalette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    auto mypalette = ui->pushButton->palette();
    mypalette.setColor(QPalette::Window, QColor("#ff0000"));
    mypalette.setColor(QPalette::Text, Qt::green);
    setPalette(mypalette);

}


void MainWindow::on_pushButton_2_clicked()
{
    auto mypalette = ui->pushButton->palette();
    mypalette.setColor(QPalette::Window, Qt::white);
    mypalette.setColor(QPalette::Text, Qt::green);
    setPalette(mypalette);
}

