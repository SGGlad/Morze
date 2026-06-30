#include<memory>
#include<fstream>
#include"morze.hpp"

namespace morze{

Dictionary::Dictionary(QString& long_symbol, QString& short_symbol, QString& delimetr){
    Set_dictionary(long_symbol, short_symbol, delimetr);
}
void Dictionary::Set_dictionary(QString& long_symbol, QString& short_symbol,QString& delimetr){
    auto s = short_symbol;
    auto l = long_symbol;
    delimetr_ = delimetr;
    auto d = delimetr;
    // fill the international dictionary's variant (TO morze code)
    international_code["a"] = s+d+l;
    international_code["b"] = l+d+s+d+s+d+s;
    international_code["c"] = l+d+s+d+l+d+s;
    international_code["d"] = l+d+s+d+s;
    international_code["e"] = s;
    international_code["f"] = s+d+s+d+l+d+s;
    international_code["g"] = l+d+l+d+s;
    international_code["h"] = s+d+s+d+s+d+s;
    international_code["i"] = s+d+s;
    international_code["j"] = s+d+l+d+l+d+l;
    international_code["k"] = l+d+s+d+l;
    international_code["l"] = s+d+l+d+s+d+s;
    international_code["m"] = l+d+l;
    international_code["n"] = l+d+s;
    international_code["o"] = l+d+l+d+l;
    international_code["p"] = s+d+l+d+l+d+s;
    international_code["q"] = l+d+l+d+s+d+l;
    international_code["r"] = s+d+l+d+s;
    international_code["s"] = s+d+s+d+s;
    international_code["t"] = l;
    international_code["u"] = s+d+s+d+l;
    international_code["v"] = s+d+s+d+s+d+l;
    international_code["w"] = s+d+l+d+l;
    international_code["x"] = l+d+s+d+s+d+l;
    international_code["y"] = l+d+s+d+l+d+l;
    international_code["z"] = l+d+l+d+s+d+s;

    international_code["1"] = s+d+l+d+l+d+l+d+l;
    international_code["2"] = s+d+s+d+l+d+l+d+l;
    international_code["3"] = s+d+s+d+s+d+l+d+l;
    international_code["4"] = s+d+s+d+s+d+s+d+l;
    international_code["5"] = s+d+s+d+s+d+s+d+s;
    international_code["6"] = l+d+s+d+s+d+s+d+s;
    international_code["7"] = l+d+l+d+s+d+s+d+s;
    international_code["8"] = l+d+l+d+l+d+s+d+s;
    international_code["9"] = l+d+l+d+l+d+l+d+s;
    international_code["0"] = l+d+l+d+l+d+l+d+l;

    international_code["."] = s+d+l+d+s+d+l+d+s+d+l;
    international_code[","] = l+d+l+d+s+d+s+d+l+d+l;
    international_code["?"] = s+d+s+d+l+d+l+d+s+d+s;
    international_code["—"] = l+d+s+d+s+d+s+d+s+d+l;
    international_code[":"] = l+d+l+d+l+d+s+d+s+d+s;
    international_code[";"] = l+d+s+d+l+d+s+d+l+d+s;
    international_code["!"] = l+d+s+d+l+d+s+d+l+d+l;
    international_code["'"] = s+d+l+d+l+d+l+d+l+d+s;
    international_code[QString::fromStdString(std::to_string('"'))] = s+d+l+d+s+d+s+d+l+d+s;
    international_code["("] = l+d+s+d+l+d+l+d+s;
    international_code[")"] = l+d+s+d+l+d+l+d+s+d+l;
    international_code["&"] = s+d+l+d+s+d+s+d+s;
    international_code["/"] = l+d+s+d+s+d+l+d+s;
    international_code["_"] = s+d+s+d+l+d+l+d+s+d+l;
    international_code["="] = l+d+s+d+s+d+s+d+l;
    international_code["+"] = s+d+l+d+s+d+l+d+s;
    international_code["-"] = l+d+s+d+s+d+s+d+s+d+l;
    international_code["$"] = s+d+s+d+s+d+l+d+s+d+s+d+l;
    international_code["@"] = s+d+l+d+l+d+s+d+l+d+s;

    //fill the international dictionary's variant (FROM morze code)
    international_decode[s+d+l] = "a";
    international_decode[l+d+s+d+s+d+s] = "b";
    international_decode[l+d+s+d+l+d+s] = "c";
    international_decode[l+d+s+d+s] = "d";
    international_decode[s] = "e";
    international_decode[s+d+s+d+l+d+s] = "f";
    international_decode[l+d+l+d+s] = "g";
    international_decode[s+d+s+d+s+d+s] = "h";
    international_decode[s+d+s] = "i";
    international_decode[s+d+l+d+l+d+l] = "j";
    international_decode[l+d+s+d+l] = "k";
    international_decode[s+d+l+d+s+d+s] = "l";
    international_decode[l+d+l] = "m";
    international_decode[l+d+s] = "n";
    international_decode[l+d+l+d+l] = "o";
    international_decode[s+d+l+d+l+d+s] = "p";
    international_decode[l+d+l+d+s+d+l] = "q";
    international_decode[s+d+l+d+s] = "r";
    international_decode[s+d+s+d+s] = "s";
    international_decode[l] = "t";
    international_decode[s+d+s+d+l] = "u";
    international_decode[s+d+s+d+s+d+l] = "v";
    international_decode[s+d+l+d+l] = "w";
    international_decode[l+d+s+d+s+d+l] = "x";
    international_decode[l+d+s+d+l+d+l] = "y";
    international_decode[l+d+l+d+s+d+s] = "z";

    international_decode[s+d+l+d+l+d+l+d+l] = "1";
    international_decode[s+d+s+d+l+d+l+d+l] = "2";
    international_decode[s+d+s+d+s+d+l+d+l] = "3";
    international_decode[s+d+s+d+s+d+s+d+l] = "4";
    international_decode[s+d+s+d+s+d+s+d+s] = "5";
    international_decode[l+d+s+d+s+d+s+d+s] = "6";
    international_decode[l+d+l+d+s+d+s+d+s] = "7";
    international_decode[l+d+l+d+l+d+s+d+s] = "8";
    international_decode[l+d+l+d+l+d+l+d+s] = "9";
    international_decode[l+d+l+d+l+d+l+d+l] = "0";

    international_decode[s+d+l+d+s+d+l+d+s+d+l] = ".";
    international_decode[l+d+l+d+s+d+s+d+l+d+l] = ",";
    international_decode[s+d+s+d+l+d+l+d+s+d+s] = "?";
    international_decode[l+d+s+d+s+d+s+d+s+d+l] = "—";
    international_decode[l+d+l+d+l+d+s+d+s+d+s] = ":";
    international_decode[l+d+s+d+l+d+s+d+l+d+s] = ";";
    international_decode[l+d+s+d+l+d+s+d+l+d+l] = "!";
    international_decode[s+d+l+d+l+d+l+d+l+d+s] = "'";
    international_decode[s+d+l+d+s+d+s+d+l+d+s] = QString::fromStdString(std::to_string('"'));
    international_decode[l+d+s+d+l+d+l+d+s] = "(";
    international_decode[l+d+s+d+l+d+l+d+s+d+l] = ")";
    international_decode[s+d+l+d+s+d+s+d+s] = "&";
    international_decode[l+d+s+d+s+d+l+d+s] = "/";
    international_decode[s+d+s+d+l+d+l+d+s+d+l] = "_";
    international_decode[l+d+s+d+s+d+s+d+l] = "=";
    international_decode[s+d+l+d+s+d+l+d+s] = "+";
    international_decode[l+d+s+d+s+d+s+d+s+d+l] = "-";
    international_decode[s+d+s+d+s+d+l+d+s+d+s+d+l] = "$";
    international_decode[s+d+l+d+l+d+s+d+l+d+s] = "@";
    // make for russian
}

QString Encript_from_en(QString& originalText, Dictionary dict){

    QString encodered_text = "";
    int index = 0;
    for(auto symbol : originalText){
        if (symbol != " " && (index+1 == originalText.size() || originalText[index+1] == " ")){
            encodered_text += dict.international_code.at(symbol);
        }else{
            if(symbol != " "){
                encodered_text += dict.international_code.at(symbol)+dict.delimetr_+dict.delimetr_+dict.delimetr_;
            }else{
                for (int i = 0; i < 7; ++i){
                    encodered_text+=dict.delimetr_;
                }
            }
        }
        ++index;
    }
    return encodered_text;
}

QString Decript_to_en(QString& encriptedText, Dictionary dict){
    QString decripted_text = "";
    QString symbol = "";
    QString word = "";
    int size = encriptedText.size();
    for(int i = 0; i < size; ++i){
        QString sign = encriptedText[i];
        if (sign != dict.delimetr_){
            symbol+=sign;
            if (i == size - 1){
               decripted_text += dict.international_decode[symbol];
            }
        }
        if (sign == dict.delimetr_ && i+1 < size && encriptedText[i+1] != dict.delimetr_){
                symbol+=sign;
        }
        if (sign == dict.delimetr_ && i+3 < size && encriptedText[i+3] != dict.delimetr_){
                word+=dict.international_decode[symbol];
                symbol = "";
                i+=2;
        }
        if (sign == dict.delimetr_ && i+6 < size && encriptedText[i+6] != dict.delimetr_){
                decripted_text+=word + " ";
                word = "";
                i+=5;
        }
    }
    return decripted_text;
}
}

