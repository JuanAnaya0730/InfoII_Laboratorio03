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

#define USEED 4 // Esta es la semilla universal

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

struct System
{
    size_t num_admins;
    size_t num_users;
    admin *_admins_;
    user *_users_;

    System();

    void loadAdmins(void);
    void loadUsers(void);
    void addAdmin(admin new_admin);
    void addUser(user new_user);

    bool is_admin(string id);
    bool is_user(string id);

};

/*! Esta fucion es la encargada de leer un archivo */
string read(string name);

/*! Esta fucion encriptara datos binarios usando el primer metodo de encriptacion */
string encrypt_first_method(string binary, size_t seed);

/*! Esta fucion dencriptara datos binarios que fueron codificados usando
 *  el primer metodo de encriptacion */
string decrypt_first_method(string binary, size_t seed);

/*! Esta funcion se encarga de pasar un texto a su equivalente en binario */
string text_to_binary(string text);

/*! Esta funcion se encarga de pasar datos binarios a su equivalente en texto o ASCII */
string binary_to_text(string binary);

#endif // TOOLS_H
