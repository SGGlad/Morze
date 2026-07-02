#pragma once
#include <QString>
#include<map>

namespace  morze{
enum class Mode{
    EN = 1,
    RU = 2

};

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


QString Encript(QString& originaltext, Dictionary dict, Mode mode);
QString Decript(QString& encriptedText, Dictionary dict, Mode mode);
}
