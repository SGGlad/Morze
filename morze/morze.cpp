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
    auto d = delimetr;
    // fill the international dictionary's variant (TO morze code)
    international_code["a"] = s+l;
    international_code["b"] = l+s+d+s+d+s;
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
    international_code[QString{'"'}] = s+d+l+d+s+d+s+d+l+d+s;
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
    international_decode[s+d+l+d+s+d+s+d+l+d+s] = QString{'"'};
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
    //fill the russian ddictionary's variant (FROM morze code)
    ru_decode[s+d+l] = "а";
    ru_decode[l+d+s+d+s+d+s] = "б";
    ru_decode[s+d+l+d+l] = "в";
    ru_decode[l+d+l+d+s] = "г";
    ru_decode[l+d+s+d+s] = "д";
    ru_decode[s] = "е";
    ru_decode[s] = "ё";
    ru_decode[s+d+s+d+s+d+l] = "ж";
    ru_decode[l+d+l+d+s+d+s] = "з";
    ru_decode[s+d+s] = "и";
    ru_decode[s+d+l+d+l+d+l] = "й";
    ru_decode[l+d+s+d+l] = "к";
    ru_decode[s+d+l+d+s+d+s] = "л";
    ru_decode[l+d+l] = "м";
    ru_decode[l+d+s] = "н";
    ru_decode[l+d+l+d+l] = "о";
    ru_decode[s+d+l+d+l+d+s] = "п";
    ru_decode[s+d+l+d+s] = "р";
    ru_decode[s+d+l+d+s] = "с";
    ru_decode[l] = "т";
    ru_decode[s+d+s+d+l] = "у";
    ru_decode[s+d+s+d+l+d+s] = "ф";
    ru_decode[s+d+s+d+s+d+s] = "х";
    ru_decode[l+d+s+d+l+d+s] = "ц";
    ru_decode[l+d+l+d+l+d+s] = "ч";
    ru_decode[l+d+l+d+l+d+l] = "ш";
    ru_decode[l+d+l+d+s+d+l] = "щ";
    ru_decode[l+d+l+d+s+d+s+d+l+d+s] = "ъ";
    ru_decode[l+d+s+d+l+d+l] = "ы";
    ru_decode[l+d+s+d+s+d+l] = "ь";
    ru_decode[s+d+s+d+l+d+s+d+s] = "э";
    ru_decode[s+d+s+d+l+d+l] = "ю";
    ru_decode[s+d+l+d+s+d+l] = "я";


    ru_decode[s+d+l+d+l+d+l+d+l] = "1";
    ru_decode[s+d+s+d+l+d+l+d+l] = "2";
    ru_decode[s+d+s+d+s+d+l+d+l] = "3";
    ru_decode[s+d+s+d+s+d+s+d+l] = "4";
    ru_decode[s+d+s+d+s+d+s+d+s] = "5";
    ru_decode[l+d+s+d+s+d+s+d+s] = "6";
    ru_decode[l+d+l+d+s+d+s+d+s] = "7";
    ru_decode[l+d+l+d+l+d+s+d+s] = "8";
    ru_decode[l+d+l+d+l+d+l+d+s] = "9";
    ru_decode[l+d+l+d+l+d+l+d+l] = "0";

    ru_decode[s+d+l+d+s+d+l+d+s+d+l] = ".";
    ru_decode[l+d+l+d+s+d+s+d+l+d+l] = ",";
    ru_decode[s+d+s+d+l+d+l+d+s+d+s] = "?";
    ru_decode[l+d+s+d+s+d+s+d+s+d+l] = "—";
    ru_decode[l+d+l+d+l+d+s+d+s+d+s] = ":";
    ru_decode[l+d+s+d+l+d+s+d+l+d+s] = ";";
    ru_decode[l+d+s+d+l+d+s+d+l+d+l] = "!";
    ru_decode[s+d+l+d+l+d+l+d+l+d+s] = "'";
    ru_decode[s+d+l+d+s+d+s+d+l+d+s] = QString{'"'};
    ru_decode[l+d+s+d+l+d+l+d+s] = "(";
    ru_decode[l+d+s+d+l+d+l+d+s+d+l] = ")";
    ru_decode[s+d+l+d+s+d+s+d+s] = "&";
    ru_decode[l+d+s+d+s+d+l+d+s] = "/";
    ru_decode[s+d+s+d+l+d+l+d+s+d+l] = "_";
    ru_decode[l+d+s+d+s+d+s+d+l] = "=";
    ru_decode[s+d+l+d+s+d+l+d+s] = "+";
    ru_decode[l+d+s+d+s+d+s+d+s+d+l] = "-";
    ru_decode[s+d+s+d+s+d+l+d+s+d+s+d+l] = "$";
    ru_decode[s+d+l+d+l+d+s+d+l+d+s] = "@";

    //russian TO moerze
    ru_code["а"] = s+d+l;
    ru_code["б"] = l+d+s+d+s+d+s;
    ru_code["в"] = s+d+l+d+l;
    ru_code["г"] = l+d+l+d+s;
    ru_code["д"] = l+d+s+d+s;
    ru_code["е"] = s;
    ru_code["ё"] = s;
    ru_code["ж"] = s+d+s+d+s+d+l;
    ru_code["з"] = l+d+l+d+s+d+s;
    ru_code["и"] = s+d+s;
    ru_code["й"] = s+d+l+d+l+d+l;
    ru_code["к"] = l+d+s+d+l;
    ru_code["л"] = s+d+l+d+s+d+s;
    ru_code["м"] = l+d+l;
    ru_code["н"] = l+d+s;
    ru_code["о"] = l+d+l+d+l;
    ru_code["п"] = s+d+l+d+l+d+s;
    ru_code["р"] = s+d+l+d+s;
    ru_code["с"] = s+d+l+d+s;
    ru_code["т"] = l;
    ru_code["у"] = s+d+s+d+l;
    ru_code["ф"] = s+d+s+d+l+d+s;
    ru_code["х"] = s+d+s+d+s+d+s;
    ru_code["ц"] = l+d+s+d+l+d+s;
    ru_code["ч"] = l+d+l+d+l+d+s;
    ru_code["ш"] = l+d+l+d+l+d+l;
    ru_code["щ"] = l+d+l+d+s+d+l;
    ru_code["ъ"] = l+d+l+d+s+d+s+d+l+d+s;
    ru_code["ы"] = l+d+s+d+l+d+l;
    ru_code["ь"] = l+d+s+d+s+d+l;
    ru_code["э"] = s+d+s+d+l+d+s+d+s;
    ru_code["ю"] = s+d+s+d+l+d+l;
    ru_code["я"] = s+d+l+d+s+d+l;

    ru_code["1"] = s+d+l+d+l+d+l+d+l;
    ru_code["2"] = s+d+s+d+l+d+l+d+l;
    ru_code["3"] = s+d+s+d+s+d+l+d+l;
    ru_code["4"] = s+d+s+d+s+d+s+d+l;
    ru_code["5"] = s+d+s+d+s+d+s+d+s;
    ru_code["6"] = l+d+s+d+s+d+s+d+s;
    ru_code["7"] = l+d+l+d+s+d+s+d+s;
    ru_code["8"] = l+d+l+d+l+d+s+d+s;
    ru_code["9"] = l+d+l+d+l+d+l+d+s;
    ru_code["0"] = l+d+l+d+l+d+l+d+l;

    ru_code["."] = s+d+l+d+s+d+l+d+s+d+l;
    ru_code[","] = l+d+l+d+s+d+s+d+l+d+l;
    ru_code["?"] = s+d+s+d+l+d+l+d+s+d+s;
    ru_code["—"] = l+d+s+d+s+d+s+d+s+d+l;
    ru_code[":"] = l+d+l+d+l+d+s+d+s+d+s;
    ru_code[";"] = l+d+s+d+l+d+s+d+l+d+s;
    ru_code["!"] = l+d+s+d+l+d+s+d+l+d+l;
    ru_code["'"] = s+d+l+d+l+d+l+d+l+d+s;
    ru_code[QString{'"'}] = s+d+l+d+s+d+s+d+l+d+s;
    ru_code["("] = l+d+s+d+l+d+l+d+s;
    ru_code[")"] = l+d+s+d+l+d+l+d+s+d+l;
    ru_code["&"] = s+d+l+d+s+d+s+d+s;
    ru_code["/"] = l+d+s+d+s+d+l+d+s;
    ru_code["_"] = s+d+s+d+l+d+l+d+s+d+l;
    ru_code["="] = l+d+s+d+s+d+s+d+l;
    ru_code["+"] = s+d+l+d+s+d+l+d+s;
    ru_code["-"] = l+d+s+d+s+d+s+d+s+d+l;
    ru_code["$"] = s+d+s+d+s+d+l+d+s+d+s+d+l;
    ru_code["@"] = s+d+l+d+l+d+s+d+l+d+s;


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
                    encodered_text += dict.international_code.at(symbol)+dict.delimetr_+dict.delimetr_+dict.delimetr_;
                }else{
                    for (int i = 0; i < 7; ++i){
                        encodered_text+=dict.delimetr_;
                    }
                }
            }
            ++index;
        }
    }
    if (mode == Mode::RU){
        for(auto symbol : originalText){
            if (symbol != " " && (index+1 == originalText.size() || originalText[index+1] == " ")){
                encodered_text += dict.ru_code.at(symbol);
            }else{
                if(symbol != " "){
                    encodered_text += dict.ru_code.at(symbol)+dict.delimetr_+dict.delimetr_+dict.delimetr_;
                }else{
                    for (int i = 0; i < 7; ++i){
                        encodered_text+=dict.delimetr_;
                    }
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
            if (sign != dict.delimetr_){
                symbol+=sign;
                if (i == size - 1){
                    word += dict.international_decode[symbol];
                    decripted_text += word;
                }
            }
            if (sign == dict.delimetr_){
                if(size != i+1){
                    if (encriptedText[i+1] != dict.delimetr_){
                        symbol+=sign;
                    }else{
                        int count = 0;
                        if(size > i+6){
                            for(int j = i; j < i+6; ++j){
                                if (encriptedText[j] == dict.delimetr_){
                                    ++count;
                                    std::cout<<"1:"<<count<<std::endl;
                                }else{break;}
                            }
                            if (count == 3){
                                word+=dict.international_decode[symbol];
                                symbol = "";
                                i += 2;
                            }
                            if (count == 6){
                                word+=dict.international_decode[symbol];
                                decripted_text+=word+" ";
                                symbol ="";
                                word="";
                                i += 6;
                            }
                            if (count!=3 && count !=6){
                                throw QString{"Не удалось расшифровать"};
                            }
                        }
                        if (size < i + 6 && size > i + 2){
                            for(int j = i; j < i+2; ++j){
                                if (encriptedText[j] == dict.delimetr_){
                                    ++count;
                                    std::cout<<"2:"<<count<<std::endl;
                                }else{break;}
                            }
                            if (count == 2){
                                word+=dict.international_decode[symbol];
                                symbol = "";
                                i += 2;
                            }
                            if (count!=2){
                                throw QString{"Не удалось расшифровать"};
                            }
                        }

                    }
                }else{throw QString{"Не удалось расшифровать"};}
            }
        }
    }
    if (mode == Mode::RU){
        for(int i = 0; i < size; ++i){
            QString sign = encriptedText[i];
            std::cout<<"i:"<<i<<std::endl;
            if (sign != dict.delimetr_){
                symbol+=sign;
                if (i == size - 1){
                    word += dict.ru_decode[symbol];
                    decripted_text += word;
                }
            }
            if (sign == dict.delimetr_){
                if(size != i+1){
                    if (encriptedText[i+1] != dict.delimetr_){
                        symbol+=sign;
                    }else{
                        int count = 0;
                        if(size > i+6){
                            for(int j = i; j < i+6; ++j){
                                if (encriptedText[j] == dict.delimetr_){
                                    ++count;
                                    std::cout<<"1:"<<count<<std::endl;
                                }else{break;}
                            }
                            if (count == 3){
                                word+=dict.ru_decode.at(symbol);
                                symbol = "";
                                i += 2;
                            }
                            if (count == 6){
                                word+=dict.ru_decode.at(symbol);
                                decripted_text+=word+" ";
                                symbol ="";
                                word="";
                                i += 6;
                            }
                            if (count!=3 && count !=6){
                                throw QString{"Не удалось расшифровать"};
                            }
                        }
                            if (size < i + 6 && size > i + 2){
                            for(int j = i; j < i+2; ++j){
                                if (encriptedText[j] == dict.delimetr_){
                                    ++count;
                                    std::cout<<"2:"<<count<<std::endl;
                                }else{break;}
                            }
                            if (count == 2){
                                word+=dict.ru_decode.at(symbol);
                                symbol = "";
                                i += 2;
                            }
                            if (count!=2){
                                throw QString{"Не удалось расшифровать"};
                            }
                        }
                    }
                }else{throw QString{"Не удалось расшифровать"};}
            }
        }
    }
        std::cout<<"symbol:"<<symbol.toStdString()<<std::endl;
        std::cout<<"word:"<<word.toStdString()<<std::endl;
        std::cout<<"text:"<<decripted_text.toStdString()<<std::endl;
    return decripted_text;
}
}

