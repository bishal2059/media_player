#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_Video_triggered()
{

}


void MainWindow::on_horizontalSlider_Duration_valueChanged(int value)
{

}


void MainWindow::on_pushButton_pause_play_toggled(bool checked)
{

}


void MainWindow::on_pushButton_stop_clicked()
{

}


void MainWindow::on_pushButton_seek_backward_clicked()
{

}


void MainWindow::on_pushButton_seek_forward_clicked()
{

}


void MainWindow::on_pushButton_volume_clicked()
{

}


void MainWindow::on_horizontalSlider_volume_valueChanged(int value)
{

}

