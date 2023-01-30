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

/*!
 * \brief MainWindow::on_actionNew_triggered
 *
 * Refresh and clean up everything.
 */
void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
    setWindowTitle("*New");
}

/*!
 * \brief MainWindow::on_actionOpen_triggered
 *
 * Open and read file.
 */
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open file");
    QFile file(fileName);
    currentFile = fileName;

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file " + file.errorString());
    }

    setWindowTitle(fileName);

    QTextStream in(&file);  // reading text
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

