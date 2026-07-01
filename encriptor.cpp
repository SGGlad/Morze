#include "encriptor.h"
#include "ui_encriptor.h"


Encriptor::Encriptor(MainWindow* main, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Encriptor), main_window(main)
{
    ui->setupUi(this);
    setWindowTitle("Шифрофщик Морзе");
    ui->EncoderedText->setReadOnly(true);
}

Encriptor::~Encriptor()
{
    delete ui;
}

void Encriptor::on_Cancel_clicked()
{
    this->close();
    main_window->show();
    delete this;
}

void Encriptor::on_OriginalText_textChanged()
{
    originalText = ui->OriginalText->toPlainText();
}

void Encriptor::on_FromTXT_clicked()
{
    try{
        QString filename = QFileDialog::getOpenFileName(this, "Выбор файла", ("*txt"));
        QFile file(filename);
        if(file.open(QIODevice::ReadOnly)){
            originalText = file.readAll();
            ui->OriginalText->setText(originalText);
            file.close();
        }
    }catch(...){}
}

void Encriptor::on_EncodeButton_clicked()
{
    try{
    encoderedText = morze::Encript_from_en(originalText, main_window->getDictionary());
    ui->EncoderedText->setPlainText(encoderedText);
    }catch(...){
        ui->EncoderedText->setText("Не удалось зашифровать");
    }
}


void Encriptor::on_SaveResultTXT_clicked()
{
    try{
        QString filename = QFileDialog::getSaveFileName(this, "Выбор файла", ("result_e.txt"));
        QFile file(filename);
        if(file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate)){
            QTextStream output(&file);
            output<<encoderedText;
            file.close();
        }
    }catch(...){}
}

