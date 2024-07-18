#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <iomanip>
// today we gonna learn how to format number from 1000 to 1k and from 1,000,000 to 1m and so on

const double bClicks = 0;
double Clicks = bClicks;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ClickAmount->setText(QString::fromUtf8(formatNumber(Clicks)));
    // now we gonna check if it's working before that we gonna change some functionality
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ClickButton_clicked()
{
// lets try it it's working

    Clicks++;
    // now we gonna change the label value
    ui->ClickAmount->setText(QString::fromUtf8(formatNumber(Clicks)));
}

std::string MainWindow::formatNumber(double n)
{
    std::ostringstream oss;
    // we need some includes for that to manage the strings
    if(n >= 1e9) // n is bigger than 1,000,000,000
        oss << std::fixed << std::setprecision(2) << (n/1e9) << "B";
    else if (n>= 1e6) // if n is bigger than 1,000,000
        oss << std::fixed << std::setprecision(2) << (n/1e6) << "M";
    else if (n >= 1e3) // if n is bigger than 1,000
        oss << std::fixed << std::setprecision(2) << (n/1e3) << "K";
    else
        oss << std::fixed << std::setprecision(2) << n;
    return oss.str();
}


