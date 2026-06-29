#include<memory>
#include<map>
#include<fstream>
#include"morze.hpp"

namespace morze{

struct Dictionary{
    std::map<QString, QString> ru_code;
    std::map<QString, QString> ru_decode;
    std::map<QString, QString> international_code;
    std::map<QString, QString> international_decode;
    QString delimetr_;
};

void set_dictionary(QString& long_symbol, QString& short_symbol,QString& delimetr, Dictionary& dict){
    auto s = short_symbol;
    auto l = long_symbol;
    dict.delimetr_ = delimetr;
    // fill the international dictionary's variant (TO morze code)
    dict.international_code["a"] = s+l;
    dict.international_code["b"] = l+s+s+s;
    dict.international_code["c"] = l+s+l+s;
    dict.international_code["d"] = l+s+s;
    dict.international_code["e"] = s;
    dict.international_code["f"] = s+s+l+s;
    dict.international_code["g"] = l+l+s;
    dict.international_code["h"] = s+s+s+s;
    dict.international_code["i"] = s+s;
    dict.international_code["j"] = s+l+l+l;
    dict.international_code["k"] = l+s+l;
    dict.international_code["l"] = s+l+s+s;
    dict.international_code["m"] = l+l;
    dict.international_code["n"] = l+s;
    dict.international_code["o"] = l+l+l;
    dict.international_code["p"] = s+l+l+s;
    dict.international_code["q"] = l+l+s+l;
    dict.international_code["r"] = s+l+s;
    dict.international_code["s"] = s+s+s;
    dict.international_code["t"] = l;
    dict.international_code["u"] = s+s+l;
    dict.international_code["v"] = s+s+s+l;
    dict.international_code["w"] = s+l+l;
    dict.international_code["x"] = l+s+s+l;
    dict.international_code["y"] = l+s+l+l;
    dict.international_code["z"] = l+l+s+s;

    dict.international_code["1"] = s+l+l+l+l;
    dict.international_code["2"] = s+s+l+l+l;
    dict.international_code["3"] = s+s+s+l+l;
    dict.international_code["4"] = s+s+s+s+l;
    dict.international_code["5"] = s+s+s+s+s;
    dict.international_code["6"] = l+s+s+s+s;
    dict.international_code["7"] = l+l+s+s+s;
    dict.international_code["8"] = l+l+l+s+s;
    dict.international_code["9"] = l+l+l+l+s;
    dict.international_code["0"] = l+l+l+l+l;

    dict.international_code["."] = s+l+s+l+s+l;
    dict.international_code[","] = l+l+s+s+l+l;
    dict.international_code["?"] = s+s+l+l+s+s;
    dict.international_code["—"] = l+s+s+s+s+l;
    dict.international_code[":"] = l+l+l+s+s+s;
    dict.international_code[";"] = l+s+l+s+l+s;
    dict.international_code["!"] = l+s+l+s+l+l;
    dict.international_code["'"] = s+l+l+l+l+s;
    dict.international_code[QString::fromStdString(std::to_string('"'))] = s+l+s+s+l+s;
    dict.international_code["("] = l+s+l+l+s;
    dict.international_code[")"] = l+s+l+l+s+l;
    dict.international_code["&"] = s+l+s+s+s;
    dict.international_code["/"] = l+s+s+l+s;
    dict.international_code["_"] = s+s+l+l+s+l;
    dict.international_code["="] = l+s+s+s+l;
    dict.international_code["+"] = s+l+s+l+s;
    dict.international_code["-"] = l+s+s+s+s+l;
    dict.international_code["$"] = s+s+s+l+s+s+l;
    dict.international_code["@"] = s+l+l+s+l+s;

    //fill the international dictionary's variant (FROM morze code)
    dict.international_code[s+l] = "a";
    dict.international_code[l+s+s+s] = "b";
    dict.international_code[l+s+l+s] = "c";
    dict.international_code[l+s+s] = "d";
    dict.international_code[s] = "e";
    dict.international_code[s+s+l+s] = "f";
    dict.international_code[l+l+s] = "g";
    dict.international_code[s+s+s+s] = "h";
    dict.international_code[s+s] = "i";
    dict.international_code[s+l+l+l] = "j";
    dict.international_code[l+s+l] = "k";
    dict.international_code[s+l+s+s] = "l";
    dict.international_code[l+l] = "m";
    dict.international_code[l+s] = "n";
    dict.international_code[l+l+l] = "o";
    dict.international_code[s+l+l+s] = "p";
    dict.international_code[l+l+s+l] = "q";
    dict.international_code[s+l+s] = "r";
    dict.international_code[s+s+s] = "s";
    dict.international_code[l] = "t";
    dict.international_code[s+s+l] = "u";
    dict.international_code[s+s+s+l] = "v";
    dict.international_code[s+l+l] = "w";
    dict.international_code[l+s+s+l] = "x";
    dict.international_code[l+s+l+l] = "y";
    dict.international_code[l+l+s+ s] = "z";

    dict.international_code[s+l+l+l+l] = "1";
    dict.international_code[s+s+l+l+l] = "2";
    dict.international_code[s+s+s+l+l] = "3";
    dict.international_code[s+s+s+s+l] = "4";
    dict.international_code[s+s+s+s+s] = "5";
    dict.international_code[l+s+s+s+s] = "6";
    dict.international_code[l+l+s+s+s] = "7";
    dict.international_code[l+l+l+s+s] = "8";
    dict.international_code[l+l+l+l+s] = "9";
    dict.international_code[l+l+l+l+l] = "0";

    dict.international_code[s+l+s+l+s+l] = ".";
    dict.international_code[l+l+s+s+l+l] = ",";
    dict.international_code[s+s+l+l+s+s] = "?";
    dict.international_code[l+s+s+s+s+l] = "—";
    dict.international_code[l+l+l+s+s+s] = ":";
    dict.international_code[l+s+l+s+l+s] = ";";
    dict.international_code[l+s+l+s+l+l] = "!";
    dict.international_code[s+l+l+l+l+s] = "'";
    dict.international_code[s+l+s+s+l+s] = QString::fromStdString(std::to_string('"'));
    dict.international_code[l+s+l+l+s] = "(";
    dict.international_code[l+s+l+l+s+l] = ")";
    dict.international_code[s+l+s+s+s] = "&";
    dict.international_code[l+s+s+l+s] = "/";
    dict.international_code[s+s+l+l+s+l] = "_";
    dict.international_code[l+s+s+s+l] = "=";
    dict.international_code[s+l+s+l+s] = "+";
    dict.international_code[l+s+s+s+s+l] = "-";
    dict.international_code[s+s+s+l+s+s+l] = "$";
    dict.international_code[s+l+l+s+l+s] = "@";
    // make for russian
}

QString Encript_from_en(QString& originalText, Dictionary& dict){
    QString encodered_text = "";
    for(auto symbol : originalText){
        encodered_text += dict.international_code.at(symbol);
    }
    return encodered_text;
}

QString Decript_to_en(QString& encriptedText, Dictionary& dict){
    QString decripted_text = "";
    for(auto symbol : encriptedText){
        //двигаемся до разделител, склеевая сиволы, найдя разделитель переводим поолученнуюю сторуку
    }
}
}

