#pragma once
#include <QString>
#include<map>

namespace  morze{
struct Dictionary{
    Dictionary(QString& long_symbol, QString& short_symbol, QString& delimetr);
    Dictionary() = default;
    std::map<QString, QString> ru_code;
    std::map<QString, QString> ru_decode;
    std::map<QString, QString> international_code;
    std::map<QString, QString> international_decode;
    QString delimetr_;
    void Set_dictionary(QString& long_symbol, QString& short_symbol, QString& delimetr);
};


QString Encript_from_en(QString& originaltext, Dictionary dict);
QString Decript_to_en(QString& encriptedText, Dictionary dict);
}
