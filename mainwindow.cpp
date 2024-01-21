#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);



    movie = new QMovie(":/p7.gif");
    movie->start();
    movie->setScaledSize(ui->label_13->size());
    ui->label_13->setMovie(movie);
    ui->label_13->setScaledContents(true);


    this->timer = new QTimer;
    this->timer->start(1000);
    connect(timer, &QTimer::timeout, this, &MainWindow::showTime);

    this->control = new QTimer;
    this->control->start(2000);
    connect(control, &QTimer::timeout, this, &MainWindow::showAirTemp);
    connect(control, &QTimer::timeout, this, &MainWindow::showAirWetness);
    connect(control, &QTimer::timeout, this, &MainWindow::showSoilWetness);
    connect(control, &QTimer::timeout, this, &MainWindow::showPH);
    connect(control, &QTimer::timeout, this, &MainWindow::showSoilFertility);



}
MainWindow::~MainWindow()
{
    movie->stop();
    timer->stop();
    control->stop();

    delete ui;
    delete movie;
    delete timer;
    delete control;
}


void MainWindow::showTime() {

    QDate date = QDate::currentDate();
    ui->label->setText(date.toString("yyyy年MM月dd日 dddd"));

    QTime time = QTime::currentTime();
    ui->lcdNumber->display(time.toString("hh:mm:ss"));
}

void MainWindow::showAirTemp()
{
    double temp[]= {14.9,15.2,15.9,15.4,15.6};
    int num = qrand()%5;
    ui->lcdNumber_2->display(temp[num]);

}

void MainWindow::showAirWetness()
{
    int wetness[] = {52,57,56,58,54};
    int num = qrand()%5;
    ui->lcdNumber_3->display(wetness[num]);
}

void MainWindow::showSoilWetness()
{
  int wetness[] = {71,67,66,68,64};
  int num = qrand()%5;
  ui->lcdNumber_4->display(wetness[num]);
}

void MainWindow::showPH()
{
    float ph[] = {7.5,7.1,7.2,7.3,7.4};
    int num = qrand()%5;
    ui->lcdNumber_5->display(ph[num]);
}

void MainWindow::showSoilFertility()
{
    int N[] = {54,48,45,49,53};
    int P[] = {58,51,53,56,47};
    int K[] = {52,56,58,54,57};

    int num = qrand()%5;
    ui->progressBar_2->setValue(N[num]);
    num = qrand()%5;
    ui->progressBar_3->setValue(P[num]);
    num = qrand()%5;
    ui->progressBar_4->setValue(K[num]);
}


void MainWindow::on_pushButton_2_clicked()
{
    if(dataCount<10)
    {
        ui->tableWidget->insertRow(dataCount);
        ui->tableWidget->setItem(dataCount, 0,new QTableWidgetItem(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss")));
        ui->tableWidget->setItem(dataCount, 1, new QTableWidgetItem(QString::number(ui->lcdNumber_2->value())+"°C"));
        ui->tableWidget->setItem(dataCount, 2, new QTableWidgetItem(QString::number(ui->lcdNumber_3->value())+"%"));
        ui->tableWidget->setItem(dataCount, 3, new QTableWidgetItem(QString::number(ui->lcdNumber_4->value())+"%"));
        ui->tableWidget->setItem(dataCount, 4, new QTableWidgetItem(QString::number(ui->lcdNumber_5->value())));
        ui->tableWidget->setItem(dataCount, 5, new QTableWidgetItem(QString::number(ui->progressBar_2->value())+"%"));
        ui->tableWidget->setItem(dataCount, 6, new QTableWidgetItem(QString::number(ui->progressBar_3->value())+"%"));
        ui->tableWidget->setItem(dataCount, 7, new QTableWidgetItem(QString::number(ui->progressBar_4->value())+"%"));
        dataCount++;

        ui->label_11->setText("记录成功");
    }
    else
    {
        ui->label_11->setText("数据已满,请先清空数据");
    }


}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableWidget->clearContents();
    dataCount =0;
    ui->label_11->setText("清空成功");
}

