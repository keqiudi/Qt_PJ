#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int dataCount=0;

    QMovie* movie;
    QTimer* timer;
    QTimer* control;


signals:

private slots:
    void showTime();

    void showAirTemp();
    void showAirWetness();
    void showSoilWetness();
    void showPH();
    void showSoilFertility();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

};
#endif // MAINWINDOW_H
