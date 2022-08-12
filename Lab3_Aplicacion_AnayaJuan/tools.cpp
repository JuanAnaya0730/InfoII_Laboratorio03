#include "tools.h"

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
