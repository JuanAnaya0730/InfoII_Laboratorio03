#include "tools.h"

int menu(int type)
{
    // type es el menu que debe ser mostrado

    string option; // Esta es la opcion tomada por el usuario

    while(true){
        if(!type){
            /* Se imprime el menu principal para type 0 */
            cout << GREEN "Menu:\n"
                    CYAN  "  1. Codificar archivo.\n"
                          "  2. Decodificar archivo.\n"
                    GREEN " Opcion: ";
        }else{ /* Se imprime el menu principal para type 1 */
            cout << GREEN "Metodos:\n"
                    CYAN  "  1. Primer metodo.\n"
                          "  2. Segundo metodo.\n"
                    GREEN " Opcion: ";
        }

        cin >> option; // Se toma la opcion ingresada

        system("cls"); // Se limpia la consola

        /* Se valida la opcion ingresada */
        if(option[0] < 49 || option[0] > 50 || option.length() > 1){
            cout << RED "Opcion no valida, Intente de nuevo.\n" << endl;
        }else{ break; }
    }

    return stoi(option); // Se retorna la opcion tomada por el usuario
}

string read(string name)
{
    // name es el nombre del archivo a leer

    ifstream file; // Archivo a leer
    string data; // Esto almacenara el contenido del archivo a leer
    string aux; // Esto almacenara temporalmente cada linea del archivo a leer

    file.open("../data/" + name); // Se abre el archivo
    if (file.is_open()){ // Se verifica si el archivo abrio correctamente

        /* Se recorre todo el archivo */
        while (!file.eof()) {
            getline(file, aux); // Se lee cada linea del archivo

            /* Se guarda la linea del archivo y se le agrega un salto de linea ya que la
             * funcion anterior los ignora*/
            data += aux + '\n';
        }

        data.pop_back(); // Se elimina el ultimo salto de linea ya que este no pertenece al archivo

        file.close(); // Se cierra el archivo
    }
    else{ // Si el archivo no se pudo abrir se muestra el mensaje correspondiente y finaliza el programa
        cout << RED "Error al abrir el archivo " << name << RESET << endl;
        exit(1);
    }

    return data; // Se retorna el contenido del archivo
}

void write(string name, string data)
{
    // name es el nombre del archivo en el que se escribira
    // data sera el contenido del archivo

    ofstream file; // Archivo a escribir

    file.open("../data/" + name); // Se abre el archivo
    if (file.is_open()){ // Se verifica si el archivo abrio correctamente

        file << data; // Se escribe en el archivo

        file.close(); // Se cierra el archivo
    }
    else{ // Si el archivo no se pudo abrir se muestra el mensaje correspondiente y finaliza el programa
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

        if (countZero == countOne){ module = 1; } // Se comprueba si la cantidad de unos y ceros de es igual
        else if (countZero > countOne){ module = 2; } // Se comprueba si la cantidad de ceros es mayor que la de unos
        else{ module = 3; } // Este es el caso en que la cantidad de unos es mayor que la de ceros

        countOne = countZero = 0;
        /* Aqui se hace el conteo de unos y ceros de un bloque */
        for (size_t i=0; i<block.length(); ++i){ block[i] == '0' ? countZero++ : countOne++; }

        /* Aqui es donde se encripta cada bloque de n bits */
        for (size_t i=1; i<=block.length(); ++i){
            if (!(i % module)){ block[i-1] == '0' ? block[i-1] = '1' : block[i-1] = '0'; }
        }

        encrypted_data += block; // El bloque encriptado es añadido a los demas bloques que ya han sido encriptados

        /* Se quita el bloque que fue separado para su encriptacion, si ya no quedan mas bloques disponibles
         * se rompe el ciclo infinito */
        if(binary.length() > seed){ binary = binary.substr(seed, binary.length()); }
        else{ break; }
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

        if (countZero == countOne){ module = 1; } // Se comprueba si la cantidad de unos y ceros de es igual
        else if (countZero > countOne){ module = 2; } // Se comprueba si la cantidad de ceros es mayor que la de unos
        else{ module = 3; } // Este es el caso en que la cantidad de unos es mayor que la de ceros

        /* Aqui es donde se desencripta cada bloque de n bits */
        for (size_t i=1; i<=block.length(); ++i){
            if (!(i % module)){ block[i-1] == '0' ? block[i-1] = '1' : block[i-1] = '0'; }
        }

        countOne = countZero = 0;
        /* Aqui se hace el conteo de unos y ceros de un bloque */
        for (size_t i=0; i<block.length(); ++i){ block[i] == '0' ? countZero++ : countOne++; }

        decrypted_data += block; // El bloque desencriptado es añadido a los demas bloques que ya han sido desencriptados

        /* Se quita el bloque que fue separado para su desencriptacion, si ya no quedan mas bloques disponibles
         * se rompe el ciclo infinito */
        if(binary.length() > seed){ binary = binary.substr(seed, binary.length()); }
        else{ break; }
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
    // text es el texto que sera pasado a binario

    string binary; // Esto almacenara el equivalente binario del texto ingresado
    string char_to_bin; // Esto almacenara el equivalente binario de cada letra del texto
    size_t ASCII; // Valor ascii de cada letra del texto

    while(text.length()){
        char_to_bin.clear(); // Se limpia la variable que almacena los binarios de cada letra

        ASCII = text.front(); // Se toma el valor ascii de cada letra del text

        /* Aqui se calcula el equivalente binario de cada letra del texto */
        for(size_t i=0; i<8; ASCII/=2,++i){ char_to_bin += (ASCII%2) + 48; }

        /* Se invierte la cadena ya que el numero binario se encuentra al reves */
        reverse(char_to_bin.begin(), char_to_bin.end());

        binary += char_to_bin; // Se agrega el binario que se calculo a los que anteriomente ya se habian calculado

        text = text.substr(1, text.length()); // Se elimina la letra a la que ya se le calculo si equivalente binario
    }

    return binary; // Se retorna el equivalente binario del texto ingresado
}

string binary_to_text(string binary)
{
    // binary son los datos binarios que seran pasados a texto

    string text; // Esto almacenara el equivalente en texto de los datos binarios ingresados
    string bin_to_char; // Esto almacenara el equivalente en texto de un grupo de 8 bits
    size_t ASCII; // Valor ascii de cada bloque de 8 bits de los datos binarios ingresados

    while(binary.length()){
        bin_to_char = binary.substr(0, 8); // Se toman bloques de 8 bits del binario ingresado

        /* Se invierte la cadena ya que se necesita al reves el numero binario de cada letra para su conversion */
        reverse(bin_to_char.begin(), bin_to_char.end());

        ASCII = 0;

        /* Aqui se calcula el equivalente en ascii de cada bloque de 8 bits */
        for(size_t i=0; i < 8; ++i){ ASCII += (bin_to_char[i]-48) * pow(2, i); }

        text += ASCII; // Se agrega el equivalente en calacter del bloque a los demas caracteres anteriormente descifrados

        binary = binary.substr(8, binary.length()); // Se elimina el bloque que ya se procesó
    }

    return text; // Se retorna el equivalente en texto del binario ingresado
}
