#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSoundEffect>
#include "mainwindow.h"


namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    Settings(MainWindow* main, QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_ShortSymbol_textEdited(const QString &symbol);
    void on_LongSymbol_textEdited(const QString &symbol);
    void on_Delimetr_textEdited(const QString &symbol);
    void on_DelimetrChar_textEdited(const QString &symbol);
    void on_SetShortSound_clicked();
    void on_SetLongSound_clicked();
    void on_SetDelimetrSound_clicked();
    void on_ShortSound_clicked();
    void on_LongSound_2_clicked();
    void on_DelimetrSound_clicked();
    void on_ApplyButton_clicked();
    void on_CancelButton_clicked();
    void on_SetDelimetrCharSound_clicked();
    void on_DelimetrCharSound_clicked();

private:

    Ui::Settings *ui;
    MainWindow* main_window;
    QString settingShortSymbol_ = ".";
    QString settingLongSymbol_ = "-";
    QString settingDelimetr_ = "/";
    QString settingDelimetrChar_ = " ";
    QString settingDelimetrCharSound_ = "Sourse/Sounds/pause.wav";
    QString settingShortSound_ = "Sourse/Sounds/short.wav";
    QString settingLongSound_ = "Sourse/Sounds/long.wav";
    QString settingDelimetrSound_ = "Sourse/Sounds/pause_btw_words.wav";
    QSoundEffect* shortSound = nullptr;
    QSoundEffect* longSound = nullptr;
    QSoundEffect* delimetrSound = nullptr;
    QSoundEffect* delimetrCharSound = nullptr;

};

#endif // SETTINGS_H
