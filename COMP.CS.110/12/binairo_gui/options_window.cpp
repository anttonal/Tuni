#include "options_window.hh"
#include "ui_options_window.h"

options_window::options_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::options_window)
{
    ui->setupUi(this);
}

options_window::~options_window()
{
    delete ui;
}
