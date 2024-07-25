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


const int bUpgrading_Limit = 1;
const int bUpgrading_Limit_Level = 1;

int Upgrading_Limit = bUpgrading_Limit;
int Upgrading_Limit_Level = bUpgrading_Limit_Level;




bool is_Auto_Click_Active = false;



double Clicks = bClicks;


QTimer *timer = new QTimer;

QString file = "Values.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadFile(file);
    ui->ClickAmount->setText(QString::fromUtf8(formatNumber(Clicks)));
    ui->UpgradeLevel->setText(QString::fromUtf8(formatNumber(upgradeLevel)));
    ui->UpgradePrice->setText(QString::fromUtf8(formatNumber(upgradePrice)));

    ui->Auto_Click_Timer_Price->setText(QString::fromUtf8(formatNumber(Auto_Click_Speed_Price)));
    ui->Auto_Click_Timer_Level->setText(QString::fromUtf8(formatNumber(Auto_Click_Speed_Level)));
    ui->Auto_Click_Power_Level->setText(QString::fromUtf8(formatNumber(Auto_Click_Level)));
    ui->Auto_Click_Power_Price->setText(QString::fromUtf8(formatNumber(Auto_Click_Power_Price)));

    ui->RebirthPrice->setText(QString::fromUtf8(formatNumber(Rebirth_Price)));
    ui->RebirthLevel->setText(QString::fromUtf8(formatNumber(Rebirth_Level)));

    ui->Upgrading_Limit_Button->setText(QString::number(Upgrading_Limit));


    connect(timer, SIGNAL(timeout()), this, SLOT(AutoClick()));
    timer->setInterval(Auto_Click_Speed);
    timer->start();

}

MainWindow::~MainWindow()
{
    QList<double> values = {Clicks,perClick,Rebirth_Level,upgradeLevel,upgradePrice,
                             Auto_Click_Level,Auto_Click_Power,Auto_Click_Power_Price,
                            Auto_Click_Speed_Level,Auto_Click_Speed_Price,(double)Auto_Click_Speed,
                            (double)Upgrading_Limit_Level,(double)Upgrading_Limit, Rebirth_Price};
    saveFile(file,values);
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
    if(Clicks < upgradePrice)
    {
        ui->Upgrade->setStyleSheet("Background-color: Red");
    }
    for(int i = 0; i < Upgrading_Limit; i++)
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
            break;
        }
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






void MainWindow::saveFile(const QString &fileName, const QList<double> &values)
{
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly| QIODevice::Text))
    {
        QTextStream out (&file);

        for(double value : values)
        {
            out << QString::number(value, 'f', 6) << "\n";
        }
        file.close();
    }
    else
    {
        qWarning() << "SAVE_FILE FAILED TO LOAD" << file.errorString();
    }

}

QList<double> MainWindow::loadFile(const QString &fileName)
{
    QList<double> values;
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly| QIODevice:: Text))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            bool ok;
            double value  = line.toDouble(&ok);
            if(ok)
            {
                values.append(value);
            }
        }

        Clicks = values[0];
        perClick = values[1];
        Rebirth_Level = values[2];
        upgradeLevel = values[3];
        upgradePrice = values[4];
        Auto_Click_Level = values[5];
        Auto_Click_Power = values[6];
        Auto_Click_Power_Price = values[7];
        Auto_Click_Speed_Level = values[8];
        Auto_Click_Speed_Price = values[9];
        Auto_Click_Speed = (int)values[10];
        Upgrading_Limit_Level = (int)values[11];
        Upgrading_Limit = (int)values[12];
        Rebirth_Price = values[13];
        file.close();
    }
    else
    {
        qWarning() << "LOAD_FILE FAILED TO LOAD" << file.errorString();
    }
    return values;
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
    if(Auto_Click_Power_Price > Clicks)
    {
        ui->Auto_Click_Power_Upgrader_Button->setStyleSheet("Background-color: Red");
    }
    for(int i = 0; i < Upgrading_Limit; i++)
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
            break;
        }
    }

    QTimer::singleShot(200,this,&MainWindow::changeColor);

}


void MainWindow::on_Auto_Click_Timer_Upgrader_Button_clicked()
{
    if(Auto_Click_Speed_Price > Clicks)
    {
        ui->Auto_Click_Timer_Upgrader_Button->setStyleSheet("Background-color: Red");
    }
    for(int i = 0; i < Upgrading_Limit; i++)
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
            break;
        }

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





void MainWindow::on_Upgrading_Limit_Button_clicked()
{
    Upgrading_Limit_Level++;
    if(Upgrading_Limit_Level > 4)
    {
        Upgrading_Limit_Level = 1;
    }

    switch (Upgrading_Limit_Level) {
    case 1:
        Upgrading_Limit = 1;
        break;
    case 2:
        Upgrading_Limit = 10;
        break;
    case 3:
        Upgrading_Limit = 100;
        break;
    case 4:
        Upgrading_Limit = 1000;
        break;
    default:
        Upgrading_Limit = 1;
        break;
    }
    ui->Upgrading_Limit_Button->setText(QString::number(Upgrading_Limit));
}




