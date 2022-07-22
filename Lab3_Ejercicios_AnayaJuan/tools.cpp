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
