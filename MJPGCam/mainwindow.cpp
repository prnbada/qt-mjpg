#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QUrl>
#include <QtWebKit>
#include <QtWebKitWidgets/QWebView>

#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    mhLayout1 = new QHBoxLayout;
    mhLayout2 = new QHBoxLayout;

    ui->scrollArea->setLayout(mhLayout1);
    ui->scrollArea->setGeometry(0, 605, 1880, 300);
    //ui->scrollArea->setGeometry(0, 705, 1880, 300);

    ui->scrollArea_2->setLayout(mhLayout2);
    ui->scrollArea_2->setGeometry(850, 0, 500, 600);
    //ui->scrollArea_2->setGeometry(1280, 0, 300, 700);

    QWebView *view = new QWebView(parent);
    mhLayout1->addWidget(view);

    QWebView *view2 = new QWebView(parent);
    mhLayout2->addWidget(view2);

    //view->setUrl(QUrl("http://www.naver.com"));
    view->load(QUrl("http://127.0.0.1/a0910.html"));
    view->show();

    view2->load(QUrl("http://127.0.0.1/b0910.html"));
    view2->show();

    tvform.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
