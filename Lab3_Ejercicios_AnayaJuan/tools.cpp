#include "tools.h"

string read(string name)
{
    ifstream file;
    string data;

    file.open(name);
    if (file.is_open()){
        while (!file.eof()) {
            data += file.get();
        }
        file.close();
    }
    else{
        cout << "Error al abrir el archivo." << endl;
        exit(1);
    }

    return data;
}

void write(string name, string data)
{
    ofstream file;

    file.open(name);
    if (file.is_open()){
        file << data;
        file.close();
    }
    else{
        cout << "Error al abrir el archivo." << endl;
        exit(1);
    }
}

string text_to_binary(string text)
{
    string binary, char_to_bin;

    while(text.length()){
        char_to_bin = "";
        for(int i=0, ascii=int(text[0]); i<8; ascii /= 2, ++i){
            char_to_bin += (ascii%2) + 48;
        }
        reverse(char_to_bin.begin(), char_to_bin.end());
        binary += char_to_bin;
        text = text.substr(1, text.length()-1);
    }

    return binary;
}
