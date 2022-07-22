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
