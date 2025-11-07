#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Ejercicio #2 ---------------------------------------
void PointerGraphicator_Menu() {
    bool resp = true;
    int opcion;
    while (resp) {
        cout << "--------MENÚ--------" << endl;
        cout << "1. Agregar Categoría" << endl;
        cout << "2. Quitar Categoría" << endl;
        cout << "3. Aumentar Categoría" << endl;
        cout << "4. Decrementar Categoría" << endl;
        cout << "5. Ver Categoría" << endl;
        cout << "6. Graficar" << endl;
        cout << "7. Salir" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:
            cout << "Saliendo..." << endl;
            resp = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            resp = false;
            break;
        }
    }
}

// Ejercicio #1 ---------------------------------------
void FindMe(int dificultad) {
    int tamanio, vidas;
    switch (dificultad) {
    case 1:
        tamanio = 2; vidas = 5;
    case 2:
        tamanio = 3; vidas = 4;
    case 3:
        tamanio = 5; vidas = 3;
    case 4:
        tamanio = 6; vidas = 2;
    default:
        cout << "Dificultad ingresada invalida, 1-4" << endl;
        break;
    }
}

void FindMe_Menu() {
    bool resp = true;
    int opcion;
    int dificultad;
    while (resp) {
        cout << "Find me Please" << endl;
        cout << "1. Fácil" << endl;
        cout << "2. Medio" << endl;
        cout << "3. Difícil" << endl;
        cout << "4. Insano" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese la opción que desea elegir: " << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            FindMe(1);
        case 2:
            FindMe(2);
        case 3:
            FindMe(3);
        case 4:
            FindMe(4);
        case 5:
            cout << "Saliendo..." << endl;
            resp = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            resp = false;
            break;
        }
    }
}

void menu() {
    bool resp = true;
    int opcion;
    while (resp) {
        cout << "|*|*|*|*|*|*|*| Menú |*|*|*|*|*|*|*|" << endl;
        cout << "1. Find Me!" << endl;
        cout << "2. Pointer Graphicator" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese opcion que desea elegir: " << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            PointerGraphicator_Menu();
            break;
        case 2:
            FindMe_Menu();
            break;
        case 3:
            cout << "Saliendo..." << endl;
            resp = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            resp = false;
            break;
        }
    }
}

int main() {
    srand(time(0));
    menu();
}