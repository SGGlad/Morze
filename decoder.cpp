#include "decoder.h"
#include "ui_decoder.h"

Decoder::Decoder(MainWindow* main, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Decoder), main_window(main)
{
    ui->setupUi(this);
    setWindowTitle("Шифрофщик Морзе");
    ui->DecoderedText->setReadOnly(true);
    ui->Note->setCheckable(true);
}

Decoder::~Decoder()
{
    delete ui;
}

void Decoder::on_OriginalText_textChanged()
{
    originalText = ui->OriginalText->toPlainText();
}

void Decoder::on_FromTXT_clicked()
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

void Decoder::on_DecripteButton_clicked()
{
    decoderedText = originalText;
    ui->DecoderedText->setText(decoderedText);
}

void Decoder::on_SaveResultTXT_clicked()
{
    try{
        QString filename = QFileDialog::getSaveFileName(this, "Выбор файла", ("result_d.txt"));
        QFile file(filename);
        if(file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate)){
            QTextStream output(&file);
            output<<decoderedText;
            file.close();
        }
    }catch(...){}
}

void Decoder::on_Cancel_clicked()
{
    main_window->show();
    delete this;
}

void Decoder::on_Note_clicked(bool checked)
{
    if(checked){
        ui->NoteText->setText("Для дешифровки\nнужно использовать\nте же символы, что и \nв зашифрованном\nтексте");
    }else{
        ui->NoteText->setText("");
    }

}

