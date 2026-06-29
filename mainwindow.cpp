#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "settings.h"
#include "encriptor.h"
#include "decriptor.h".h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Шифрофщик Морзе");
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getShortSymbol(){return shortSymbol_;}
QString MainWindow::getLongSymbol(){return longSymbol_;}
QString MainWindow::getShortSound(){return shortSound_;}
QString MainWindow::getLongSound(){return longSound_;}
QString MainWindow::getDelimetr(){return delimetr_;}
QString MainWindow::getDelimrtrSound(){return delimetrSound_;}

void MainWindow::setShortSymbol(QString symbol){
    shortSymbol_ = symbol;
}
void MainWindow::setLongSumbol(QString symbol){
    longSymbol_ = symbol;
}
void MainWindow::setShortSound(QString fileName){
    shortSound_ = fileName;
}
void MainWindow::setLongSound(QString fileName){
    longSound_ = fileName;
}
void MainWindow::setDelimetr(QString symbol){
    delimetr_ = symbol;
}
void MainWindow::setDelimetrSound(QString fileName){
    delimetrSound_ = fileName;
}


void MainWindow::on_Settings_button_clicked()
{
    Settings* SettingsWindow = new Settings(this);
    SettingsWindow->show();
    this->close();
}

void MainWindow::on_Coder_button_clicked()
{
    Encriptor* EncriptorWindow = new Encriptor(this);
    EncriptorWindow->show();
    this->close();
}


void MainWindow::on_Decoder_button_clicked()
{
    Decriptor* DecriptorWindow = new Decriptor(this);
    DecriptorWindow->show();
    this->close();
}

