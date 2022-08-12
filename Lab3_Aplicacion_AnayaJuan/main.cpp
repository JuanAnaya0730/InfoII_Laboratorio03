#include "tools.h"

using namespace std;

int main()
{
    system("color"); // Se configura la consola para que reconozca los coodigos ANSI

    System autoTeller;
    admin aux_admin;
    user aux_user;
    int option = menu(0);

    autoTeller.load();
    if(option == 1){
        cout << CYAN "Ingrese su identificacion\n -> " GREEN;
        getline(cin, aux_admin.ID); system("cls"); // Se limpia la consola

        if(autoTeller.is_admin(aux_admin.ID) != -1){
            cout << CYAN "Ingrese su contrasena\n -> " GREEN;
            getline(cin, aux_admin.password); system("cls"); // Se limpia la consola

            if(autoTeller.checkAdminPassword(aux_admin.ID, aux_admin.password)){
                while (true){
                    option = menu(1);

                    if(option == 1){
                        cout << CYAN "Ingrese la identificacion del nuevo usuario\n -> " GREEN;
                        getline(cin, aux_user.ID); system("cls"); // Se limpia la consola

                        cout << CYAN "Ingrese la contrasena para el nuevo usuario\n -> " GREEN;
                        getline(cin, aux_user.password); system("cls"); // Se limpia la consola

                        cout << CYAN "Ingrese el dinero para el nuevo usuario\n -> " GREEN;
                        cin >> aux_user.money; cin.ignore(); system("cls"); // Se limpia la consola

                        autoTeller.addUser(aux_user);

                        cout << YELLOW "El usuario ha sido agregado con exito.\n" RESET << endl;
                    }else{
                        autoTeller.save();
                        break;
                    }
                }

            }else{ cout << RED "Papi me extrana, esa no es tu contrasena." RESET << endl; }
        }else{ cout << RED "El administrador con identificacion " << aux_admin.ID << " no esta registrado.\n" RESET << endl; }
    }else{
        cout << CYAN "Ingrese su indentificacion\n -> " GREEN;
        getline(cin, aux_user.ID);  system("cls"); // Se limpia la consola

        if(autoTeller.is_user(aux_user.ID) != -1){
            cout << CYAN "Ingrese su contrasena\n -> " GREEN;
            getline(cin, aux_user.password); system("cls"); // Se limpia la consola

            if(autoTeller.checkUserPassword(aux_user.ID, aux_user.password)){
                option = menu(2);

                if(option == 1){
                    if(autoTeller._users_[autoTeller.is_user(aux_user.ID)].money - 1000 < 0){
                        cout << RED "Saldo insufisiente para consultar realizar la consulta.\n" RESET <<endl;
                    }else{
                        autoTeller._users_[autoTeller.is_user(aux_user.ID)].money -= 1000;
                        cout << GREEN "Su saldo es de " << YELLOW "$" <<
                                autoTeller._users_[autoTeller.is_user(aux_user.ID)].money << "\n" RESET << endl;
                    }
                }else{
                    cout << CYAN "Cuanto desea retirar\n -> " GREEN;
                    cin >> aux_user.money; cin.ignore(); system("cls"); // Se limpia la consola

                    if(autoTeller._users_[autoTeller.is_user(aux_user.ID)].money < aux_user.money + 1000 ||
                            autoTeller._users_[autoTeller.is_user(aux_user.ID)].money < 1000){
                        cout << RED "Su saldo es insuficiente para hacer el retiro.\n" RESET <<endl;
                    }else{
                        autoTeller._users_[autoTeller.is_user(aux_user.ID)].money -= (1000 + aux_user.money);

                        cout << YELLOW "Retiro realizado exitosamente.\n" RESET << endl;

                    }
                }

            }else{ cout << RED "Papi me extrana, esa no es tu contrasena.\n" RESET << endl; }
        }else{ cout << RED "El usuario con identificacion " << aux_user.ID << " no esta registrado.\n" RESET << endl; }

    }
    autoTeller.save();

    return 0;
}
