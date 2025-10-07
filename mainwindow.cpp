#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filemodifier.h"
#include <QThread>
#include <QFileDialog>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer(new QTimer(this)),
    workerThread(new QThread(this))
{
    ui->setupUi(this);
    fileModifier.moveToThread(workerThread);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
    connect(&fileModifier, &FileModifier::progressUpdated, ui->progressBar, &QProgressBar::setValue);
    connect(&fileModifier, &FileModifier::statusMessage, ui->statusLabel, &QLabel::setText);
    connect(&fileModifier, &FileModifier::processingFinished, this, &MainWindow::onProcessingFinished);
    connect(ui->selectFilesButton, &QPushButton::clicked, this, &MainWindow::onSelectFilesButtonClicked);
    connect(ui->selectFolderButton, &QPushButton::clicked, this, &MainWindow::onSelectFolderButtonClicked);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimerTimeout);
    connect(workerThread, &QThread::finished, workerThread, &QObject::deleteLater);
    workerThread->start();
}

MainWindow::~MainWindow()
{
    workerThread->quit();
    workerThread->wait();
    delete ui;
}

void MainWindow::onStartButtonClicked()
{
    QStringList files = ui->filesLineEdit->text().split(";");
    QByteArray xorKey = QByteArray::fromHex(ui->xorKeyLineEdit->text().toUtf8());
    QString outputDir = ui->outputDirLineEdit->text();
    bool overwrite = ui->overwriteCheckBox->isChecked();
    bool deleteFiles = ui->deleteFilesCheckBox->isChecked();
    int interval = ui->timerSpinBox->value();

    fileModifier.setParameters(files, xorKey, outputDir, overwrite, deleteFiles);
    QThread *workerThread = new QThread;
    fileModifier.moveToThread(workerThread);

    emit fileModifier.startProcessing();
    if (ui->timerCheckBox->isChecked()) {
        timer->start(interval);
        ui->statusLabel->setText("Работа по таймеру запущена.");
    } else {
        timer->stop();
        ui->statusLabel->setText("Запуск завершен.");
    }
}

void MainWindow::onProcessingFinished()
{
    ui->statusLabel->setText("Обработка завершена.");
}
void MainWindow::onSelectFilesButtonClicked()
{
    QString fileMask = ui->filesLineEdit->text();

    if (fileMask.isEmpty()) {
        fileMask = "*.*";
    }

    QStringList files = QFileDialog::getOpenFileNames(
        this,
        tr("Выберите файлы"),
        "",
        tr("Все файлы (*.*);;%1").arg(fileMask)
        );
    if (!files.isEmpty()) {
        ui->filesLineEdit->setText(files.join(";"));
    }
}

void MainWindow::onSelectFolderButtonClicked()
{
    QString folder = QFileDialog::getExistingDirectory(this, tr("Выберите папку"), "", QFileDialog::ShowDirsOnly);

    if (!folder.isEmpty()) {
        ui->outputDirLineEdit->setText(folder);
    }
}

void MainWindow::onTimerTimeout()
{
    ui->statusLabel->setText("Проверка наличия новых файлов...");
    QStringList files = ui->filesLineEdit->text().split(";");
    QByteArray xorKey = QByteArray::fromHex(ui->xorKeyLineEdit->text().toUtf8());
    QString outputDir = ui->outputDirLineEdit->text();
    bool overwrite = ui->overwriteCheckBox->isChecked();
    bool deleteFiles = ui->deleteFilesCheckBox->isChecked();

    fileModifier.setParameters(files, xorKey, outputDir, overwrite, deleteFiles);

    QThread *workerThread = new QThread;
    fileModifier.moveToThread(workerThread);

    fileModifier.setParameters(files, xorKey, outputDir, overwrite, deleteFiles);

    // Запуск обработки в уже существующем потоке
    emit fileModifier.startProcessing();
}
