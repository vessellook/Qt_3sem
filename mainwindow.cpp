#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../3sem/sorting/heapsort.h"
#include "../3sem/sorting/quicksort.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

