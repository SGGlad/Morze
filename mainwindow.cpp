#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "settings.h"
#include "encriptor.h"
#include "decriptor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Шифрофщик Морзе");
    dict.Set_dictionary(longSymbol_, shortSymbol_, delimetr_, delimetrChar_);
    settings_window = new Settings(this);
    encriptor_window = new Encriptor(this);
    decriptor_window = new Decriptor(this);
    shortSoundData_ = GetSoundData(shortSound_);
    longSoundData_ = GetSoundData(longSound_);
    delimetrSoundData_ = GetSoundData(delimetrSound_);
    delimetrCharSoundData_ = GetSoundData(delimetrCharSound_);
}

MainWindow::~MainWindow()
{
    delete settings_window;
    delete encriptor_window;
    delete decriptor_window;
    delete ui;
}

QString MainWindow::getShortSymbol(){return shortSymbol_;}
QString MainWindow::getLongSymbol(){return longSymbol_;}
QString MainWindow::getShortSound(){return shortSound_;}
QString MainWindow::getLongSound(){return longSound_;}
QString MainWindow::getDelimetr(){return delimetr_;}
QString MainWindow::getDelimrtrSound(){return delimetrSound_;}
QString MainWindow::getDelimetrCharSymbol(){return delimetrChar_;}
QString MainWindow::getDelimetrCharSound(){return delimetrCharSound_;}
QByteArray& MainWindow::getShortSoundData(){return shortSoundData_;}
QByteArray& MainWindow::getLongSoundData(){return longSoundData_;}
QByteArray& MainWindow::getDelimetrSoundData(){return delimetrSoundData_;}
QByteArray& MainWindow::getDelimetrCharSoundData(){return delimetrCharSoundData_;}
morze::Dictionary MainWindow::getDictionary(){return dict;}

void MainWindow::setShortSymbol(QString& symbol){
    shortSymbol_ = symbol;
}
void MainWindow::setLongSumbol(QString& symbol){
    longSymbol_ = symbol;
}
void MainWindow::setShortSound(QString& fileName){
    shortSound_ = fileName;
}
void MainWindow::setLongSound(QString& fileName){
    longSound_ = fileName;
}
void MainWindow::setDelimetr(QString& symbol){
    delimetr_ = symbol;
}
void MainWindow::setDelimetrSound(QString& fileName){
    delimetrSound_ = fileName;
}
void MainWindow::setDelimetrCharSymbol(QString& symbol){
    delimetrChar_ = symbol;
}
void MainWindow::setDelimetrCharSound(QString& fileName){
    delimetrCharSound_ = fileName;
}
void MainWindow::updateDict(){
    dict.Set_dictionary(longSymbol_, shortSymbol_, delimetr_, delimetrChar_);
}

void MainWindow::setShortSoundData(QString& filename){
    shortSoundData_ = "";
    shortSoundData_ = GetSoundData(filename);

}
void MainWindow::setLongSoundData(QString& filename){
    longSoundData_ = "";
    longSoundData_ = GetSoundData(filename);
}
void MainWindow::setDelimetrSoundData(QString& filename){
    delimetrSoundData_ = "";
    delimetrSoundData_ = GetSoundData(filename);
}
void MainWindow::setDelimetrCharSoundData(QString& filename){
    delimetrCharSoundData_ = "";
    delimetrCharSoundData_ = GetSoundData(filename);
}

void MainWindow::on_Settings_button_clicked()
{
    settings_window->show();
    this->close();
}

void MainWindow::on_Coder_button_clicked()
{

    encriptor_window->show();
    this->close();
}

void MainWindow::on_Decoder_button_clicked()
{
    decriptor_window->show();
    this->close();
}

QByteArray MainWindow::GetSoundData(QString& filename){
    QFile file(filename);
    QByteArray audioData;
    if(file.open(QIODevice::ReadOnly)){
        audioData = file.readAll();
        int pos = audioData.indexOf("data");
        audioData.slice(pos+4);
        return audioData;
    }
}







































