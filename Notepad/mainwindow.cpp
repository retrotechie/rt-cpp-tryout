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
 * Open and read a file.
 */
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open file");
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file " + file.errorString());
        return;
    }

    currentFile = fileName;

    setWindowTitle(fileName);

    QTextStream in(&file);  // reading text
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

/*!
 * \brief MainWindow::on_actionSave_As_triggered
 *
 * Save current text to a file.
 */
void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file " + file.errorString());
        return;
    }

    currentFile = fileName;

    setWindowTitle(fileName);

    QTextStream out(&file); // writing text
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

/*!
 * \brief MainWindow::on_actionPrint_triggered
 *
 * Access and configure printer.
 */
void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer name");
    QPrintDialog printerDialog(&printer, this); // Specify the printer's configuration

    if (printerDialog.exec() == QDialog::Rejected) {
        QMessageBox::warning(this, "Warning", "Cannot access printer");
        return;
    }

    ui->textEdit->print(&printer);
}

/*!
 * \brief MainWindow::on_actionExit_triggered
 *
 * Exit.
 */
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

/*!
 * \brief MainWindow::on_actionCopy_triggered
 *
 * Copy.
 */
void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

/*!
 * \brief MainWindow::on_actionPaste_triggered
 *
 * Paste.
 */
void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

