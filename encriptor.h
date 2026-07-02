#ifndef ENCRIPTOR_H
#define ENCRIPTOR_H

#include <QDialog>
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

private slots:

    void on_Cancel_clicked();

    void on_OriginalText_textChanged();

    void on_FromTXT_clicked();

    void on_EncodeButton_clicked();

    void on_SaveResultTXT_clicked();

    void on_SetMode_activated(int index);

private:
    Ui::Encriptor *ui;
    MainWindow* main_window;
    QString originalText;
    QString encoderedText;
    morze::Mode mode = morze::Mode::EN;
};

#endif // ENCRIPTOR_H
