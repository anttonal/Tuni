#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "gradecalculator.hh"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->spinBoxE->setMaximum(5);
    ui->spinBoxG->setMaximum(120);
    ui->spinBoxN->setMaximum(800);
    ui->spinBoxP->setMaximum(250);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calculatePushButton_clicked()
{
    int w_score = score_from_weekly_exercises(n_points, g_points);
    int p_score = score_from_projects(p_points);

    int total_grade = calculate_total_grade(n_points, g_points, p_points, e_grade);

    QString resultString;
    resultString += QString("W-Score: %1\n").arg(w_score);
    resultString += QString("P-Score: %1\n").arg(p_score);
    resultString += QString("Total grade: %1").arg(total_grade);



    ui->textBrowser->setText(resultString);

}


void MainWindow::on_spinBoxN_valueChanged(int arg1)
{
    n_points = arg1;
}


void MainWindow::on_spinBoxG_valueChanged(int arg1)
{
    g_points = arg1;
}


void MainWindow::on_spinBoxP_valueChanged(int arg1)
{
    p_points = arg1;
}


void MainWindow::on_spinBoxE_valueChanged(int arg1)
{
    e_grade = arg1;
}
