#include "mainwindow.h"
#include "ui_mainwindow.h"

const double bClicks = 0;
double Clicks = bClicks;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ClickAmount->setText(QString::number(Clicks));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ClickButton_clicked()
{
// lets try it it's working
// this it today in this video we simple clicker game but we gonna more and more in the future like auto click and
    // more of that how to format the numbers from 1000 to 1k
    Clicks++;
    // now we gonna change the label value
    ui->ClickAmount->setText(QString::number(Clicks));
}

