#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Player = new QMediaPlayer();

    ui->pushButton_pause_play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_seek_backward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_seek_forward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    ui->horizontalSlider_volume->setMinimum(0);
    ui->horizontalSlider_volume->setMaximum(100);
    ui->horizontalSlider_volume->setValue(30);

    Player->setVolume(ui->horizontalSlider_volume->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_Video_triggered()
{

    QString FileName = QFileDialog::getOpenFileName(this, tr("Open Video") , "" , tr("MP4 Files (.mp4)"));

    Video = new QVideoWidget();

    Video->setGeometry(10,10,ui->groupBox_Video->width() - 20, ui->groupBox_Video->height() -20 );

    Video->setParent(ui->groupBox_Video);

    Player->setVideoOutput(Video);

    Player->setMedia(QUrl(FileName));

    Video->setVisible(true);
    Video->show();
}


void MainWindow::on_horizontalSlider_Duration_valueChanged(int value)
{
     Player->setPosition(value * 1000);
}


void MainWindow::on_pushButton_pause_play_toggled(bool checked)
{

    if(Is_Pause == true){
        Player->play();
        Is_Pause = false;
        ui->pushButton_pause_play->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

    }else{
        Player->pause();
        Is_Pause = true;
        ui->pushButton_pause_play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }

}


void MainWindow::on_pushButton_stop_clicked()
{

    Player->stop();

}


void MainWindow::on_pushButton_seek_backward_clicked()
{
    ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value() -20);
    Player->setPosition(ui->horizontalSlider_Duration->value() * 1000);

}


void MainWindow::on_pushButton_seek_forward_clicked()
{

      ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value() + 20);

}


void MainWindow::on_pushButton_volume_clicked()
{

    if(Is_Muted == False){
        Is_Muted =true;
        ui->pushButton_volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        Player->setMuted(true);
    }else{
        Is_Muted =false;
        ui->pushButton_volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        Player->setMuted(false);
    }
}


void MainWindow::on_horizontalSlider_volume_valueChanged(int value)
{

    Player->setVolume(value);
}

