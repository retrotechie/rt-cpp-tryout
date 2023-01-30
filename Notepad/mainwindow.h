#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>        // Interface for reading from and writing to files
#include <QFileDialog>  // Dialog interface to select files or directories
#include <QTextStream>  // Interface for reading and writing text
#include <QMessageBox>  // Dialog to ask questions and get answers
#include <QPrinter>
#include <QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;

    QString currentFile = "";
};
#endif // MAINWINDOW_H
