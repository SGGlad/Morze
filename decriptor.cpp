#include "decriptor.h"
#include "ui_decriptor.h"

Decriptor::Decriptor(MainWindow* main, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Decriptor), main_window(main)
{
    ui->setupUi(this);
    setWindowTitle("Шифрофщик Морзе");
    ui->DecriptedText->setReadOnly(true);
    ui->Note->setCheckable(true);
}

Decriptor::~Decriptor()
{
    delete ui;
}

void Decriptor::on_EncriptedText_textChanged()
{
    encriptedText = ui->EncriptedText->toPlainText();
}

void Decriptor::on_FromTXT_clicked()
{
    try{
        QString filename = QFileDialog::getOpenFileName(this, "Выбор файла", ("*txt"));
        QFile file(filename);
        if(file.open(QIODevice::ReadOnly)){
            encriptedText = file.readAll();
            ui->EncriptedText->setText(encriptedText);
            file.close();
        }
    }catch(...){}
}

void Decriptor::on_DecripteButton_clicked()
{
    try{
        decriptedText = morze::Decript_to_en(encriptedText, main_window->getDictionary());
        ui->DecriptedText->setText(decriptedText);
    }catch(QString massenge){
        ui->DecriptedText->setText(massenge);
    }
}

void Decriptor::on_SaveResultTXT_clicked()
{
    try{
        QString filename = QFileDialog::getSaveFileName(this, "Выбор файла", ("result_d.txt"));
        QFile file(filename);
        if(file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate)){
            QTextStream output(&file);
            output<<decriptedText;
            file.close();
        }
    }catch(...){}
}

void Decriptor::on_Cancel_clicked()
{
    main_window->show();
    delete this;
}

void Decriptor::on_Note_clicked(bool checked)
{
    if(checked){
        ui->NoteText->setText("Для дешифровки\nнужно использовать\nте же символы, что и \nв зашифрованном\nтексте");
    }else{
        ui->NoteText->setText("");
    }
}
