#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define MINIAUDIO_IMPLEMENTATION
#include <iostream>
#include <fstream>
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include "morze/morze.hpp"
#include <SFML/Audio.hpp>
#include <QTimer>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString getShortSymbol();
    QString getLongSymbol();
    QString getShortSound();
    QString getLongSound();
    QString getDelimetr();
    QString getDelimrtrSound();
    morze::Dictionary getDictionary();

    void setShortSymbol(QString symbol);
    void setLongSumbol(QString symbol);
    void setShortSound(QString fileName);
    void setLongSound(QString fileName);
    void setDelimetr(QString symbol);
    void setDelimetrSound(QString fileName);
    void updateDict();
private slots:
    void on_Settings_button_clicked();

    void on_Coder_button_clicked();

    void on_Decoder_button_clicked();

private:
    Ui::MainWindow *ui;
    QString shortSymbol_ = ".";
    QString longSymbol_ = "-";
    QString delimetr_ = "/";
    QString shortSound_ = "../../Sounds/short.wav";
    QString longSound_ = "../../Sounds/long.wav";
    QString delimetrSound_ = "../../Sounds/pause.wav";
    morze::Dictionary dict;


};
#endif // MAINWINDOW_H
