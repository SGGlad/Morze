#include "settings.h"
#include "ui_settings.h"
#include "miniaudio/miniaudio.h"

Settings::Settings(MainWindow* main, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings), main_window(main)
{
    ui->setupUi(this);
    shortSound = new QSoundEffect;
    shortSound->setSource(QUrl::fromLocalFile(settingShortSound_));
    longSound = new QSoundEffect;
    longSound->setSource(QUrl::fromLocalFile(settingLongSound_));
    delimetrSound = new QSoundEffect;
    delimetrSound->setSource(QUrl::fromLocalFile(settingDelimetrSound_));
    delimetrCharSound = new QSoundEffect;
    delimetrCharSound->setSource(QUrl::fromLocalFile(settingDelimetrCharSound_));
    setWindowTitle("Шифрофщик Морзе");
    ui->ShortSymbol->setText(main_window->getShortSymbol());
    ui->LongSymbol->setText(main_window->getLongSymbol());
    ui->Delimetr->setText(main_window->getDelimetr());
    ui->DelimetrChar->setText(main_window->getDelimetrCharSymbol());
    ui->ShortSound->setIcon(QIcon("Sourse/Icons/icon-sound.png"));
    ui->LongSound_2->setIcon(QIcon("Sourse/Icons/icon-sound.png"));
    ui->DelimetrSound->setIcon(QIcon("Sourse/Icons/icon-sound.png"));
    ui->DelimetrCharSound->setIcon(QIcon("Sourse/Icons/icon-sound.png"));
}

Settings::~Settings()
{
    delete shortSound;
    delete longSound;
    delete delimetrSound;
    delete delimetrCharSound;
    delete ui;
}

void Settings::on_ShortSymbol_textEdited(const QString &symbol)
{
    if (symbol != ""){
        if (symbol != settingLongSymbol_ && symbol != settingDelimetr_ && symbol != settingDelimetrChar_){
            settingShortSymbol_ = symbol;
            ui->ShortSymbolTextError->setText("");
            ui->ApplyButton->setEnabled(true);
        }else{
            ui->ShortSymbolTextError->setText("Символ уже используется");
            ui->ApplyButton->setEnabled(false);
        }
    }else{
        ui->ShortSymbolTextError->setText("Пустое поле");
        ui->ApplyButton->setEnabled(false);
    }
}
void Settings::on_LongSymbol_textEdited(const QString &symbol)
{
    if (symbol != ""){
        if (symbol != settingShortSymbol_ && symbol!=settingDelimetr_ && symbol != settingDelimetrChar_){
            settingLongSymbol_ = symbol;
            ui->LongSymbolTextError->setText("");
            ui->ApplyButton->setEnabled(true);
        }else{
            ui->LongSymbolTextError->setText("Символ уже используется");
            ui->ApplyButton->setEnabled(false);
        }
    }else{
        ui->LongSymbolTextError->setText("Пустое поле");
        ui->ApplyButton->setEnabled(false);
    }
}
void Settings::on_Delimetr_textEdited(const QString &symbol)
{
    if (symbol != ""){
        if (symbol != settingLongSymbol_ && symbol != settingShortSymbol_ && symbol != settingDelimetrChar_){
            settingDelimetr_ = symbol;
            ui->DelimetrSymbolTextError->setText("");
            ui->ApplyButton->setEnabled(true);
        }else{
            ui->DelimetrSymbolTextError->setText("Символ уже используется");
            ui->ApplyButton->setEnabled(false);
        }
    }else{
        ui->DelimetrSymbolTextError->setText("Пустое поле");
        ui->ApplyButton->setEnabled(false);
    }
}
void Settings::on_DelimetrChar_textEdited(const QString &symbol)
{
    if (symbol != ""){
        if (symbol != settingLongSymbol_ && symbol != settingShortSymbol_ && symbol != settingDelimetr_){
            settingDelimetrChar_ = symbol;
            ui->DelimetrCharSymbolTextError->setText("");
            ui->ApplyButton->setEnabled(true);
        }else{
            ui->DelimetrCharSymbolTextError->setText("Символ уже используется");
            ui->ApplyButton->setEnabled(false);
        }
    }else{
        ui->DelimetrCharSymbolTextError->setText("Пустое поле");
        ui->ApplyButton->setEnabled(false);
    }
}

void Settings::on_SetShortSound_clicked()
{
    try{
        QString filename = QFileDialog::getOpenFileName(this, "Выбор файла", ("*wav"));
        if (filename != settingDelimetrSound_ && filename != settingLongSound_ && filename != settingDelimetrCharSound_){
            settingShortSound_ = filename;
            shortSound->setSource(QUrl::fromLocalFile(filename));
            ui->ShortSoundError->setText("");
        }else{
            ui->ShortSoundError->setText("Уже используется");
        }
    }catch(...){}
}
void Settings::on_SetLongSound_clicked()
{
    try{
        QString filename = QFileDialog::getOpenFileName(this, "Выбор файла ", ("*wav"));
        if (filename != settingDelimetrSound_ && filename != settingShortSound_ && filename != settingDelimetrCharSound_){
            settingLongSound_ = filename;
            longSound->setSource(QUrl::fromLocalFile(settingLongSound_));
            ui->LongSoundError->setText("");
        }else{
            ui->LongSoundError->setText("Уже используется");
        }
    }catch(...){}
}
void Settings::on_SetDelimetrSound_clicked()
{
    try{
        QString filename = QFileDialog::getOpenFileName(this, "Выбор файла", ("*wav"));
        if (filename != settingLongSound_ && filename != settingShortSound_ && filename != settingDelimetrCharSound_){
            delimetrSound->setSource(QUrl::fromLocalFile(filename));
            settingDelimetrSound_ = filename;
            ui->DelimetrSoundError->setText("");
        }else{
            ui->DelimetrSoundError->setText("Уже используется");
        }
    }catch(...){}
}
void Settings::on_SetDelimetrCharSound_clicked()
{
    try{
        QString filename = QFileDialog::getOpenFileName(this, "Выбор файла", ("*wav"));
        if (filename != settingLongSound_ && filename != settingShortSound_ && filename != settingDelimetrSound_){
            delimetrCharSound->setSource(QUrl::fromLocalFile(filename));
            settingDelimetrCharSound_ = filename;
            ui->DelimetrCharSoundError->setText("");
        }else{
            ui->DelimetrCharSoundError->setText("Уже используется");
        }
    }catch(...){}

}

void Settings::on_ShortSound_clicked()
{
    try{
        if(shortSound->isLoaded()){
            shortSound->play();
        }else{
            ui->ShortSoundError->setText("Не загружен");
        }
    }catch(...){ui->ShortSoundError->setText("Не удалось воспроизвести");}
}
void Settings::on_LongSound_2_clicked()
{
    try{
        if(longSound->isLoaded()){
            longSound->play();
        }else{
            ui->LongSoundError->setText("Не загружен");
        }
    }catch(...){ui->LongSoundError->setText("Не удалось воспроизвести");}
}
void Settings::on_DelimetrSound_clicked()
{
    try{
        if(delimetrSound->isLoaded()){
            delimetrSound->play();
        }else{
            ui->DelimetrSoundError->setText("Не загружен");
        }
    }catch(...){ui->DelimetrSoundError->setText("Не удалось воспроизвести");}
}

void Settings::on_DelimetrCharSound_clicked()
{
    try{
        if(delimetrCharSound->isLoaded()){
            delimetrCharSound->play();
        }else{
            ui->DelimetrCharSoundError->setText("Не загружен");
        }
    }catch(...){ui->DelimetrSoundError->setText("Не удалось воспроизвести");}
}


void Settings::on_ApplyButton_clicked()
{
    this->close();
    main_window->show();
    main_window->setShortSymbol(settingShortSymbol_);
    main_window->setLongSumbol(settingLongSymbol_);
    main_window->setDelimetr(settingDelimetr_);
    main_window->setShortSound(settingShortSound_);
    main_window->setLongSound(settingLongSound_);
    main_window->setDelimetrSound(settingDelimetrSound_);
    main_window->setDelimetrCharSymbol(settingDelimetrChar_);
    main_window->setDelimetrCharSound(settingDelimetrCharSound_);
    main_window->updateDict();
}

void Settings::on_CancelButton_clicked()
{
    this->close();
    main_window->show();
    delete this;
}

