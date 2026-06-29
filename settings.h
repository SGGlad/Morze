#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
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
    void on_SetShortSound_clicked();
    void on_SetLongSound_clicked();
    void on_SetDelimetrSound_clicked();
    void on_ShortSound_clicked(bool checked);
    void on_LongSound_2_clicked(bool checked);
    void on_DelimetrSound_clicked(bool checked);
    void on_ApplyButton_clicked();
    void on_CancelButton_clicked();

private:

    Ui::Settings *ui;
    MainWindow* main_window;
    QString settingShortSymbol_ = ".";
    QString settingLongSymbol_ = "-";
    QString settingDelimetr_ = "/";
    QString settingShortSound_ = "short.wav";
    QString settingLongSound_ = "long.wav";
    QString settingDelimetrSound_ = "pause.wav";

};

#endif // SETTINGS_H
