//
// Created by mauri on 22/10/2023.
//

#include "Utilities.h"
//IMPRIMIR------------------------------------------------------

//RECIVIR------------------------------------------------------
string recivirString() {
    string s;
    bool fin = false;
    while (!fin) {
        try {
            if (cin >> s) {
                if (s=="" || s == " ") {
                    throw new Exceptions('s');
                }
                fin = true;
                return s;
            }
            clear();
            throw new Exceptions('s');
        }
        catch (Exceptions* e) {
            print(e->what());
        }

    }
    return " ";
}
string recivirStringN() {
    string s;
    bool fin = false;
    while (!fin) {
        try {
            if (cin >> s) {
                if (s == "salir") { //Opcion de respaldo para no quedar en un ciclo infinito
                    return s;
                }
                else {
                    for (char c : s) { //recorre cada caracter (almacenado en c) de el string 's'
                        if (!isdigit(c)) { //valida si el caracter corresponde a un digito
                            throw new Exceptions('z');

                            return "";
                        }
                    }
                    if (s == "" || s == " ") {
                        throw new Exceptions('S');
                    }
                    fin = true;
                    return s;
                }

            }
            throw new Exceptions('z'); //Error si no posee caracteres numericos
        }
        catch (Exceptions* e) {
            print(e->what());
        }
    }
    return "";
}
int recivirInt() {
    int i;
    bool fin = false;
    while (!fin){
        try{//valida que los datos ingresados por el usuario corresponden a un entero

            if (cin >> i) {
                fin = true;
                return i;
            }
            else  {
                clear();
                throw (new Exceptions('i'));
            }
        }
        catch (Exceptions* e) {
            print(e->what());
            //enter();
            //limpiar();
        }
    }
    return 0;
}
//VALIDAR------------------------------------------------------




//OTROS--------------------------------------------------------
void enter() {
    print("Preciona enter para continuar...");
#ifdef _WIN32
    system("pause");
#elif __linux__
    system("clear");
#endif
}

void clean() {
#ifdef _WIN32
    system("cls");
#else
    cin.get();
#endif
}

void clear() {
    cin.clear();
    cin.ignore(1024, '\n');
}

void ignoreCin() {
    cin.ignore(); // opcion para evitar error en getlines
}
