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


private slots:
    void on_btnAdd_clicked();//слот для добавления треков по кнопочке "add"
    void on_btnDlt_clicked();
    void on_btnSort_clicked();
    void on_btnShfl_clicked();

    QStandardItemModel  *playListModel;
    QMediaPlayer        *player;
    QMediaPlaylist      *playlist;
};

#endif // MAINWINDOW_H
