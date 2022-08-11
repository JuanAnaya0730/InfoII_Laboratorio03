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
    // binary son los datos binarios que seran sometidos a la encriptacion
    // seed es la semilla de encriptacion

    string encrypted_data; // Esto almacenara la forma encriptada de los datos ingresados
    string block; // Esta variable ira almacenando los bloques de bits correspondientes a la semilla ingresada
    size_t countOne = 0; // Contador de unos para cada bloque
    size_t countZero = 0; // Contador de ceros para cada bloque
    size_t module; // Es es variable dira que tratamineto se le debe a un bloque de n bits

    while (true){
        block = binary.substr(0, seed); // Se separa un bloque de n bits, con n=seed

        if (countZero == countOne) module = 1; // Se comprueba si la cantidad de unos y ceros de es igual
        else if (countZero > countOne) module = 2; // Se comprueba si la cantidad de ceros es mayor que la de unos
        else module = 3; // Este es el caso en que la cantidad de unos es mayor que la de ceros

        countOne = countZero = 0;
        /* Aqui se hace el conteo de unos y ceros de un bloque */
        for (size_t i=0; i<block.length(); ++i){ block[i] == '0' ? countZero++ : countOne++; }

        /* Aqui es donde se encripta cada bloque de n bits */
        for (size_t i=1; i<=block.length(); ++i){
            if (!(i % module)) block[i-1] == '0' ? block[i-1] = '1' : block[i-1] = '0';
        }

        encrypted_data += block; // El bloque encriptado es añadido a los demas bloques que ya han sido encriptados

        /* Se quita el bloque que fue separado para su encriptacion, si ya no quedan mas bloques disponibles
         * se rompe el ciclo infinito */
        if(binary.length() > seed) binary = binary.substr(seed, binary.length());
        else break;
    }

    return encrypted_data; // Se retornan los datos ya encriptados
}

string decrypt_first_method(string binary, size_t seed)
{
    // binary son los datos binarios que seran desencriptados
    // seed es la semilla con la que los datos fueron encriptados

    string decrypted_data; // Esto almacenara la forma desencriptada de los datos ingresados
    string block; // Esta variable ira almacenando los bloques de bits correspondientes a la semilla ingresada
    size_t countOne = 0; // Contador de unos para cada bloque
    size_t countZero = 0; // Contador de ceros para cada bloque
    size_t module; // Es es variable dira que tratamineto se le debe a un bloque de n bits

    while (true){
        block = binary.substr(0, seed); // Se separa un bloque de n bits, con n=seed

        if (countZero == countOne) module = 1; // Se comprueba si la cantidad de unos y ceros de es igual
        else if (countZero > countOne) module = 2; // Se comprueba si la cantidad de ceros es mayor que la de unos
        else module = 3; // Este es el caso en que la cantidad de unos es mayor que la de ceros

        /* Aqui es donde se desencripta cada bloque de n bits */
        for (size_t i=1; i<=block.length(); ++i){
            if (!(i % module)) block[i-1] == '0' ? block[i-1] = '1' : block[i-1] = '0';
        }

        countOne = countZero = 0;
        /* Aqui se hace el conteo de unos y ceros de un bloque */
        for (size_t i=0; i<block.length(); ++i){
            block[i] == '0' ? countZero++ : countOne++;
        }

        decrypted_data += block; // El bloque desencriptado es añadido a los demas bloques que ya han sido desencriptados

        /* Se quita el bloque que fue separado para su desencriptacion, si ya no quedan mas bloques disponibles
         * se rompe el ciclo infinito */
        if(binary.length() > seed) binary = binary.substr(seed, binary.length());
        else break;
    }

    return decrypted_data; // Se retornan los datos ya desencriptados
}

string encrypt_second_method(string binary, size_t seed)
{
    // binary son los datos binarios que seran sometidos a la encriptacion
    // seed es la semilla de encriptacion

    string encrypted_data; // Esto almacenara la forma encriptada de los datos ingresados
    string block; // Esta variable ira almacenando los bloques de bits correspondientes a la semilla ingresada

    while (true){
        block = binary.substr(0, seed); // Se separa un bloque de n bits, con n=seed

        encrypted_data += block.back(); // Se añade de primero en un bloque el ultimo caracter de ese bloque

        /* Se van añadiendo los bits faltantes corridos una posicion hacia delante respecto a su posicion original */
        for(size_t i=0; i < block.length()-1; ++i){ encrypted_data += block[i]; }

        /* Se quita el bloque que fue separado para su encriptacion, si ya no quedan mas bloques disponibles
         * se rompe el ciclo infinito */
        if(binary.length() > seed){ binary = binary.substr(seed, binary.length()); }
        else{ break; }
    }

    return encrypted_data; // Se retornan los datos ya encriptados
}

string decrypt_second_method(string binary, size_t seed)
{
    // binary son los datos binarios que seran desencriptados
    // seed es la semilla con la que los datos fueron encriptados

    string decrypted_data; // Esto almacenara la forma desencriptada de los datos ingresados
    string block; // Esta variable ira almacenando los bloques de bits correspondientes a la semilla ingresada

    while(true){
        block = binary.substr(0, seed); // Se separa un bloque de n bits, con n=seed

        /* Se van añadiendo los bits faltantes corridos una posicion hacia atras respecto a su posicion original */
        for(size_t i=1; i < block.length(); ++i){ decrypted_data += block[i]; }
        decrypted_data += block.front(); // Se añade de ultimo en un bloque el primer caracter de ese bloque

        /* Se quita el bloque que fue separado para su desencriptacion, si ya no quedan mas bloques disponibles
         * se rompe el ciclo infinito */
        if(binary.length() > seed){ binary = binary.substr(seed, binary.length()); }
        else{ break; }
    }

    return decrypted_data; // Se retornan los datos ya desencriptados
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
