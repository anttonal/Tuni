#include "victory_window.hh"
#include "ui_victory_window.h"

victory_window::victory_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::victory_window)
{
    ui->setupUi(this);
}

victory_window::~victory_window()
{
    delete ui;
}
