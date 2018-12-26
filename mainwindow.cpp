#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    playListModel = new QStandardItemModel(this);
    ui->mPlayListView->setModel(mPlayListModel);
     
    playListModel->setHorizontalHeaderLabels(QStringList()  << tr("Audio Track")        //Заголовки таблицы
                                                                << tr("File Path"));    //
    ui->playListModel->hideColumn(1); //скрываем колонку в которой хранится путь к файлу
    ui->playListModel->verticalHeader()->setVisible(false);//скрываем нумерацию строк
    ui->playListModel->setSelectionBehavior(QAbstractItemView::SelectRows);//включаем выделение строк
    ui->playListModel->setSelectionMode(QAbstractItemView::SingleSelection); //разрешаем выделять только одну строку
    ui->playListModel->resizeColumnsToContents();
    ui->playListModel->setEditTriggers(QAbstractItemView::NoEditTriggers);//отключаем редактирование



    ui->playListModel->horizontalHeader()->setStretchLastSection(true);//подгонка последней видимой колонке по ширине tableView


    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(player);

    player->setPlaylist(m_playlist);
    player->setVolume(70);                    // TODO: изменить эту строку при реализации ползунка громкости
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    // TODO: соединить слоты плеера/плейлиста с кнопками интерфейса
    connect(ui->previousButton, QPushButton::clicked, playlist, &QMediaPlaylist::previous);
    connect(, , playlist, &QMediaPlaylist::next);
    connect(ui->playButton, QPushButton::clicked, player, &QMediaPlayer::play);
    connect(, , player, &QMediaPlayer::pause);
    connect(, , player, &QMediaPlayer::stop);
    connect(,,this,&MainWindow::on_btnDlt_clicked);
    //TODO: добавить связи для остальных кнопок
}


MainWindow::~MainWindow()
{
    delete ui;
    delete playListModel;
    delete playlist;
    delete player;
 
}

void MainWindow::on_btnAdd_clicked()
{
    //открываем диалог выбора файла
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      tr("Open files"),
                                                      QString(),
                                                      tr("Audio files (*.mp3)"));

    foreach (QString filePath, files){
        QList<QStandardItem *> items;
        items.append(new QStandardItem(QDir(filePath).dirName()));
        items.append(new QStandardItem(filePath));
        playListModel->appendRow(items);
    }
    playListModel->setHeaderData(0, Qt::Horizontal,"Name");//установим заголовки столбцов
    playListModel->setHeaderData(1, Qt::Horizontal, "Path");
   
}

void MainWindow::on_btnDlt_clicked(){
    playlist->clear();
}

void MainWindow::on_VolumeSlider_sliderMoved(int position)
{
    player->setVolume(position);
}
