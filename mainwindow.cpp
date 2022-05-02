#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filter = trUtf8("Текстовый файл(*.txt);;Двоичный файл(*.original)");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString s = QFileDialog::getSaveFileName(this, "Заголовок окна",
    QDir::current().path(), filter);
    if (s.length() > 0)
    {
    QString ext = QString(&(s.data()[s.length() - 4]));
    if (ext == ".txt")
    {
    QFile file(s);
    if (file.open(QFile::WriteOnly | QFile::NewOnly))
    {
    QTextStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();
    file.close();
    }
    }
    }

}


void MainWindow::on_pushButton_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, "Заголовок окна",
    QDir::current().path(), filter);
    if (s.length() > 0)
    {
        int index = s.indexOf(".txt");
        if (index != -1 && s.length() - 4 == index)
        {
            QFile file(s);
            if (file.open(QFile::ReadOnly | QFile::ExistingOnly))
            {
                QTextStream stream(&file);
                ui->plainTextEdit->setPlainText(stream.readAll());
                file.close();
            }
        }
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    QFile file (":/myh.txt");
    if (file.open(QIODevice::ReadOnly))
    {
    QTextStream stream(&file);
    QString str = stream.read(file.size());
    ui->plainTextEdit->setPlainText(str);
    }


}

