#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <tvform.h>

class QVBoxLayout;
class QHBoxLayout;

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

    QHBoxLayout *mhLayout1;
    QHBoxLayout *mhLayout2;
    TvForm tvform;
};

#endif // MAINWINDOW_H
