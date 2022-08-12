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

/*! Esta fucion es la encargada de leer un archivo */
string read(string name);

#endif // TOOLS_H
