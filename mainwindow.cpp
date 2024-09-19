#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer();

    ui->pushButton_pause_play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_seek_backward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_seek_forward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
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

    if(Is_Muted == False){
        Is_Muted =true;
        ui->pushButton_volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        player->setMuted(true);
    }else{
        Is_Muted =false;
        ui->pushButton_volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        player->setMuted(false);
    }
}


void MainWindow::on_horizontalSlider_volume_valueChanged(int value)
{

}

