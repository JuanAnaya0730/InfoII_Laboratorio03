#include "tools.h"

int menu()
{
    string option;

    while(true){
        cout << GREEN "Menu:\n"
                CYAN  "  1. Primer metodo.\n"
                      "  2. Segundo metodo.\n"
                GREEN " Opcion: ";
        cin >> option;

        system("cls"); // Se limpia la consola
        if(option[0] < 49 || option[0] > 50 || option.length() > 1){
            cout << RED "Opcion no valida, Intente de nuevo.\n" << endl;
        }else break;
    }

    return stoi(option);
}

string read(string name)
{
    ifstream file;
    string data, aux;

    file.open("../data/" + name);
    if (file.is_open()){
        while (!file.eof()) {
            getline(file, aux);
            data += aux;
        }
        file.close();
    }
    else{
        cout << RED "Error al abrir el archivo " << name << RESET << endl;
        exit(1);
    }

    return data;
}

void write(string name, string data)
{
    ofstream file;

    file.open("../data/" + name);
    if (file.is_open()){
        file << data;
        file.close();
    }
    else{
        cout << RED "Error al crear o abrir el archivo " << name << RESET << endl;
        exit(1);
    }
}

string encrypt_first_method(string binary, size_t seed)
{
    string encrypted_data;
    size_t countOne = 0, countZero = 0, module;
    string block;

    while (true){
        block = binary.substr(0, seed);

        if (countZero == countOne) module = 1;
        else if (countZero > countOne) module = 2;
        else module = 3;

        countOne = countZero = 0;
        for (size_t i=0; i<block.length(); ++i){
            block[i] == '0' ? countZero++ : countOne++;
        }

        for (size_t i=1; i<=block.length(); ++i){
            if (!(i % module)) block[i-1] == '0' ? block[i-1] = '1' : block[i-1] = '0';
        }

        encrypted_data += block;

        if(binary.length() > seed) binary = binary.substr(seed, binary.length());
        else break;
    }

    return encrypted_data;
}

string decrypt_first_method(string binary, size_t seed)
{
    string decrypted_data;
    size_t countOne = 0, countZero = 0, module;
    string block;

    while (true){
        block = binary.substr(0, seed);

        if (countZero == countOne) module = 1;
        else if (countZero > countOne) module = 2;
        else module = 3;

        for (size_t i=1; i<=block.length(); ++i){
            if (!(i % module)) block[i-1] == '0' ? block[i-1] = '1' : block[i-1] = '0';
        }

        countOne = countZero = 0;
        for (size_t i=0; i<block.length(); ++i){
            block[i] == '0' ? countZero++ : countOne++;
        }

        decrypted_data += block;

        if(binary.length() > seed) binary = binary.substr(seed, binary.length());
        else break;
    }

    return decrypted_data;
}

string encrypt_second_method(string binary, size_t seed)
{
    string encrypted_data;
    string block;

    while (true){
        block = binary.substr(0, seed);

        encrypted_data += block.back();
        for(size_t i=0; i < block.length()-1; ++i){ encrypted_data += block[i]; }

        if(binary.length() > seed){ binary = binary.substr(seed, binary.length()); }
        else{ break; }
    }

    return encrypted_data;
}

string decrypt_second_method(string binary, size_t seed)
{
    string decrypted_data;
    string block;

    while(true){
        block = binary.substr(0, seed);

        for(size_t i=1; i < block.length(); ++i){ decrypted_data += block[i]; }
        decrypted_data += block.front();

        if(binary.length() > seed) binary = binary.substr(seed, binary.length());
        else break;
    }

    return decrypted_data;
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
        text = text.substr(1, text.length());
    }

    return binary;
}

string binary_to_text(string binary)
{
    int ascii;
    string text, bin_to_char;

    while(binary.length()){
        bin_to_char = binary.substr(0, 8);
        reverse(bin_to_char.begin(), bin_to_char.end());

        ascii = 0;
        for(int i=0; i<8; ++i){
            ascii += (int(bin_to_char[i]) - 48)*pow(2, i);
        }
        text += char(ascii);

        binary = binary.substr(8, binary.length());
    }

    return text;
}
