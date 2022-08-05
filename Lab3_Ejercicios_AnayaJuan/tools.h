#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

string read(string name);
void write(string name, string data);
string first_method(string data,int seed);
string second_method(string data,int seed);
string text_to_binary(string text);

#endif // TOOLS_H
