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
    ui->mPlayListView->setModel(playListModel);
     
    playListModel->setHorizontalHeaderLabels(QStringList()  << tr("Audio Track")        //Заголовки таблицы
                                                                << tr("File Path"));    //
    ui->mPlayListView->hideColumn(1); //скрываем колонку в которой хранится путь к файлу
    ui->mPlayListView->verticalHeader()->setVisible(false);//скрываем нумерацию строк
    ui->mPlayListView->setSelectionBehavior(QAbstractItemView::SelectRows);//включаем выделение строк
    ui->mPlayListView->setSelectionMode(QAbstractItemView::SingleSelection); //разрешаем выделять только одну строку
    ui->mPlayListView->resizeColumnsToContents();
    ui->mPlayListView->setEditTriggers(QAbstractItemView::NoEditTriggers);//отключаем редактирование



    ui->mPlayListView->horizontalHeader()->setStretchLastSection(true);//подгонка последней видимой колонке по ширине tableView


    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(player);

    player->setPlaylist(playlist);
    player->setVolume(70);                    // TODO: изменить эту строку при реализации ползунка громкости
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    // TODO: соединить слоты плеера/плейлиста с кнопками интерфейса
    connect(ui->previousButton, QPushButton::clicked, playlist, &QMediaPlaylist::previous);

    connect(ui->previousButton_2, QPushButton::clicked, playlist, &QMediaPlaylist::next);
    connect(ui->playButton,  QPushButton::clicked, player, &QMediaPlayer::play);
    connect(ui->playButton_2, QPushButton::clicked , player, &QMediaPlayer::pause);
    connect(ui->playButton_3,QPushButton::clicked , player, &QMediaPlayer::stop);
    connect(ui->dltBut,QPushButton::clicked,this,&MainWindow::on_btnDlt_clicked);
    connect(ui->btnSort,QPushButton::clicked,this,&MainWindow::on_btnSort_clicked);
    connect(ui->btnSort_2,QPushButton::clicked,this,&MainWindow::on_btnShfl_clicked);

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
    playListModel->clear();
}

void MainWindow::on_btnSort_clicked(){
    playListModel->sort(1);
}

void MainWindow::on_btnShfl_clicked(){
    playlist->shuffle();
    playListModel->clear();
    on_btnAdd_clicked();
}

void MainWindow::on_VolumeSlider_sliderMoved(int position)
{
    player->setVolume(position);
}
