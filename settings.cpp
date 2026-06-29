#include "settings.h"
#include "ui_settings.h"


Settings::Settings(MainWindow* main, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings), main_window(main)
{
    ui->setupUi(this);
    setWindowTitle("Шифрофщик Морзе");
    ui->ShortSymbol->setText(main_window->getShortSymbol());
    ui->LongSymbol->setText(main_window->getLongSymbol());
    ui->Delimetr->setText(main_window->getDelimetr());
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_ShortSymbol_textEdited(const QString &symbol)
{
    if (symbol != ""){
        settingShortSymbol_ = symbol;
        if (ui->ShortSymbolTextError->text() != ""){
            ui->ShortSymbolTextError->setText("");
            ui->ApplyButton->setEnabled(true);
        }
    }else{
        ui->ShortSymbolTextError->setText("Пустое поле");
        ui->ApplyButton->setEnabled(false);
    }
}
void Settings::on_LongSymbol_textEdited(const QString &symbol)
{
    if (symbol != ""){
        settingLongSymbol_ = symbol;
        if (ui->LongSymbolTextError->text() != ""){
            ui->LongSymbolTextError->setText("");
            ui->ApplyButton->setEnabled(true);
        }
    }else{
        ui->LongSymbolTextError->setText("Пустое поле");
        ui->ApplyButton->setEnabled(false);
    }
}
void Settings::on_Delimetr_textEdited(const QString &symbol)
{
    if (symbol != ""){
        settingDelimetr_ = symbol;
        if (ui->DelimetrSymbolTextError->text() != ""){
            ui->DelimetrSymbolTextError->setText("");
            ui->ApplyButton->setEnabled(true);
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
        settingShortSound_ = filename;
    }catch(...){}
}
void Settings::on_SetLongSound_clicked()
{
    try{
        QString filename = QFileDialog::getOpenFileName(this, "Выбор файла ", ("*wav"));
        settingLongSound_ = filename;
    }catch(...){}
}
void Settings::on_SetDelimetrSound_clicked()
{
    try{
        QString filename = QFileDialog::getOpenFileName(this, "Выбор файла", ("*wav"));
        settingDelimetrSound_ = filename;
    }catch(...){}
}

void Settings::on_ShortSound_clicked(bool checked)
{
    //play sound
}
void Settings::on_LongSound_2_clicked(bool checked)
{
    //play sound
}
void Settings::on_DelimetrSound_clicked(bool checked)
{
    //play sound
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
    delete this;
}

void Settings::on_CancelButton_clicked()
{
    this->close();
    main_window->show();
    delete this;
}

