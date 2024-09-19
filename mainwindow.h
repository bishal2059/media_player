#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_Video_triggered();

    void on_horizontalSlider_Duration_valueChanged(int value);

    void on_pushButton_pause_play_toggled(bool checked);

    void on_pushButton_stop_clicked();

    void on_pushButton_seek_backward_clicked();

    void on_pushButton_seek_forward_clicked();

    void on_pushButton_volume_clicked();

    void on_horizontalSlider_volume_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *Player;
    QAudioOutput *audioOutput;
    QVideoWidget *Video;
    qint64 nDuration;
    bool Is_Pause = true;
    bool Is_Muted =false;
};

#endif // MAINWINDOW_H
