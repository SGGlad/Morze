#include<memory>
#include<fstream>
#include"morze.hpp"
#include <iostream>

namespace morze{

Dictionary::Dictionary(QString& long_symbol, QString& short_symbol, QString& delimetr){
    Set_dictionary(long_symbol, short_symbol, delimetr);
}
void Dictionary::Set_dictionary(QString& long_symbol, QString& short_symbol,QString& delimetr){
    auto s = short_symbol;
    auto l = long_symbol;
    delimetr_ = delimetr;
    // fill the international dictionary's variant (TO morze code)
    international_code["a"] = s+l;
    international_code["b"] = l+s+s+s;
    international_code["c"] = l+s+l+s;
    international_code["d"] = l+s+s;
    international_code["e"] = s;
    international_code["f"] = s+s+l+s;
    international_code["g"] = l+l+s;
    international_code["h"] = s+s+s+s;
    international_code["i"] = s+s;
    international_code["j"] = s+l+l+l;
    international_code["k"] = l+s+l;
    international_code["l"] = s+l+s+s;
    international_code["m"] = l+l;
    international_code["n"] = l+s;
    international_code["o"] = l+l+l;
    international_code["p"] = s+l+l+s;
    international_code["q"] = l+l+s+l;
    international_code["r"] = s+l+s;
    international_code["s"] = s+s+s;
    international_code["t"] = l;
    international_code["u"] = s+s+l;
    international_code["v"] = s+s+s+l;
    international_code["w"] = s+l+l;
    international_code["x"] = l+s+s+l;
    international_code["y"] = l+s+l+l;
    international_code["z"] = l+l+s+s;

    international_code["1"] = s+l+l+l+l;
    international_code["2"] = s+s+l+l+l;
    international_code["3"] = s+s+s+l+l;
    international_code["4"] = s+s+s+s+l;
    international_code["5"] = s+s+s+s+s;
    international_code["6"] = l+s+s+s+s;
    international_code["7"] = l+l+s+s+s;
    international_code["8"] = l+l+l+s+s;
    international_code["9"] = l+l+l+l+s;
    international_code["0"] = l+l+l+l+l;

    international_code["."] = s+l+s+l+s+l;
    international_code[","] = l+l+s+s+l+l;
    international_code["?"] = s+s+l+l+s+s;
    international_code["—"] = l+s+s+s+s+l;
    international_code[":"] = l+l+l+s+s+s;
    international_code[";"] = l+s+l+s+l+s;
    international_code["!"] = l+s+l+s+l+l;
    international_code["'"] = s+l+l+l+l+s;
    international_code[QString{'"'}] = s+l+s+s+l+s;
    international_code["("] = l+s+l+l+s;
    international_code[")"] = l+s+l+l+s+l;
    international_code["&"] = s+l+s+s+s;
    international_code["/"] = l+s+s+l+s;
    international_code["_"] = s+s+l+l+s+l;
    international_code["="] = l+s+s+s+l;
    international_code["+"] = s+l+s+l+s;
    international_code["-"] = l+s+s+s+s+l;
    international_code["$"] = s+s+s+l+s+s+l;
    international_code["@"] = s+l+l+s+l+s;

    //fill the international dictionary's variant (FROM morze code)
    international_decode[s+l] = "a";
    international_decode[l+s+s+s] = "b";
    international_decode[l+s+l+s] = "c";
    international_decode[l+s+s] = "d";
    international_decode[s] = "e";
    international_decode[s+s+l+s] = "f";
    international_decode[l+l+s] = "g";
    international_decode[s+s+s+s] = "h";
    international_decode[s+s] = "i";
    international_decode[s+l+l+l] = "j";
    international_decode[l+s+l] = "k";
    international_decode[s+l+s+s] = "l";
    international_decode[l+l] = "m";
    international_decode[l+s] = "n";
    international_decode[l+l+l] = "o";
    international_decode[s+l+l+s] = "p";
    international_decode[l+l+s+l] = "q";
    international_decode[s+l+s] = "r";
    international_decode[s+s+s] = "s";
    international_decode[l] = "t";
    international_decode[s+s+l] = "u";
    international_decode[s+s+s+l] = "v";
    international_decode[s+l+l] = "w";
    international_decode[l+s+s+l] = "x";
    international_decode[l+s+l+l] = "y";
    international_decode[l+l+s+s] = "z";

    international_decode[s+l+l+l+l] = "1";
    international_decode[s+s+l+l+l] = "2";
    international_decode[s+s+s+l+l] = "3";
    international_decode[s+s+s+s+l] = "4";
    international_decode[s+s+s+s+s] = "5";
    international_decode[l+s+s+s+s] = "6";
    international_decode[l+l+s+s+s] = "7";
    international_decode[l+l+l+s+s] = "8";
    international_decode[l+l+l+l+s] = "9";
    international_decode[l+l+l+l+l] = "0";

    international_decode[s+l+s+l+s+l] = ".";
    international_decode[l+l+s+s+l+l] = ",";
    international_decode[s+s+l+l+s+s] = "?";
    international_decode[l+s+s+s+s+l] = "—";
    international_decode[l+l+l+s+s+s] = ":";
    international_decode[l+s+l+s+l+s] = ";";
    international_decode[l+s+l+s+l+l] = "!";
    international_decode[s+l+l+l+l+s] = "'";
    international_decode[s+l+s+s+l+s] = QString{'"'};
    international_decode[l+s+l+l+s] = "(";
    international_decode[l+s+l+l+s+l] = ")";
    international_decode[s+l+s+s+s] = "&";
    international_decode[l+s+s+l+s] = "/";
    international_decode[s+s+l+l+s+l] = "_";
    international_decode[l+s+s+s+l] = "=";
    international_decode[s+l+s+l+s] = "+";
    international_decode[l+s+s+s+s+l] = "-";
    international_decode[s+s+s+l+s+s+l] = "$";
    international_decode[s+l+l+s+l+s] = "@";
    international_decode[s+s+s+l+s] = "<understood>";
    international_decode[s+l+s+s+s] = "<wait>";
    international_decode[s+s+s+l+s+l] = "<work finished>";
    international_decode[l+s+l+s+l] = "<work begin>";
    international_decode[s+s+s+s+s+s+s+s] = "<error>";

    // make for russian
    //fill the russian ddictionary's variant (FROM morze code)
    ru_decode[s+l] = "а";
    ru_decode[l+s+s+s] = "б";
    ru_decode[s+l+l] = "в";
    ru_decode[l+l+s] = "г";
    ru_decode[l+s+s] = "д";
    ru_decode[s] = "е";
    ru_decode[s+s+s+l] = "ж";
    ru_decode[l+l+s+s] = "з";
    ru_decode[s+s] = "и";
    ru_decode[s+l+l+l] = "й";
    ru_decode[l+s+l] = "к";
    ru_decode[s+l+s+s] = "л";
    ru_decode[l+l] = "м";
    ru_decode[l+s] = "н";
    ru_decode[l+l+l] = "о";
    ru_decode[s+l+l+s] = "п";
    ru_decode[s+l+s] = "р";
    ru_decode[s+s+s] = "с";
    ru_decode[l] = "т";
    ru_decode[s+s+l] = "у";
    ru_decode[s+s+l+s] = "ф";
    ru_decode[s+s+s+s] = "х";
    ru_decode[l+s+l+s] = "ц";
    ru_decode[l+l+l+s] = "ч";
    ru_decode[l+l+l+l] = "ш";
    ru_decode[l+l+s+l] = "щ";
    ru_decode[l+l+s+l+l] = "ъ";
    ru_decode[l+s+l+l] = "ы";
    ru_decode[l+s+s+l] = "ь";
    ru_decode[s+s+l+s+s] = "э";
    ru_decode[s+s+l+l] = "ю";
    ru_decode[s+l+s+l] = "я";


    ru_decode[s+l+l+l+l] = "1";
    ru_decode[s+s+l+l+l] = "2";
    ru_decode[s+s+s+l+l] = "3";
    ru_decode[s+s+s+s+l] = "4";
    ru_decode[s+s+s+s+s] = "5";
    ru_decode[l+s+s+s+s] = "6";
    ru_decode[l+l+s+s+s] = "7";
    ru_decode[l+l+l+s+s] = "8";
    ru_decode[l+l+l+l+s] = "9";
    ru_decode[l+l+l+l+l] = "0";

    ru_decode[s+l+s+l+s+l] = ".";
    ru_decode[l+l+s+s+l+l] = ",";
    ru_decode[s+s+l+l+s+s] = "?";
    ru_decode[l+s+s+s+s+l] = "—";
    ru_decode[l+l+l+s+s+s] = ":";
    ru_decode[l+s+l+s+l+s] = ";";
    ru_decode[l+s+l+s+l+l] = "!";
    ru_decode[s+l+l+l+l+s] = "'";
    ru_decode[s+l+s+s+l+s] = QString{'"'};
    ru_decode[l+s+l+l+s] = "(";
    ru_decode[l+s+l+l+s+l] = ")";
    ru_decode[s+l+s+s+s] = "&";
    ru_decode[l+s+s+l+s] = "/";
    ru_decode[s+s+l+l+s+l] = "_";
    ru_decode[l+s+s+s+l] = "=";
    ru_decode[s+l+s+l+s] = "+";
    ru_decode[l+s+s+s+s+l] = "-";
    ru_decode[s+s+s+l+s+s+l] = "$";
    ru_decode[s+l+l+s+l+s] = "@";
    ru_decode[s+s+s+l+s] = "<understood>";
    ru_decode[s+l+s+s+s] = "<wait>";
    ru_decode[s+s+s+l+s+l] = "<work finished>";
    ru_decode[l+s+l+s+l] = "<work begin>";
    ru_decode[s+s+s+s+s+s+s+s] = "<error>";

    //russian TO moerze
    ru_code["а"] = s+l;
    ru_code["б"] = l+s+s+s;
    ru_code["в"] = s+l+l;
    ru_code["г"] = l+l+s;
    ru_code["д"] = l+s+s;
    ru_code["е"] = s;
    ru_code["ж"] = s+s+s+l;
    ru_code["з"] = l+l+s+s;
    ru_code["и"] = s+s;
    ru_code["й"] = s+l+l+l;
    ru_code["к"] = l+s+l;
    ru_code["л"] = s+l+s+s;
    ru_code["м"] = l+l;
    ru_code["н"] = l+s;
    ru_code["о"] = l+l+l;
    ru_code["п"] = s+l+l+s;
    ru_code["р"] = s+l+s;
    ru_code["с"] = s+s+s;
    ru_code["т"] = l;
    ru_code["у"] = s+s+l;
    ru_code["ф"] = s+s+l+s;
    ru_code["х"] = s+s+s+s;
    ru_code["ц"] = l+s+l+s;
    ru_code["ч"] = l+l+l+s;
    ru_code["ш"] = l+l+l+l;
    ru_code["щ"] = l+l+s+l;
    ru_code["ъ"] = l+l+s+l+l;
    ru_code["ы"] = l+s+l+l;
    ru_code["ь"] = l+s+s+l;
    ru_code["э"] = s+s+l+s+s;
    ru_code["ю"] = s+s+l+l;
    ru_code["я"] = s+l+s+l;

    ru_code["1"] = s+l+l+l+l;
    ru_code["2"] = s+s+l+l+l;
    ru_code["3"] = s+s+s+l+l;
    ru_code["4"] = s+s+s+s+l;
    ru_code["5"] = s+s+s+s+s;
    ru_code["6"] = l+s+s+s+s;
    ru_code["7"] = l+l+s+s+s;
    ru_code["8"] = l+l+l+s+s;
    ru_code["9"] = l+l+l+l+s;
    ru_code["0"] = l+l+l+l+l;

    ru_code["."] = s+l+s+l+s+l;
    ru_code[","] = l+l+s+s+l+l;
    ru_code["?"] = s+s+l+l+s+s;
    ru_code["—"] = l+s+s+s+s+l;
    ru_code[":"] = l+l+l+s+s+s;
    ru_code[";"] = l+s+l+s+l+s;
    ru_code["!"] = l+s+l+s+l+l;
    ru_code["'"] = s+l+l+l+l+s;
    ru_code[QString{'"'}] = s+l+s+s+l+s;
    ru_code["("] = l+s+l+l+s;
    ru_code[")"] = l+s+l+l+s+l;
    ru_code["&"] = s+l+s+s+s;
    ru_code["/"] = l+s+s+l+s;
    ru_code["_"] = s+s+l+l+s+l;
    ru_code["="] = l+s+s+s+l;
    ru_code["+"] = s+l+s+l+s;
    ru_code["-"] = l+s+s+s+s+l;
    ru_code["$"] = s+s+s+l+s+s+l;
    ru_code["@"] = s+l+l+s+l+s;


}

QString Encript(QString& originalText, Dictionary dict, Mode mode){
    originalText = originalText.toLower();
    QString encodered_text = "";
    int index = 0;
    if (mode == Mode::EN){
        for(auto symbol : originalText){
            if (symbol != " " && (index+1 == originalText.size() || originalText[index+1] == " ")){
                encodered_text += dict.international_code.at(symbol);
            }else{
                if(symbol != " "){
                    encodered_text += dict.international_code.at(symbol)+" ";
                }else{
                    encodered_text+=dict.delimetr_;
                }
            }
            ++index;
        }
    }
    if (mode == Mode::RU){
        originalText.replace("ё", "е");
        for(auto symbol : originalText){
            if (symbol != " " && (index+1 == originalText.size() || originalText[index+1] == " ")){
                encodered_text += dict.ru_code.at(symbol);
            }else{
                if(symbol != " "){
                    encodered_text += dict.ru_code.at(symbol)+" ";
                }else{
                    encodered_text+=dict.delimetr_;
                }
            }
            ++index;
        }
    }
    return encodered_text;
}

QString Decript(QString& encriptedText, Dictionary dict, Mode mode){
    QString decripted_text = "";
    QString symbol = "";
    QString word = "";
    int size = encriptedText.size();
    if (mode == Mode::EN){
        for(int i = 0; i < size; ++i){
            QString sign = encriptedText[i];
            std::cout<<"i:"<<i<<std::endl;
            if (sign != dict.delimetr_ && sign != " "){
                symbol+=sign;
                if (i == size - 1){
                    word += dict.international_decode.at(symbol);
                    decripted_text += word;
                }
            }
            if (sign == " "){
                word += dict.international_decode.at(symbol);
                symbol = "";
            }
            if (sign == dict.delimetr_){
                word += symbol;
                decripted_text += word+" ";
                word = "";
                symbol = "";
            }
        }
    }
    if (mode == Mode::RU){
        for(int i = 0; i < size; ++i){
            QString sign = encriptedText[i];
            if (sign != dict.delimetr_ && sign != " "){
                symbol+=sign;
                if (i == size - 1){
                    word += dict.ru_decode.at(symbol);
                    decripted_text += word;
                }
            }
            if (sign == " "){
                word += dict.ru_decode.at(symbol);
                symbol = "";
            }
            if (sign == dict.delimetr_){
                word += dict.ru_decode.at(symbol);
                decripted_text += word+" ";
                word = "";
                symbol = "";
            }
        }
    }
    return decripted_text;
}
}

