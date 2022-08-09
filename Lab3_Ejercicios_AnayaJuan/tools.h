#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"

using namespace std;

int menu(void);
string read(string name);
void write(string name, string data);
string first_method(string data,int seed);
string second_method(string data,int seed);
string text_to_binary(string text);
string binary_to_text(string binary);

#endif // TOOLS_H
