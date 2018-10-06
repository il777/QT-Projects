#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "dialog.h"

Dialog *dialog;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    dialog= new Dialog();
    connect(ui->action,SIGNAL(triggered(bool)),this,SLOT(showDialog()));

}

void MainWindow::showDialog()
{
    dialog->show();

}

MainWindow::~MainWindow()
{
    delete dialog;
    delete ui;
}


