#include "gameboard_window.hh"
#include "ui_gameboard_window.h"

gameboard_window::gameboard_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameboard_window)
{
    ui->setupUi(this);
}

gameboard_window::~gameboard_window()
{
    delete ui;
}
