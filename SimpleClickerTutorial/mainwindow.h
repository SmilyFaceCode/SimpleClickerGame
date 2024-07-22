#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ClickButton_clicked();
    std::string formatNumber(double n);

    void on_Upgrade_clicked();
    void changeColor();


    void on_AutoClick_clicked();
    void AutoClick();
    void on_Auto_Click_Power_Upgrader_Button_clicked();

    void on_Auto_Click_Timer_Upgrader_Button_clicked();




    void on_RebirthButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
