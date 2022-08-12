#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <string>

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"

using namespace std;

struct admin
{
    string ID;
    string password;
};

struct user
{
    string ID;
    string password;
    size_t money;
};

/*! Esta fucion es la encargada de leer un archivo */
string read(string name);

/*! Esta fucion retornara una lista con los administradores que esten en sudo.txt */
string* loadAdmins(void);

#endif // TOOLS_H
