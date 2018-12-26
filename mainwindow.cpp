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

    player->setPlaylist(m_playlist);
    player->setVolume(70);                    // TODO: изменить эту строку при реализации ползунка громкости
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    // TODO: соединить слоты плеера/плейлиста с кнопками интерфейса
    connect(, , playlist, &QMediaPlaylist::previous);
    connect(, , playlist, &QMediaPlaylist::next);
    connect(, , player, &QMediaPlayer::play);
    connect(, , player, &QMediaPlayer::pause);
    connect(, , player, &QMediaPlayer::stop);

    //TODO: добавить связи для остальных кнопок
}


MainWindow::~MainWindow()
{
    delete ui;
    delete playListModel;
    delete playlist;
    delete player;
}
