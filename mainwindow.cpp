#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Player = new QMediaPlayer();
    audioOutput = new QAudioOutput();

    Player->setAudioOutput(audioOutput);

    this->setWindowTitle("Media Player");

    ui->pushButton_pause_play->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    ui->pushButton_stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_seek_backward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_seek_forward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    ui->horizontalSlider_volume->setMinimum(0);
    ui->horizontalSlider_volume->setMaximum(100);
    ui->horizontalSlider_volume->setValue(50);

    qreal volume = QAudio::convertVolume(ui->horizontalSlider_volume->value() / qreal(100.0),
                                         QAudio::LogarithmicVolumeScale,
                                         QAudio::LinearVolumeScale);

    audioOutput->setVolume(qRound(volume * 100));

    connect(Player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(Player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);

    ui->horizontalSlider_Duration->setRange(0, Player->duration() / 1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::durationChanged(qint64 duration)
{
    mDuration = duration / 1000;
    ui->horizontalSlider_Duration->setMaximum(mDuration);
}

void MainWindow::positionChanged(qint64 duration)
{

    if (!ui->horizontalSlider_Duration->isSliderDown())
    {

        ui->horizontalSlider_Duration->setValue(duration / 1000);
    }

    updateDuration(duration / 1000);
}

void MainWindow::updateDuration(qint64 Duration)
{
    if (Duration || mDuration)
    {

        QTime CurrentTime((Duration / 3600) % 60, (Duration / 60) % 60, Duration % 60, (Duration * 1000) % 1000);
        QTime totalTime((mDuration / 3600) % 60, (mDuration / 60) % 60, mDuration % 60, (mDuration * 1000) % 1000);
        QString Format = "";
        if (mDuration > 3600)
        {
            Format = "hh:mm:ss";
        }
        else
        {
            Format = "mm:ss";
        }

        ui->label_current_time->setText(CurrentTime.toString(Format));
        ui->label_total_time->setText(totalTime.toString(Format));
    }
}

void MainWindow::on_actionOpen_Video_triggered()
{

    QString FileName = QFileDialog::getOpenFileName(this, tr("Open Video File"), "", tr("MP4 Files (*.mp4)"));

    Video = new QVideoWidget();

    Video->setGeometry(10, 10, ui->groupBox_Video->width() - 20, ui->groupBox_Video->height() - 20);

    Video->setParent(ui->groupBox_Video);

    Player->setVideoOutput(Video);

    Player->setSource(QUrl(FileName));
    Video->setVisible(true);
    Video->show();
    Player->play();

    VideoFileFound = true;
}

void MainWindow::on_horizontalSlider_Duration_valueChanged(int value)
{
    Player->setPosition(value * 1000);
}

void MainWindow::on_pushButton_pause_play_clicked()
{
    if (VideoFileFound)
    {

        if (Is_Pause == true)
        {
            Player->play();
            Is_Pause = false;
            ui->pushButton_pause_play->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        }
        else
        {
            Player->pause();
            Is_Pause = true;
            ui->pushButton_pause_play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        }
    }
}

void MainWindow::on_pushButton_stop_clicked()
{

    if (VideoFileFound)
    {
        Player->stop();
    }
}

void MainWindow::on_pushButton_seek_backward_clicked()
{
    if (VideoFileFound)
    {
        ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value() - 5);
        Player->setPosition(ui->horizontalSlider_Duration->value() * 1000);
    }
}

void MainWindow::on_pushButton_seek_forward_clicked()
{
    if (VideoFileFound)
    {
        ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value() + 5);
        Player->setPosition(ui->horizontalSlider_Duration->value() * 1000);
    }
}

void MainWindow::on_pushButton_volume_clicked()
{
    // For qt version less than 6 setMuted func exist in Player.
    if (VideoFileFound)
    {

        if (Is_Muted == false)
        {
            Is_Muted = true;
            ui->pushButton_volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
            audioOutput->setMuted(true);
        }
        else
        {
            Is_Muted = false;
            ui->pushButton_volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
            audioOutput->setMuted(false);
        }
    }
}

void MainWindow::on_horizontalSlider_volume_valueChanged(int value)
{
    // For Qt version less than 6 setVlomue func exist.
    //  volume = value;
    //  audioOutput->setVolume(volume);

    qreal volume = QAudio::convertVolume(value / qreal(100.0),
                                         QAudio::LogarithmicVolumeScale,
                                         QAudio::LinearVolumeScale);

    audioOutput->setVolume(qRound(volume * 100));
}
