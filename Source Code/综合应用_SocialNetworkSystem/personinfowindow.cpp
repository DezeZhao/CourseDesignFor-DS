#include "personinfowindow.h"
#include "ui_personinfowindow.h"

PersonInfoWindow::PersonInfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PersonInfoWindow)
{
    ui->setupUi(this);
}

PersonInfoWindow::~PersonInfoWindow()
{
    delete ui;
}
