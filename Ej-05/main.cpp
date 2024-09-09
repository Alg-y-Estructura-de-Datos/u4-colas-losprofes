#include <iostream>
#include "../Cola/Cola.h"
#include "../Pila/Pila.h"

using namespace std;

void separarParesEImpares(Cola<int> &cola, Pila<int> &pila) {
    if (cola.esVacia()) {
        cout << "Error: La cola está vacía." << endl;
        return;
    }

    // Cola auxiliar para almacenar los elementos pares
    Cola<int> colaAux;

    // Separar los elementos
    while (!cola.esVacia()) {
        int dato = cola.desencolar();

        if (dato % 2 == 0) {
            colaAux.encolar(dato);  // Elemento par, se mantiene en colaAux
        } else {
            pila.push(dato);  // Elemento impar, se apila
        }
    }

    // Restaurar la cola con los elementos pares
    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
    }
}

void mostrarCola(Cola<int> &cola) {
    Cola<int> colaAux;

    // Mostrar los elementos de la cola sin modificarla
    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        cout << dato << " ";
        colaAux.encolar(dato);
    }
    cout << endl;

    // Transferir los elementos de vuelta a la cola original
    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
    }
}

int main() {

    cout << "Ejercicio 04/03" << endl;

    Cola<int> cola;
    Pila<int> pila;

    // Lectura de la cola
    cout << "Ingrese numeros para la cola (ingrese -1 para terminar): " << endl;
    int input;
    while (cin >> input && input != -1) {
        cola.encolar(input);
    }

    // Separar pares e impares
    separarParesEImpares(cola, pila);

    // Mostrar el contenido de la cola después de la separación
    cout << "Cola despues de quitar numeros impares: ";
    mostrarCola(cola);

    // Mostrar el contenido de la pila
    cout << "Pila con elementos impares (orden inverso): ";
    while (!pila.esVacia()) {
        cout << pila.pop() << " ";
    }
    cout << endl;

    return 0;
}
