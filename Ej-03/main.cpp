#include <iostream>
#include "../Cola/Cola.h"

using namespace std;

void eliminarOcurrencias(Cola<int> &cola, int numero) {
    Cola<int> colaAux;
    bool encontrado = false;
    bool numeroEncontrado = false; // Para verificar si el número existe en la cola

    // Recorremos la cola original
    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        if (dato == numero) {
            if (!encontrado) {
                colaAux.encolar(dato);  // Encolamos la primera ocurrencia
                encontrado = true;      // Marcamos que hemos encontrado la primera ocurrencia
            }
            numeroEncontrado = true;
        } else {
            colaAux.encolar(dato);      // Encolamos todos los demás números que no son iguales a "numero"
        }
    }

    // Si no se encontró el número, mostramos un mensaje de error
    if (!numeroEncontrado) {
        cout << "Error: El número " << numero << " no está presente en la cola." << endl;
    }

    // Transferir de nuevo los elementos a la cola original desde la auxiliar
    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
    }
}

int main() {

    cout << "Ejercicio 04/03" << endl;

    Cola<int> cola;
    int numero;

    // Lectura de la cola
    cout << "Ingrese numeros para la cola (ingrese -1 para terminar): " << endl;
    int input;
    while (cin >> input && input != -1) {
        cola.encolar(input);
    }

    // Lectura del número
    cout << "Ingrese el numero a eliminar: ";
    cin >> numero;

    // Eliminar las ocurrencias excepto la primera
    eliminarOcurrencias(cola, numero);

    // Mostrar la cola final
    cout << "Cola final: ";
    while (!cola.esVacia()) {
        cout << cola.desencolar() << " ";
    }
    cout << endl;

    return 0;
}
