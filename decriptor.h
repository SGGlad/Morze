#ifndef DECRIPTOR_H
#define DECRIPTOR_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class Decriptor;
}

class Decriptor : public QDialog
{
    Q_OBJECT

public:
    explicit Decriptor(MainWindow* main, QWidget *parent = nullptr);
    ~Decriptor();

private slots:
    void on_EncriptedText_textChanged();
    void on_FromTXT_clicked();
    void on_DecripteButton_clicked();
    void on_SaveResultTXT_clicked();
    void on_Cancel_clicked();
    void on_Note_clicked(bool checked);

private:
    Ui::Decriptor *ui;
    QString encriptedText = "";
    QString decriptedText = "";
    MainWindow* main_window;


};

#endif // DECRIPTOR_H
