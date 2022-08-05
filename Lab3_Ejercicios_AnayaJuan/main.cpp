#include "tools.h"

using namespace std;

int main()
{
    system("color"); // Se configura la consola para que identifique los codigos ANSI

    int option = menu(); // Opcion que tomo el usuario
    string file_input; // Nombre del archivo que se codificara
    string file_output; // Nombre del archivo codificado
    int seed; // Semilla de codificacion

    /* Se le pide al usuario que ingrese el nombre del archivo a codificar */
    cout << CYAN "Ingrese el nombre del archivo a codificar\n -> " GREEN;
    cin >> file_input;

    system("cls"); // Se limpia la consola

    /* Se le pide al usuario que ingrese la semilla de codificacion */
    cout << CYAN "Ingrese la semilla de codificacion\n ->  " GREEN;
    cin >> seed;

    system("cls"); // Se limpia la consola

    /* Se le pide al usuario que ingrese el nombre que desea para archivo a codificado */
    cout << CYAN "Ingrese el nombre para el archivo codificado\n -> " GREEN;
    cin >> file_output;

    system("cls"); // Se limpia la consola

    if(option == 1){
        /* Se codifica el alchivo usando el primer metodo */
        write(file_output, first_method(read(file_input), seed));

    }else{
        /* Se codifica el alchivo usando el segundo metodo */
        write(file_output, second_method(read(file_input), seed));
    }

    /* Se imprime un mensaje de confirmacion */
    cout << CYAN "El archivo " << file_input << " has sido codificado con exito.\n" RESET << endl;

    return 0;
}
