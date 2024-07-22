#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <QTimer>

const double bClicks = 0;

const double bperClick = 1;
const double bupgradePrice = 5;
const double bupgradeLevel = 1;

double perClick = bperClick;
double upgradePrice = bupgradePrice;
double upgradeLevel = bupgradeLevel;


const double bAuto_Click_Power = 1;
const double bAuto_Click_Level = 1;
const int  bAuto_Click_Speed = 1000;

double Auto_Click_Power = bAuto_Click_Power;
double Auto_Click_Level = bAuto_Click_Level;
int    Auto_Click_Speed = bAuto_Click_Speed;




const double bAuto_Click_Speed_Level = 1;
const double bAuto_Click_Speed_Price = 500;
const double bAuto_Click_Power_Price = 10;

double Auto_Click_Speed_Level = bAuto_Click_Speed_Level;
double Auto_Click_Speed_Price = bAuto_Click_Speed_Price;
double Auto_Click_Power_Price = bAuto_Click_Power_Price;


const double bRebirth_Price = 1*1e3;
const double bRebirth_Level = 1;

double Rebirth_Price = bRebirth_Price;
double Rebirth_Level = bRebirth_Level;





bool is_Auto_Click_Active = false;



double Clicks = bClicks;


QTimer *timer = new QTimer;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->ClickAmount->setText(QString::fromUtf8(formatNumber(Clicks)));
    ui->UpgradeLevel->setText(QString::fromUtf8(formatNumber(upgradeLevel)));
    ui->UpgradePrice->setText(QString::fromUtf8(formatNumber(upgradePrice)));

    ui->Auto_Click_Timer_Price->setText(QString::fromUtf8(formatNumber(Auto_Click_Speed_Price)));
    ui->Auto_Click_Timer_Level->setText(QString::fromUtf8(formatNumber(Auto_Click_Speed_Level)));
    ui->Auto_Click_Power_Level->setText(QString::fromUtf8(formatNumber(Auto_Click_Level)));
    ui->Auto_Click_Power_Price->setText(QString::fromUtf8(formatNumber(Auto_Click_Power_Price)));

    ui->RebirthPrice->setText(QString::fromUtf8(formatNumber(Rebirth_Price)));
    ui->RebirthLevel->setText(QString::fromUtf8(formatNumber(Rebirth_Level)));

    connect(timer, SIGNAL(timeout()), this, SLOT(AutoClick()));
    timer->setInterval(Auto_Click_Speed);
    timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ClickButton_clicked()
{


    Clicks += perClick * Rebirth_Level;

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
    ui->Auto_Click_Timer_Upgrader_Button->setStyleSheet("");
    ui->Auto_Click_Power_Upgrader_Button->setStyleSheet("");
    ui->RebirthButton->setStyleSheet("");
}







void MainWindow::on_AutoClick_clicked()
{
    if(!is_Auto_Click_Active)
    {
        is_Auto_Click_Active = true;
        ui->AutoClick->setStyleSheet("background-color: rgb(0,255,0)");
    }
    else
    {
        is_Auto_Click_Active = false;
        ui->AutoClick->setStyleSheet("");
    }
}

void MainWindow::AutoClick()
{
    if(is_Auto_Click_Active)
    {
        Clicks += Auto_Click_Power * Rebirth_Level;
        ui->ClickAmount->setText(QString::fromUtf8(formatNumber(Clicks)));
    }
}


void MainWindow::on_Auto_Click_Power_Upgrader_Button_clicked()
{
    if(Auto_Click_Power_Price <= Clicks)
    {
        Clicks -= Auto_Click_Power_Price;
        Auto_Click_Power_Price += bAuto_Click_Power_Price;
        Auto_Click_Power++;
        Auto_Click_Level++;
        ui->Auto_Click_Power_Level->setText(QString::fromUtf8(formatNumber(Auto_Click_Level)));
        ui->Auto_Click_Power_Price->setText(QString::fromUtf8(formatNumber(Auto_Click_Power_Price)));
        ui->ClickAmount->setText(QString::fromUtf8(formatNumber(Clicks)));
        ui->Auto_Click_Power_Upgrader_Button->setStyleSheet("Background-color: Green");
    }
    else
    {
        ui->Auto_Click_Power_Upgrader_Button->setStyleSheet("Background-color: Red");
    }
    QTimer::singleShot(200,this,&MainWindow::changeColor);

}


void MainWindow::on_Auto_Click_Timer_Upgrader_Button_clicked()
{

    if(Auto_Click_Speed_Price <= Clicks && Auto_Click_Speed > 2)
    {
        Clicks -= Auto_Click_Speed_Price;
        Auto_Click_Speed -=20;
        Auto_Click_Speed_Level++;
        Auto_Click_Speed_Price *= 1.5;
        ui->Auto_Click_Timer_Price->setText(QString::fromUtf8(formatNumber(Auto_Click_Speed_Price)));
        ui->Auto_Click_Timer_Level->setText(QString::fromUtf8(formatNumber(Auto_Click_Speed_Level)));
        ui->ClickAmount->setText(QString::fromUtf8(formatNumber(Clicks)));
        ui->Auto_Click_Timer_Upgrader_Button->setStyleSheet("Background-color: Green");

    }
    else
    {
        ui->Auto_Click_Timer_Upgrader_Button->setStyleSheet("Background-color: Red");
    }
    if(Auto_Click_Speed <= 2)
    {
        Auto_Click_Speed = 2;
        ui->Auto_Click_Timer_Upgrader_Button->setStyleSheet("Background-color: Yellow");
    }
    timer->setInterval(Auto_Click_Speed);
    QTimer::singleShot(200,this,&MainWindow::changeColor);
}








void MainWindow::on_RebirthButton_clicked()
{
    if(Rebirth_Price <= Clicks)
    {
        Clicks = bClicks;
        Rebirth_Price += bRebirth_Price;
        Rebirth_Level++;

        Auto_Click_Speed_Level = bAuto_Click_Speed_Level;
        Auto_Click_Speed_Price = bAuto_Click_Speed_Price;
        Auto_Click_Power_Price = bAuto_Click_Power_Price;

        perClick = bperClick;
        upgradePrice = bupgradePrice;
        upgradeLevel = bupgradeLevel;

        Auto_Click_Power = bAuto_Click_Power;
        Auto_Click_Level = bAuto_Click_Level;
        Auto_Click_Speed = bAuto_Click_Speed;

        ui->ClickAmount->setText(QString::fromUtf8(formatNumber(Clicks)));
        ui->UpgradeLevel->setText(QString::fromUtf8(formatNumber(upgradeLevel)));
        ui->UpgradePrice->setText(QString::fromUtf8(formatNumber(upgradePrice)));

        ui->Auto_Click_Timer_Price->setText(QString::fromUtf8(formatNumber(Auto_Click_Speed_Price)));
        ui->Auto_Click_Timer_Level->setText(QString::fromUtf8(formatNumber(Auto_Click_Speed_Level)));
        ui->Auto_Click_Power_Level->setText(QString::fromUtf8(formatNumber(Auto_Click_Level)));
        ui->Auto_Click_Power_Price->setText(QString::fromUtf8(formatNumber(Auto_Click_Power_Price)));

        ui->RebirthPrice->setText(QString::fromUtf8(formatNumber(Rebirth_Price)));
        ui->RebirthLevel->setText(QString::fromUtf8(formatNumber(Rebirth_Level)));

        ui->RebirthButton->setStyleSheet("Background-color: Green");
    }
    else
    {
        ui->RebirthButton->setStyleSheet("Background-color: Red");
    }
    QTimer::singleShot(200,this,&MainWindow::changeColor);
}

