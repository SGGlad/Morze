#pragma once
#include "../mainwindow.h"

namespace  morze{
struct Dictionary;
void Set_dictionaries(QString& long_symbol, QString& short_symbol, QString& delimetr, Dictionary& dict);
QString Encript_from_en(QString& originaltext, Dictionary& dict);
QString Decript_to_en(QString& encriptedText, Dictionary& dict);
}
