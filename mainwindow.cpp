#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   this->currentIndex = 0;
   this->sum = 0;
   timer =  new QTimer(this);
    ui->setupUi(this);
    ui->radioButton->setChecked(true);

}

MainWindow::~MainWindow()
{
    delete ui;
    }

void MainWindow::on_pushButton_clicked()
{
    QFont font;
    font.setFamily("Arial");
    font.setBold(true);
    ui->label->setFont(font);
    int sum = ui->textEdit->toPlainText().toInt();
    if(sum == this->sum){
        ui->label->setText("Success");
    } else {
        ui->label->setText("Fail");
    }

}

void MainWindow::load_number(int num)
{
    ui->lcdNumber->display(num);
    emit number_loaded(num);
}

void MainWindow::add_loaded_num()
{
    if(currentIndex < 4 ){

        ui->lcdNumber->display("");
        ui->lcdNumber->display(nums.at(currentIndex));
        this->sum += nums.at(currentIndex);
        this->currentIndex++;

          qDebug() << this->sum;
    } else{
        timer->stop();
    }



}


void MainWindow::on_pushButton_2_clicked()
{


   timer->start(2000);
   connect(timer, SIGNAL(timeout()),this, SLOT(add_loaded_num()));
//    connect(this,SIGNAL(number_loaded(int)),ui->lcdNumber,SLOT(display(int)));

}

void MainWindow::readNUmsFromFile()
{
    if(file->open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(file);
        while (!stream.atEnd()) {
            this->nums.append(stream.readLine().toInt());
        }
    }
}

void MainWindow::on_radioButton_clicked()
{
    this->file = new QFile( "1.txt");
    readNUmsFromFile();
}

void MainWindow::on_radioButton_2_clicked()
{
    this->file = new QFile( "2.txt");
    readNUmsFromFile();
}

void MainWindow::on_radioButton_3_clicked()
{
    this->file = new QFile( "2.txt");
    readNUmsFromFile();
}
