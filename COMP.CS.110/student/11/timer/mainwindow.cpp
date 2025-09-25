#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(runTheClock()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    if(!startPressed){
        timer->start(1000);
    }
    startPressed=true;
}

void MainWindow::runTheClock()
{
    if(sec<60){
        ++sec;
    }
    else{
        sec=0;
        ++min;
    }
    QString secs= QString::number(sec);
    QString mins= QString::number(min);
    ui->lcdNumberSec->display(secs);
    ui->lcdNumberMin->display(mins);
}

void MainWindow::on_stopButton_clicked()
{
    timer->stop();
    startPressed=false;
}

void MainWindow::on_resetButton_clicked()
{
    on_stopButton_clicked();
    sec=0;
    min=0;
    QString secs= QString::number(sec);
    QString mins= QString::number(min);
    ui->lcdNumberSec->display(secs);
    ui->lcdNumberMin->display(mins);
}
