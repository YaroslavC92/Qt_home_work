#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), opButt(nullptr)
{
    const QSize btnSize = QSize(200, 20);
    ui->setupUi(this);
    filter = trUtf8("Текстовый файл(*.txt);;Двоичный файл(*.original)");
    opButt = new QPushButton(this);
    if (!opButt) return;
    opButt->move(40, 370);
    opButt->setText("Открыть без редактирования");
    opButt->setFixedSize(btnSize);
    connect(opButt, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked()));
    connect(this, SIGNAL(openFile()), this, SLOT(on_pushButton_clicked()));
    connect(this, SIGNAL(saveFile()), this, SLOT(on_pushButton_2_clicked()));
    connect(this, SIGNAL(helpFile()), this, SLOT(on_pushButton_3_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
    if (opButt) delete opButt;
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

void MainWindow::on_pushButton_4_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, "Заголовок окна",
    QDir::current().path(), filter);
    if (s.length() > 0)
    {
        int index = s.indexOf(".txt");
        if (index != -1 && s.length() - 4 == index)
        {
            QFile file(s);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream stream(&file);
                ui->plainTextEdit->setPlainText(stream.readAll());
                file.close();
            }
        }
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_F1)
         emit openFile();

    else if (event->key() == Qt::Key_F2)
         emit saveFile();

    else if (event->key() == Qt::Key_F3)
         emit helpFile();








}

