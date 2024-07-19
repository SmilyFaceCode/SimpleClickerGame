#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <QTimer>

const double bClicks = 0;
// first we need to add the variables to upgrader level, price and power
const double bperClick = 1;
const double bupgradePrice = 5;
const double bupgradeLevel = 1;

double perClick = bperClick;
double upgradePrice = bupgradePrice;
double upgradeLevel = bupgradeLevel;


double Clicks = bClicks;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // let's check if it's working we forgot to change perclick value
    ui->ClickAmount->setText(QString::fromUtf8(formatNumber(Clicks)));
    ui->UpgradeLevel->setText(QString::fromUtf8(formatNumber(upgradeLevel)));
    ui->UpgradePrice->setText(QString::fromUtf8(formatNumber(upgradePrice)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ClickButton_clicked()
{


    Clicks += perClick;

    ui->ClickAmount->setText(QString::fromUtf8(formatNumber(Clicks)));
}

std::string MainWindow::formatNumber(double n)
{
    std::ostringstream oss;

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





void MainWindow::on_Upgrade_clicked()
{
    if(Clicks >= upgradePrice)
    {
        Clicks -= upgradePrice;
        upgradePrice++;
        upgradeLevel++;
        perClick++;
        ui->ClickAmount->setText(QString::fromUtf8(formatNumber(Clicks)));
        ui->UpgradeLevel->setText(QString::fromUtf8(formatNumber(upgradeLevel)));
        ui->UpgradePrice->setText(QString::fromUtf8(formatNumber(upgradePrice)));
        ui->Upgrade->setStyleSheet("background-color: rgb(0, 255, 0)");
    }
    else
    {
        ui->Upgrade->setStyleSheet("background-color: rgb(255, 0, 0)");
    }
    QTimer::singleShot(200,this,&MainWindow::changeColor);
}

void MainWindow::changeColor()
{
    ui->Upgrade->setStyleSheet("");
}
// This is our video today have a good day
