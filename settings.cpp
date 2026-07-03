#include "settings.h"
#include "ui_settings.h"
#include "miniaudio/miniaudio.h"

Settings::Settings(MainWindow* main, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings), main_window(main)
{
    ui->setupUi(this);
    setWindowTitle("Шифрофщик Морзе");
    ui->ShortSymbol->setText(main_window->getShortSymbol());
    ui->LongSymbol->setText(main_window->getLongSymbol());
    ui->Delimetr->setText(main_window->getDelimetr());
    ui->ShortSound->setCheckable(true);
    ui->LongSound_2->setCheckable(true);
    ui->DelimetrSound->setCheckable(true);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_ShortSymbol_textEdited(const QString &symbol)
{
    if (symbol != ""){
        if (symbol != " "){
            if (symbol != settingLongSymbol_ && symbol != settingDelimetr_){
                settingShortSymbol_ = symbol;
                ui->ShortSymbolTextError->setText("");
                ui->ApplyButton->setEnabled(true);
            }else{
                ui->ShortSymbolTextError->setText("Символ уже используется");
                ui->ApplyButton->setEnabled(false);
            }
        }else{
            ui->ShortSymbolTextError->setText("Невозможно использовать");
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
        if (symbol != " "){
            if (symbol != settingShortSymbol_ && symbol!=settingDelimetr_){
                settingLongSymbol_ = symbol;
                ui->LongSymbolTextError->setText("");
                ui->ApplyButton->setEnabled(true);
            }else{
                ui->LongSymbolTextError->setText("Символ уже используется");
                ui->ApplyButton->setEnabled(false);
            }
        }else{
            ui->LongSymbolTextError->setText("Невозможно использовать");
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
        if(symbol != " "){
            if (symbol != settingLongSymbol_ && symbol != settingShortSymbol_){
                settingDelimetr_ = symbol;
                ui->DelimetrSymbolTextError->setText("");
                ui->ApplyButton->setEnabled(true);
            }else{
                ui->DelimetrSymbolTextError->setText("Символ уже используется");
                ui->ApplyButton->setEnabled(false);
            }
        }else{
            ui->DelimetrSymbolTextError->setText("Невозможно использовать");
            ui->ApplyButton->setEnabled(false);
        }
    }else{
        ui->DelimetrSymbolTextError->setText("Пустое поле");
        ui->ApplyButton->setEnabled(false);
    }
}

void Settings::on_SetShortSound_clicked()
{
    try{
        QString filename = QFileDialog::getOpenFileName(this, "Выбор файла", ("*wav"));
        if (filename != settingDelimetrSound_ && filename != settingLongSound_){
            settingShortSound_ = filename;
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
        if (filename != settingDelimetrSound_ && filename != settingShortSound_){
            settingLongSound_ = filename;
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
        if (filename != settingLongSound_ && filename != settingShortSound_){
             settingDelimetrSound_ = filename;
            ui->DelimrtrSoundError->setText("");
        }else{
            ui->DelimrtrSoundError->setText("Уже используется");
        }
    }catch(...){}
}

void Settings::on_ShortSound_clicked(bool checked)
{
    try{
        ma_engine engine;
        ma_result result = ma_engine_init(NULL, &engine);
        if(result != MA_SUCCESS){
            ui->ShortSoundError->setText("Не удалось воспроизвести");
        }else{
            ui->ShortSoundError->setText("");
            ma_engine_play_sound(&engine, qPrintable(settingShortSound_), NULL);
        }

    }catch(...){ui->ShortSoundError->setText("Не удалось воспроизвести");}
}
void Settings::on_LongSound_2_clicked(bool checked)
{
    try{
        ui->LongSoundError->setText("");
       ma_engine engine;
        ma_engine_init(NULL, &engine);
        ma_sound sound;
        if (ma_sound_init_from_file(&engine, qPrintable(settingLongSound_), MA_SOUND_FLAG_DECODE, NULL, NULL, &sound) == MA_SUCCESS){
            ma_sound_start(&sound);
            timer = new QTimer(this);
            connect(timer, &QTimer::timeout, this, [this, sound]() {
                if (!ma_sound_is_playing(&sound)) {
                    timer->stop();
                    deleteLater();
                }
            });
            timer->start(100);
            if(!timer->isActive()){
                ma_sound_uninit(&sound);
                ma_engine_uninit(&engine);
            }
        }

    }catch(...){ui->LongSoundError->setText("Не удалось воспроизвести");}
}
void Settings::on_DelimetrSound_clicked(bool checked)
{
    try{
        ma_engine engine;
        ma_result result = ma_engine_init(NULL, &engine);
        if(result != MA_SUCCESS){
             ui->DelimrtrSoundError->setText("Не удалось воспроизвести");
        }else{
            ui->DelimrtrSoundError->setText("");
            ma_engine_play_sound(&engine, qPrintable(settingDelimetrSound_), NULL);
        }

    }catch(...){ui->DelimrtrSoundError->setText("Не удалось воспроизвести");}
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
    main_window->updateDict();
}

void Settings::on_CancelButton_clicked()
{
    this->close();
    main_window->show();
    delete this;
}

