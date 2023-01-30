#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->textEdit);   // Select `textEdit` as a central widget
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_actionNew_triggered
 *
 * Refresh and clean up everything.
 */
void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

