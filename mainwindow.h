#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QStandardItemModel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    QStandardItemModel  *playListModel;
    QMediaPlayer        *player;
    QMediaPlaylist      *playlist;

private slots:
    void on_btnAdd_clicked();//слот для добавления треков по кнопочке "add"
    void on_btnDlt_clicked();
    void on_btnSort_clicked();
    void on_btnShfl_clicked();


    void on_VolumeSlider_sliderMoved(int position);
};

#endif // MAINWINDOW_H
