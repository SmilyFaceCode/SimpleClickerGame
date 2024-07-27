/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ClickButton;
    QLabel *Clicks;
    QLabel *ClickAmount;
    QFrame *UpgradeFrame;
    QPushButton *Upgrade;
    QLabel *UpgradePrice;
    QLabel *UpgradeLevel;
    QPushButton *AutoClick;
    QFrame *UpgradeFrame_2;
    QPushButton *Auto_Click_Power_Upgrader_Button;
    QLabel *Auto_Click_Power_Price;
    QLabel *Auto_Click_Power_Level;
    QFrame *Auto_Click_Time_Upgrader_Frame;
    QPushButton *Auto_Click_Timer_Upgrader_Button;
    QLabel *Auto_Click_Timer_Price;
    QLabel *Auto_Click_Timer_Level;
    QFrame *RebirthFrame;
    QPushButton *RebirthButton;
    QLabel *RebirthPrice;
    QLabel *RebirthLevel;
    QPushButton *Upgrading_Limit_Button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);\n"
"background-color: rgb(255, 255, 127);"));
        ClickButton = new QPushButton(centralwidget);
        ClickButton->setObjectName("ClickButton");
        ClickButton->setGeometry(QRect(290, 180, 140, 140));
        QFont font;
        font.setPointSize(16);
        ClickButton->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../ClickerGameIcons/2cursor.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ClickButton->setIcon(icon);
        ClickButton->setIconSize(QSize(140, 140));
        Clicks = new QLabel(centralwidget);
        Clicks->setObjectName("Clicks");
        Clicks->setGeometry(QRect(300, 40, 71, 31));
        Clicks->setFont(font);
        ClickAmount = new QLabel(centralwidget);
        ClickAmount->setObjectName("ClickAmount");
        ClickAmount->setGeometry(QRect(380, 40, 71, 31));
        ClickAmount->setFont(font);
        UpgradeFrame = new QFrame(centralwidget);
        UpgradeFrame->setObjectName("UpgradeFrame");
        UpgradeFrame->setGeometry(QRect(100, 380, 141, 171));
        UpgradeFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 201, 92);"));
        UpgradeFrame->setFrameShape(QFrame::StyledPanel);
        UpgradeFrame->setFrameShadow(QFrame::Raised);
        UpgradeFrame->setLineWidth(1);
        UpgradeFrame->setMidLineWidth(0);
        Upgrade = new QPushButton(UpgradeFrame);
        Upgrade->setObjectName("Upgrade");
        Upgrade->setGeometry(QRect(20, 50, 91, 81));
        Upgrade->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../ClickerGameIcons/up-arrow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Upgrade->setIcon(icon1);
        Upgrade->setIconSize(QSize(55, 55));
        UpgradePrice = new QLabel(UpgradeFrame);
        UpgradePrice->setObjectName("UpgradePrice");
        UpgradePrice->setGeometry(QRect(30, 10, 81, 31));
        UpgradePrice->setFont(font);
        UpgradeLevel = new QLabel(UpgradeFrame);
        UpgradeLevel->setObjectName("UpgradeLevel");
        UpgradeLevel->setGeometry(QRect(30, 130, 71, 31));
        UpgradeLevel->setFont(font);
        AutoClick = new QPushButton(centralwidget);
        AutoClick->setObjectName("AutoClick");
        AutoClick->setGeometry(QRect(650, 220, 80, 81));
        QFont font1;
        font1.setPointSize(8);
        AutoClick->setFont(font1);
        AutoClick->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../ClickerGameIcons/1cursor.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        AutoClick->setIcon(icon2);
        AutoClick->setIconSize(QSize(16, 16));
        UpgradeFrame_2 = new QFrame(centralwidget);
        UpgradeFrame_2->setObjectName("UpgradeFrame_2");
        UpgradeFrame_2->setGeometry(QRect(310, 380, 141, 171));
        UpgradeFrame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 201, 92);"));
        UpgradeFrame_2->setFrameShape(QFrame::StyledPanel);
        UpgradeFrame_2->setFrameShadow(QFrame::Raised);
        Auto_Click_Power_Upgrader_Button = new QPushButton(UpgradeFrame_2);
        Auto_Click_Power_Upgrader_Button->setObjectName("Auto_Click_Power_Upgrader_Button");
        Auto_Click_Power_Upgrader_Button->setGeometry(QRect(20, 50, 91, 81));
        Auto_Click_Power_Upgrader_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../ClickerGameIcons/development.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Auto_Click_Power_Upgrader_Button->setIcon(icon3);
        Auto_Click_Power_Upgrader_Button->setIconSize(QSize(55, 55));
        Auto_Click_Power_Price = new QLabel(UpgradeFrame_2);
        Auto_Click_Power_Price->setObjectName("Auto_Click_Power_Price");
        Auto_Click_Power_Price->setGeometry(QRect(30, 10, 81, 31));
        Auto_Click_Power_Price->setFont(font);
        Auto_Click_Power_Level = new QLabel(UpgradeFrame_2);
        Auto_Click_Power_Level->setObjectName("Auto_Click_Power_Level");
        Auto_Click_Power_Level->setGeometry(QRect(30, 130, 71, 31));
        Auto_Click_Power_Level->setFont(font);
        Auto_Click_Time_Upgrader_Frame = new QFrame(centralwidget);
        Auto_Click_Time_Upgrader_Frame->setObjectName("Auto_Click_Time_Upgrader_Frame");
        Auto_Click_Time_Upgrader_Frame->setGeometry(QRect(510, 380, 141, 171));
        Auto_Click_Time_Upgrader_Frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 201, 92);"));
        Auto_Click_Time_Upgrader_Frame->setFrameShape(QFrame::StyledPanel);
        Auto_Click_Time_Upgrader_Frame->setFrameShadow(QFrame::Raised);
        Auto_Click_Timer_Upgrader_Button = new QPushButton(Auto_Click_Time_Upgrader_Frame);
        Auto_Click_Timer_Upgrader_Button->setObjectName("Auto_Click_Timer_Upgrader_Button");
        Auto_Click_Timer_Upgrader_Button->setGeometry(QRect(20, 50, 91, 81));
        Auto_Click_Timer_Upgrader_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../ClickerGameIcons/time-management.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Auto_Click_Timer_Upgrader_Button->setIcon(icon4);
        Auto_Click_Timer_Upgrader_Button->setIconSize(QSize(55, 55));
        Auto_Click_Timer_Price = new QLabel(Auto_Click_Time_Upgrader_Frame);
        Auto_Click_Timer_Price->setObjectName("Auto_Click_Timer_Price");
        Auto_Click_Timer_Price->setGeometry(QRect(30, 10, 81, 31));
        Auto_Click_Timer_Price->setFont(font);
        Auto_Click_Timer_Level = new QLabel(Auto_Click_Time_Upgrader_Frame);
        Auto_Click_Timer_Level->setObjectName("Auto_Click_Timer_Level");
        Auto_Click_Timer_Level->setGeometry(QRect(30, 130, 71, 31));
        Auto_Click_Timer_Level->setFont(font);
        RebirthFrame = new QFrame(centralwidget);
        RebirthFrame->setObjectName("RebirthFrame");
        RebirthFrame->setGeometry(QRect(10, 150, 141, 171));
        RebirthFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 201, 92);"));
        RebirthFrame->setFrameShape(QFrame::StyledPanel);
        RebirthFrame->setFrameShadow(QFrame::Raised);
        RebirthButton = new QPushButton(RebirthFrame);
        RebirthButton->setObjectName("RebirthButton");
        RebirthButton->setGeometry(QRect(20, 50, 91, 81));
        RebirthButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../ClickerGameIcons/recycle.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        RebirthButton->setIcon(icon5);
        RebirthButton->setIconSize(QSize(32, 32));
        RebirthPrice = new QLabel(RebirthFrame);
        RebirthPrice->setObjectName("RebirthPrice");
        RebirthPrice->setGeometry(QRect(30, 10, 81, 31));
        RebirthPrice->setFont(font);
        RebirthLevel = new QLabel(RebirthFrame);
        RebirthLevel->setObjectName("RebirthLevel");
        RebirthLevel->setGeometry(QRect(30, 130, 71, 31));
        RebirthLevel->setFont(font);
        Upgrading_Limit_Button = new QPushButton(centralwidget);
        Upgrading_Limit_Button->setObjectName("Upgrading_Limit_Button");
        Upgrading_Limit_Button->setGeometry(QRect(670, 20, 80, 81));
        Upgrading_Limit_Button->setFont(font);
        Upgrading_Limit_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        Clicks->raise();
        ClickAmount->raise();
        UpgradeFrame->raise();
        AutoClick->raise();
        UpgradeFrame_2->raise();
        Auto_Click_Time_Upgrader_Frame->raise();
        RebirthFrame->raise();
        Upgrading_Limit_Button->raise();
        ClickButton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ClickButton->setText(QString());
        Clicks->setText(QCoreApplication::translate("MainWindow", "Clicks: ", nullptr));
        ClickAmount->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Upgrade->setText(QString());
        UpgradePrice->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        UpgradeLevel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        AutoClick->setText(QCoreApplication::translate("MainWindow", "AutoClick", nullptr));
        Auto_Click_Power_Upgrader_Button->setText(QString());
        Auto_Click_Power_Price->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Auto_Click_Power_Level->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Auto_Click_Timer_Upgrader_Button->setText(QString());
        Auto_Click_Timer_Price->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Auto_Click_Timer_Level->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        RebirthButton->setText(QCoreApplication::translate("MainWindow", "Rebirth", nullptr));
        RebirthPrice->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        RebirthLevel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Upgrading_Limit_Button->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
