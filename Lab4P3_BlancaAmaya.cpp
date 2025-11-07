#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <locale>
using namespace std;

vector<int> categorias;

// Ejercicio #2 ---------------------------------------
// 1. Agregar =========================================
void agregarCategoria() {
    if (categorias.size() >= 10) {
        cout << "Se ha alcanzado el maximo de categorías (10)" << endl;
        return;
    }
    categorias.push_back(0);
    cout << "Categoría agregada" << endl;
}

// 2. Quitar  =========================================
void quitarCategoria() {
    if (categorias.empty()) {
        cout << "No se han creado categorías" << endl;
    }
    cout << endl;
    cout << "Categorías existentes:" << endl;
    for (int i = 0; i < categorias.size(); i++) {
        cout << "Categorías No. " << i + 1 << ": Valor = " << categorias[i] << endl;
    }
    int indice;
    cout << "Escriba categoría a eliminar: ";
    cin >> indice;

    if (indice < 1 || indice > categorias.size()) {
        cout << "Categoría invalida" << endl;
        return;
    }
    categorias.erase(categorias.begin() + indice - 1);
    cout << "Categoría eliminada exitosamente!" << endl;
}

// 3. Aumentar  =========================================
void aumentarCategoria() {
    if (categorias.empty()) {
        cout << "No se han creado categorías" << endl;
    }
    cout << endl;
    cout << "Categorías existentes:" << endl;
    for (int i = 0; i < categorias.size(); i++) {
        cout << "Categorías No. " << i + 1 << ": Valor = " << categorias[i] << endl;
    }
    int indice;
    cout << "Escriba categoría a aumentar: ";
    cin >> indice;
    if (indice < 1 || indice > categorias.size()) {
        cout << "Categoría invalida" << endl;
        return;
    }
    if (categorias[indice - 1] < 10) {
        categorias[indice - 1]++;
        cout << "Categoría aumentada" << endl;
    }
}

// 4. Decrementar  ======================================
void decrementarCategoria() {
    if (categorias.empty()) {
        cout << "No se han creado categorías" << endl;
    }
    cout << endl;
    cout << "Categorías existentes:" << endl;
    for (int i = 0; i < categorias.size(); i++) {
        cout << "Categorías No. " << i + 1 << ": Valor = " << categorias[i] << endl;
    }
    int indice;
    cout << "Escriba categoría a decrementar: ";
    cin >> indice;
    if (categorias[indice - 1] < 10) {
        categorias[indice - 1]--;
        cout << "Categoría decrementada" << endl;
    }
}

// 5. Ver Categorias ====================================
void verCategoria() {
    if (categorias.empty()) {
        cout << "No se han creado categorías" << endl;
    }
    cout << endl;
    cout << "Categorías existentes:" << endl;
    for (int i = 0; i < categorias.size(); i++) {
        cout << "Categorías No. " << i + 1 << ": Valor = " << categorias[i] << endl;
    }
}

// 6. Graficar =======================================
void graficar() {
    if (categorias.empty()) {
        cout << "No hay categorías para graficar" << endl;
        return;
    }
    cout << "Grafico de las categorías" << endl;
    const int filas = 11; // de 0-10
    const int columnas = categorias.size();
    // --> Tablero (para graficar las categorias)
    char** tablero = new char* [filas];
    for (int i = 0; i < filas; i++) {
        tablero[i] = new char [columnas];
        for (int j = 0; j < columnas; j++) {
            // Llenando el tablero/matriz con 0 segun el valor guardado en esa categoria
            if (i >= (filas - 1 - categorias[j])) {
                tablero[i][j] = '0';
            }
            else {
                tablero[i][j] = ' ';
            }
        }
    }

    // Mostrando la grafica de las categorias
    /*for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (tablero[i][j] == '0') {
                cout << "[0]";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }*/
    for (int i = 0; i < categorias.size(); i++) {
        cout << "Categorías No. " << i + 1 << " | ";
        for (int j = 0; j < categorias[i]; j++) {
            cout << "[0]";
        }
        cout << endl;
    }
    // --> Liberar memoria (6. Graficar) ================
    for (int i = 0; i < filas; i++) {
        delete[] tablero[i];
    }
    delete[] tablero;
}

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
            agregarCategoria();
            break;
        case 2:
            quitarCategoria();
            break;
        case 3:
            aumentarCategoria();
            break;
        case 4:
            decrementarCategoria();
            break;
        case 5:
            verCategoria();
            break;
        case 6:
            graficar();
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
bool validarPos(int x, int y, int z, int tamanio) {
    return (x >= 0 && x < tamanio && y >= 0 && y < tamanio && z >= 0 && z < tamanio);
}

// --> generando las posiciones
void generandoPos(int& x, int& y, int& z, int tamanio) {
    x = rand() % tamanio;
    y = rand() % tamanio;
    z = rand() % tamanio;
}

char*** crearMatriz3D(int tamanio) {
    char*** matriz = new char** [tamanio];
    for (int i = 0; i < tamanio; i++) {
        matriz[i] = new char* [tamanio];
        for (int j = 0; j < tamanio; j++) {
            matriz[i][j] = new char[tamanio];
        }
    }
    return matriz;
}

// Iniciando la matriz (vacia)
void matriz_iniciar(char*** matriz, int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio; j++) {
            for (int k = 0; k < tamanio; k++) {
                matriz[i][j][k] = ' ';
            }
        }
    }
}

// --> Liberando Memoria
void liberarMemoria(char*** matriz, int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio; j++) {
            delete[] matriz[i][j];
        }
        delete[] matriz[i];
    }
    delete[] matriz;
}


void FindMe(int dificultad) {
    int tamanio, vidas;
    switch (dificultad) {
    case 1:
        tamanio = 2; vidas = 5;
        cout << "*Fácil*" << endl;
        break;
    case 2:
        tamanio = 3; vidas = 4;
        cout << "*Medio*" << endl;
        break;
    case 3:
        tamanio = 5; vidas = 3;
        cout << "*Difícil*" << endl;
        break;
    case 4:
        tamanio = 6; vidas = 2;
        cout << "*Insano*" << endl;
        break;
    default:
        cout << "Dificultad ingresada invalida, 1-4" << endl;
        break;
    }

    // --> Creando la matriz dependiendo de la dificultad elegida
    char*** matriz = crearMatriz3D(tamanio);
    // Iniciando la matriz
    matriz_iniciar(matriz, tamanio);
    
    int x_ganadora, y_ganadora, z_ganadora;
    generandoPos(x_ganadora, y_ganadora, z_ganadora, tamanio);
    matriz[x_ganadora][y_ganadora][z_ganadora] = '0';
    bool ganado = false;
    while (vidas > 0 && !ganado) {
        cout << "Vidas: " << vidas << endl;
        cout << "Ingresa las coordenadas en las que creas que me encuentro" << endl;
        int x, y, z;
        cout << "X: "; cin >> x;
        cout << "Y: "; cin >> y;
        cout << "Z: "; cin >> z;
        // Verificando si las pos ingresadas estan fuera de rango
        if (!validarPos(x, y, z, tamanio)) {
            cout << "Coordenada fuera de rango" << endl;
            continue;
        } 
        if (x == x_ganadora && y == y_ganadora && z == z_ganadora) {
            cout << "WOW!!! ME ENCONTRASTE" << endl;
            ganado = true;
        }
        else {
            cout << "JAJAJA VUELVE A INTENTARLO" << endl;
            vidas--;
        }
    }
    if (!ganado) {
        cout << "Sorry, te quedaste sin vidas" << endl;
        cout << "Las coordenadas correctas eran: " << "X= " << x_ganadora << " Y=" << y_ganadora << " Z=" << z_ganadora << endl;
    }
    liberarMemoria(matriz, tamanio);
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
        cout << "Ingrese la opción que desea elegir: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            FindMe(1);
            break;
        case 2:
            FindMe(2);
            break;
        case 3:
            FindMe(3);
            break;
        case 4:
            FindMe(4);
            break;
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
        cout << "Ingrese opcion que desea elegir: ";
        cin >> opcion; cout << endl;
        switch (opcion) {
        case 1:
            FindMe_Menu();
            break;
        case 2:
            PointerGraphicator_Menu();
            break;
        case 3:
            cout << "Saliendo..." << endl;
            resp = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "spanish");
    srand(time(0));
    menu();
}