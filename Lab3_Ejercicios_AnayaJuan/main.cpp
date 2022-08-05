#include "tools.h"

using namespace std;

int main()
{
    system("color");
    int option = menu();
    string file_input, file_output;
    int seed;

    cout << "Ingrese el nombre del archivo a codificar\n -> ";
    cin >> file_input;

    system("cls");

    cout << "Ingrese la semilla de codificacion\n ->  ";
    cin >> seed;

    system("cls");

    cout << "Ingrese el nombre para el archivo codificado\n -> ";
    cin >> file_output;

    system("cls");

    if(option == 1){
        write(file_output, first_method(read(file_input), seed));
    }else{
        write(file_output, second_method(read(file_input), seed));
    }

    cout << CYAN "El archivo " << file_input << " has sido codificado con exito.\n" RESET << endl;

    return 0;
}
