#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFutureWatcher>
#include "filemodifier.h"
#include <QTimer>

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
    void onStartButtonClicked();
    void onProcessingFinished();
    void onSelectFilesButtonClicked();
    void onSelectFolderButtonClicked();
    void onTimerTimeout();

private:
    Ui::MainWindow *ui;
    FileModifier fileModifier;
    QFutureWatcher<void> watcher;
    QTimer *timer;
    QThread *workerThread;
};

#endif // MAINWINDOW_H
