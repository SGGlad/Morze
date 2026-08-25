#ifndef ENCRIPTOR_H
#define ENCRIPTOR_H

#include <QDialog>
#include <QSoundEffect>
#include <QMediaPlayer>
#include "mainwindow.h"


namespace Ui {
class Encriptor;
}

class Encriptor : public QDialog
{
    Q_OBJECT

public:
    Encriptor(MainWindow* main, QWidget *parent = nullptr);
    ~Encriptor();
    MainWindow* main_window;
    QString& getEncoderedText();
    void Update(QString shortS, QString longS, QString delS, QString delCharS);

private slots:
    void on_Cancel_clicked();
    void on_OriginalText_textChanged();
    void on_FromTXT_clicked();
    void on_EncodeButton_clicked();
    void on_SaveResultTXT_clicked();
    void on_SetMode_activated(int index);
    void on_Play_clicked(bool checked);

    void on_SaveResultWAV_clicked();

private:
    Ui::Encriptor *ui;
    QString originalText;
    QString encoderedText;
    morze::Mode mode = morze::Mode::EN;
    bool needPlay;
    QMediaPlayer* player = nullptr;
    QMediaPlayer* player2 = nullptr;
    QMediaPlayer* player3 = nullptr;
    QMediaPlayer* player4 = nullptr;
    QSoundEffect* shortSound = nullptr;
    QSoundEffect* longSound = nullptr;
    QSoundEffect* delimetrSound = nullptr;
    QSoundEffect* delimetrCharSound = nullptr;
    size_t shortSoundDuration;
    size_t longSoundDuration;
    size_t delimetrSoundDuration;
    size_t delimetrCharSoundDuration;
    bool isPlayClickedFirstTime = true;
    void PlaySound();
    void WriteWav();
};

#endif // ENCRIPTOR_H
