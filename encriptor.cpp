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


void Encriptor::on_PlaySound_clicked(bool checked)
{
    if(checked){
        index = 0;
    }
    while(checked && index<encoderedText.size()){
        sf::SoundBuffer buffer;
        if(encoderedText[index]==main_window->getShortSymbol()){
            buffer.loadFromFile(main_window->getShortSound().toStdString());
            sf::Sound sound(buffer);
            sound.play();
            if(sound.getStatus() == sf::Sound::Status::Playing){
            }
        }
        if(encoderedText[index]==main_window->getLongSymbol()){
            buffer.loadFromFile(main_window->getLongSound().toStdString());
            sf::Sound sound(buffer);
            sound.play();
            if(sound.getStatus() == sf::Sound::Status::Playing){
            }
        }
        if(encoderedText[index]==main_window->getDelimetr()){
            buffer.loadFromFile(main_window->getDelimrtrSound().toStdString());
            sf::Sound sound(buffer);
            sound.play();
            if(sound.getStatus() == sf::Sound::Status::Playing){
            }
        }
        ++index;
    }
}


void Encriptor::on_SaveResultWAV_clicked()
{
    try{
        QString filename1 = QFileDialog::getSaveFileName(this, "Выбор файла", ("result.wav"));
        std::string filename = filename1.toStdString();
        std::ofstream wavFile(filename, std::ios::binary);
        sf::SoundBuffer shortBuffer(main_window->getShortSound().toStdString());
        sf::SoundBuffer longBuffer(main_window->getLongSound().toStdString());
        sf::SoundBuffer delBuffer(main_window->getDelimrtrSound().toStdString());
        auto shortData = shortBuffer.getSamples();
        auto longData = longBuffer.getSamples();
        auto delData = delBuffer.getSamples();
        int sampleRate = shortBuffer.getSampleRate();
        int bitDepth = 16;
        //header chunc
        wavFile << "RIFF";
        wavFile << "????";
        wavFile << "WAVE";
        //format chunc
        wavFile << "fmt ";
        wavFile.write(reinterpret_cast<const char*>(16), 4); //size
        wavFile.write(reinterpret_cast<const char*>(1), 2); //copression code
        wavFile.write(reinterpret_cast<const char*>(1), 2); //channals
        wavFile.write(reinterpret_cast<const char*>(sampleRate), 4); //sample rate
        wavFile.write(reinterpret_cast<const char*>(sampleRate*bitDepth/8), 4);
        wavFile.write(reinterpret_cast<const char*>(bitDepth/8), 2);
        wavFile.write(reinterpret_cast<const char*>(bitDepth), 2);
        //data chunc
        wavFile<<"data";
        wavFile<<"????";
        int beforeAudioData = wavFile.tellp();
        for(QString i : encoderedText){
            if (i==main_window->getShortSymbol()){
                wavFile.write(reinterpret_cast<const char*>(&shortData),  4);
                wavFile.write(reinterpret_cast<const char*>(&delData), 4);
            }
            if (i==main_window->getLongSymbol()){
                wavFile.write(reinterpret_cast<const char*>(&longData), 4);
                wavFile.write(reinterpret_cast<const char*>(&delData), 4);
            }
            if (i == " "){
                for(int j = 0; j <2; ++j){
                    wavFile.write(reinterpret_cast<const char*>(&delData), 4);
                }
            }
            if (i == main_window->getDelimetr()){
                for(int j = 0; j <6; ++j){
                    wavFile.write(reinterpret_cast<const char*>(&delData), 4);
                }
            }
        }
        int afterAudioData = wavFile.tellp();
        wavFile.seekp(beforeAudioData-4);
        wavFile.write(reinterpret_cast<const char*>(afterAudioData-beforeAudioData), 4);
        wavFile.seekp(4, std::ios::beg);
        wavFile.write(reinterpret_cast<const char*>(afterAudioData-8), 4);
        wavFile.close();
    }catch(...){}
}

