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

    //настройка таблицы плейлиста
    mPlayListModel = new QStandardItemModel(this);


    ui->mPlayListView->setModel(mPlayListModel);

    ui->mPlayListView->hideColumn(1); //скрываем колонку в которой хранится путь к файлу
    ui->mPlayListView->verticalHeader()->setVisible(false);//скрываем нумерацию строк
    ui->mPlayListView->setSelectionBehavior(QAbstractItemView::SelectRows);//включаем выделение строк
    ui->mPlayListView->setSelectionMode(QAbstractItemView::SingleSelection); //разрешаем выделять только одну строку
    ui->mPlayListView->resizeColumnsToContents();
    ui->mPlayListView->setEditTriggers(QAbstractItemView::NoEditTriggers);//отключаем редактирование



    ui->mPlayListView->horizontalHeader()->setStretchLastSection(true);//подгонка последней видимой колонке по ширине tableView








}

MainWindow::~MainWindow()
{
    delete ui;
    delete mPlayList;
    delete mPlayListModel;

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
        mPlayListModel->appendRow(items);
    }
    mPlayListModel->setHeaderData(0, Qt::Horizontal,"Name");//установим заголовки столбцов
    mPlayListModel->setHeaderData(1, Qt::Horizontal, "Path");
}
