#include <thread>
#include <chrono>
#include "encriptor.h"
#include "ui_encriptor.h"
#include <QAudioOutput>
#include <fstream>


Encriptor::Encriptor(MainWindow* main, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Encriptor), main_window(main)
{
    ui->setupUi(this);
    setWindowTitle("Шифрофщик Морзе");
    ui->EncoderedText->setReadOnly(true);
    ui->Play->setCheckable(true);
    shortSound = new QSoundEffect;
    player = new QMediaPlayer;
    shortSound->setSource(QUrl::fromLocalFile(main_window->getShortSound()));
    player->setSource(QUrl::fromLocalFile(main_window->getShortSound()));
    longSound = new QSoundEffect;
    player2 = new QMediaPlayer;
    longSound->setSource(QUrl::fromLocalFile(main_window->getLongSound()));
    player2->setSource(QUrl::fromLocalFile(main_window->getLongSound()));
    delimetrSound = new QSoundEffect;
    player3 = new QMediaPlayer;
    delimetrSound->setSource(QUrl::fromLocalFile(main_window->getDelimrtrSound()));
    player3->setSource(QUrl::fromLocalFile(main_window->getDelimrtrSound()));
    delimetrCharSound = new QSoundEffect;
    player4 = new QMediaPlayer;
    delimetrCharSound->setSource(QUrl::fromLocalFile(main_window->getDelimetrCharSound()));
    player4->setSource(QUrl::fromLocalFile(main_window->getDelimetrCharSound()));
}

Encriptor::~Encriptor()
{
    delete shortSound;
    delete longSound;
    delete delimetrSound;
    delete delimetrCharSound;
    delete player;
    delete player2;
    delete player3;
    delete player4;
    delete ui;
}

QString& Encriptor::getEncoderedText(){
    return encoderedText;
}

void Encriptor::on_Cancel_clicked()
{
    this->close();
    main_window->show();
    needPlay = false;

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
    encoderedText = morze::Encript(originalText, main_window->getDictionary(), mode);
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

void Encriptor::on_SetMode_activated(int index)
{
    if(index == 0){
        mode = morze::Mode::EN;
    }
    if(index == 1){
        mode = morze::Mode::RU;
    }
}

void Encriptor::on_Play_clicked(bool checked)
{
    if(checked && isPlayClickedFirstTime){
        ui->Play->setIcon(QIcon("Sourse/Icons/icon-sound.png"));
        needPlay = true;
        isPlayClickedFirstTime = false;
        try{
            std::thread audioThread(&Encriptor::PlaySound, this);
            audioThread.detach();
        }catch(...){}
    }else{
        if(checked){
            ui->Play->setIcon(QIcon("Sourse/Icons/icon-sound.png"));
            needPlay = true;
            try{
                std::thread audioThread(&Encriptor::PlaySound, this);
                audioThread.detach();
            }catch(...){}
        }else {
            ui->Play->setIcon(QIcon("Sourse/Icons/icon-no-sound.png"));
            needPlay = false;
        }
    }
}

void Encriptor::PlaySound(){
    try{
        shortSoundDuration = player->duration();
        longSoundDuration = player2 ->duration();
        delimetrSoundDuration = player3->duration();
        delimetrCharSoundDuration = player4->duration();
        for(auto sym : encoderedText){
            if(!needPlay){
                break;
            }
            if(sym == main_window->getShortSymbol()){
                shortSound->play();
                std::this_thread::sleep_for(std::chrono::milliseconds(shortSoundDuration));
            }
            if(sym == main_window->getLongSymbol()){
                longSound->play();
                std::this_thread::sleep_for(std::chrono::milliseconds(longSoundDuration));
            }
            if(sym == main_window->getDelimetr()){
                delimetrSound->play();
                std::this_thread::sleep_for(std::chrono::milliseconds(delimetrSoundDuration));
            }
            if(sym == main_window->getDelimetrCharSymbol()){
                delimetrCharSound->play();
                std::this_thread::sleep_for(std::chrono::milliseconds(delimetrCharSoundDuration));
            }
        }
        needPlay = false;
    }catch(...){}
}

void Encriptor::Update(QString shortS, QString longS, QString delS, QString delCharS){
    shortSound->setSource(QUrl::fromLocalFile(shortS));
    player->setSource(QUrl::fromLocalFile(shortS));
    longSound->setSource(QUrl::fromLocalFile(longS));
    player2->setSource(QUrl::fromLocalFile(longS));
    delimetrSound->setSource(QUrl::fromLocalFile(delS));
    player3->setSource(QUrl::fromLocalFile(delS));
    delimetrCharSound->setSource(QUrl::fromLocalFile(delCharS));
    player4->setSource(QUrl::fromLocalFile(delCharS));
}

void Encriptor::on_SaveResultWAV_clicked()
{
    try{
        WriteWav();
    }catch(...){}
}

void Encriptor::WriteWav(){
    QString filename = QFileDialog::getSaveFileName(this, "Выбор файла", ("result_e.wav"));
    QString chunk_id = "RIFF";
    QString chunk_size = "----";
    QString format = "WAVE";
    QString fmt_subchunk_id = "fmt ";
    int fmt_subchunk_size = 16;
    int audio_format = 1;
    int num_chanals = 1;
    int sample_rate = 44100;
    int byte_rate = sample_rate * num_chanals * (fmt_subchunk_size / 8);
    int block_align = num_chanals * (fmt_subchunk_size / 8);
    int bits_per_sample = 16;
    QString data_subchunk_id = "data";
    QString data_subchun_size = "----";

    QFile file(filename);
    QDataStream output(&file);
    if(file.open(QIODevice::WriteOnly)){
        file.write(chunk_id.toUtf8());
        file.write(chunk_size.toUtf8());
        file.write(format.toUtf8());
        file.write(fmt_subchunk_id.toUtf8());
        file.write(QByteArray::fromRawData(reinterpret_cast<char*>(&fmt_subchunk_size), 4));
        file.write(QByteArray::fromRawData(reinterpret_cast<char*>(&audio_format), 2));
        file.write(QByteArray::fromRawData(reinterpret_cast<char*>(&num_chanals), 2));
        file.write(QByteArray::fromRawData(reinterpret_cast<char*>(&sample_rate), 4));
        file.write(QByteArray::fromRawData(reinterpret_cast<char*>(&byte_rate), 4));
        file.write(QByteArray::fromRawData(reinterpret_cast<char*>(&block_align), 2));
        file.write(QByteArray::fromRawData(reinterpret_cast<char*>(&bits_per_sample), 2));
        file.write(data_subchunk_id.toUtf8());
        file.write(data_subchun_size.toUtf8());
        int audio_data_begin = file.pos();
        for(auto symbol : encoderedText){
            if(symbol == main_window->getShortSymbol()){
                file.write(main_window->getShortSoundData());
                continue;
            }
            if(symbol == main_window->getLongSymbol()){
                file.write(main_window->getLongSoundData());
                continue;
            }
            if(symbol == main_window->getDelimetr()){
                file.write(main_window->getDelimetrSoundData());
                continue;
            }
            if(symbol == main_window->getDelimetrCharSymbol()){
                file.write(main_window->getDelimetrCharSoundData());
                continue;
            }
        }
        int audio_data_end = file.pos();
        file.seek(audio_data_begin -4);
        int tmp = audio_data_end - audio_data_begin;
        file.write(QByteArray::fromRawData(reinterpret_cast<char*>(&tmp), 4));
        tmp = audio_data_end - 8;
        file.seek(4);
        file.write(QByteArray::fromRawData(reinterpret_cast<char*>(&tmp), 4));
        file.close();
    }
}

























































































