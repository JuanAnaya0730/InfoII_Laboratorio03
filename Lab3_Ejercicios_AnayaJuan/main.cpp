#include "tools.h"

using namespace std;

int main()
{
    system("color");

    int option = menu(0); // Opcion que tomo el usuario
    string file_input; // Nombre del archivo que se codificara
    string file_output; // Nombre del archivo codificado
    int seed; // Semilla de codificacion

    if(option == 1){
        cout << YELLOW "Con que metodo desea codificar el archivo?\n" RESET << endl;
        option = menu(1);

        /* Se le pide al usuario que ingrese el nombre del archivo a codificar */
        cout << CYAN "Ingrese el nombre del archivo a codificar\n -> " GREEN;
        cin >> file_input; system("cls"); // Se limpia la consola

        /* Se le pide al usuario que ingrese la semilla de codificacion */
        cout << CYAN "Ingrese la semilla de codificacion\n ->  " GREEN;
        cin >> seed; system("cls"); // Se limpia la consola

        /* Se le pide al usuario que ingrese el nombre que desea para archivo a codificado */
        cout << CYAN "Ingrese el nombre para el archivo codificado\n -> " GREEN;
        cin >> file_output; system("cls"); // Se limpia la consola

        if(option == 1){
            /* Aqui es donde se codifica el archivo seleccionado por el usuario usando el primer metodo*/
            write(file_output, encrypt_first_method(text_to_binary(read(file_input)), seed));

        }else{
            /* Aqui es donde se codifica el archivo seleccionado por el usuario usando el segundo metodo*/
            write(file_output, encrypt_second_method(text_to_binary(read(file_input)), seed));
        }

        /* Se imprime un mensaje de comfirmacion */
        cout << YELLOW "El archivo " << file_input << " ha sido codificado con exito." RESET << endl;

    }else{
        cout << YELLOW "Con que metodo desea decodificar el archivo?\n" RESET << endl;
        option = menu(1);

        /* Se le pide al usuario que ingrese el nombre del archivo a decodificar */
        cout << CYAN "Ingrese el nombre del archivo a decodificar\n -> " GREEN;
        cin >> file_input; system("cls"); // Se limpia la consola

        /* Se le pide al usuario que ingrese la semilla de decodificacion */
        cout << CYAN "Ingrese la semilla con la que fue codificado el archivo\n ->  " GREEN;
        cin >> seed; system("cls"); // Se limpia la consola

        /* Se le pide al usuario que ingrese el nombre que desea para archivo a decodificado */
        cout << CYAN "Ingrese el nombre para el archivo decodificado\n -> " GREEN;
        cin >> file_output; system("cls"); // Se limpia la consola

        if(option == 1){
            /* Aqui es donde se decodifica el archivo seleccionado por el usuario usando el primer metodo*/
            write(file_output, binary_to_text(decrypt_first_method(read(file_input), seed)));

        }else{
            /* Aqui es donde se decodifica el archivo seleccionado por el usuario usando el segundo metodo*/
            write(file_output, binary_to_text(decrypt_second_method(read(file_input), seed)));
        }

        /* Se imprime un mensaje de comfirmacion */
        cout << YELLOW "El archivo " << file_input << " ha sido decodificado con exito." RESET << endl;
    }

    return 0;
}
