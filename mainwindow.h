#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QMediaPlayList>


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
    QStandardItemModel *mPlayListModel; //модель данных плейлиста для отображения
    QMediaPlaylist     *mPlayList;      //плейлист проигрывателя

private slots:
    void on_btnAdd_clicked();//слот для добавления треков по кнопочке "add"
};

#endif // MAINWINDOW_H
