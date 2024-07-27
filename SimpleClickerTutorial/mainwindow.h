#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QString>
#include <QList>
#include <QFile>




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
    MainWindow(Ui::MainWindow *ui);
    ~MainWindow();

private slots:
    void on_ClickButton_clicked();
    std::string formatNumber(double n);

    void on_Upgrade_clicked();
    void changeColor();

    void saveFile(const QString &fileName, const QList<double> &values);
    QList<double> loadFile(const QString &fileName);

    void on_AutoClick_clicked();
    void AutoClick();
    void on_Auto_Click_Power_Upgrader_Button_clicked();

    void on_Auto_Click_Timer_Upgrader_Button_clicked();




    void on_RebirthButton_clicked();



    void on_Upgrading_Limit_Button_clicked();



    void on_ClickButton_pressed();

    void on_ClickButton_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
