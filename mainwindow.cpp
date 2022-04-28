#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    strModel = new QStringListModel(this);
    model = new QStandardItemModel(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::workList(){
    /*QStringList list;
    list << "Строка 1" << "Строка 2" << "Строка 3" << "Строка 4";
    list << "PROGERR";
    strModel->setStringList(list);
    ui->listView->setModel(strModel);*/
    model = new QStandardItemModel(this);
    ui->listView->setModel(model);
    model->appendRow(new
    QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_MediaVolume)),
    "C++"));
    model->appendRow(new
    QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_MediaPlay)),
    "Python"));
    model->appendRow(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_MediaPlay)), "JAVA"));

}


void MainWindow::on_pushButton_clicked()
{
    model->appendRow(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_MediaPlay)), "NO NAME"));

}

