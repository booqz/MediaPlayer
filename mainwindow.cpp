#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    playListModel = new QStandardItemModel(this);
    //TODO: соединить созданную модель с таблицей в окне
    playListModel->setHorizontalHeaderLabels(QStringList()  << tr("Audio Track")        //Заголовки таблицы
                                                                << tr("File Path"));    //
    //TODO: отформатировать таблицу в окне


    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(player);

}


MainWindow::~MainWindow()
{
    delete ui;
    delete playListModel;
    delete playlist;
    delete player;
}
