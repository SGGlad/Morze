#ifndef DECODER_H
#define DECODER_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Decoder;
}

class Decoder : public QDialog
{
    Q_OBJECT

public:
    Decoder(MainWindow* main, QWidget *parent = nullptr);
    ~Decoder();

private slots:
    void on_OriginalText_textChanged();
    void on_FromTXT_clicked();
    void on_DecripteButton_clicked();
    void on_SaveResultTXT_clicked();
    void on_Cancel_clicked();
    void on_Note_clicked(bool checked);

private:
    Ui::Decoder *ui;
    QString originalText = "";
    QString decoderedText = "";
    MainWindow* main_window;

};

#endif // DECODER_H
