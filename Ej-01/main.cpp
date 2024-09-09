#include <iostream>
#include "../Cola/Cola.h"  // Incluye la biblioteca de la Cola

using namespace std;

bool sonIguales(Cola<char> &cola1, Cola<char> &cola2) {
    while (!cola1.esVacia() && !cola2.esVacia()) {
        if (cola1.peek() != cola2.peek()) {
            return false;
        }
        cola1.desencolar();
        cola2.desencolar();
    }

    // Si ambas colas están vacías al mismo tiempo, son iguales
    return cola1.esVacia() && cola2.esVacia();
}

int main() {

    cout << "Ejercicio 04/01" << endl;

    Cola<char> cola1;
    Cola<char> cola2;

    // Lectura de la primera cola
    cout << "Ingrese caracteres para la primera cola (ingrese '.' para terminar): " << endl;
    char input;
    while (cin >> input && input != '.') {
        cola1.encolar(input);
    }

    // Lectura de la segunda cola
    cout << "Ingrese caracteres para la segunda cola (ingrese '.' para terminar): " << endl;
    while (cin >> input && input != '.') {
        cola2.encolar(input);
    }

    // Comparación de las colas
    if (sonIguales(cola1, cola2)) {
        cout << "Las colas son iguales." << endl;
    } else {
        cout << "Las colas son diferentes." << endl;
    }

    return 0;
}
