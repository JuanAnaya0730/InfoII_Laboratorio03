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

string first_method(string data, int seed)
{
    string encryptedData;
    string binaryData = text_to_binary(data);
    int countOne = 0, countZero = 0, module;
    string block;

    while (binaryData.length()){

        block = binaryData.substr(0, seed);

        if (countZero == countOne) module = 1;
        else if (countZero > countOne) module = 2;
        else module = 3;

        for (int i=1; i<=seed; ++i){
            if (i % module == 0){
                block[i-1] == '0' ? encryptedData += '1' : encryptedData += '0';
                continue;
            }
            encryptedData += block[i-1];
        }

        countOne = countZero = 0;
        for (int i=0; i<seed; ++i){
            block[i] == '0' ? countZero++ : countOne++;
        }

        binaryData = binaryData.substr(seed, binaryData.length()-1);
    }

    return encryptedData;
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
