#include <iostream>
#include "../Pila/Pila.h"  // Incluye la biblioteca de la pila

using namespace std;

// Función que devuelve una nueva pila con la suma de cada elemento más n
Pila<int> sumarNro(Pila<int>& pila, int n) {
    Pila<int> pilaAux;
    Pila<int> pilaResultado;

    // Desapilar los elementos para preservar el orden y calcular la suma
    while (!pila.esVacia()) {
        int valor = pila.pop();
        pilaAux.push(valor);  // Guardar el valor en pilaAux para restaurar después
    }

    // Crear la nueva pila con los valores sumados
    while (!pilaAux.esVacia()) {
        int valor = pilaAux.pop();
        pilaResultado.push(valor + n);
    }

    // Restaurar la pila original desde pilaAux
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }

    return pilaResultado;
}

void mostrarPila(Pila<int>& pila) {
    Pila<int> pilaAux;

    // Desapilar elementos para mostrar sin perderlos
    while (!pila.esVacia()) {
        int valor = pila.pop();
        cout << valor << " ";
        pilaAux.push(valor);
    }
    cout << endl;

    // Restaurar la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
}

int main() {

    cout << "Ejercicio 03/05" << endl;

    Pila<int> pila;
    int numero, n;

    // Solicitar números enteros al usuario y almacenarlos en la pila
    cout << "Ingrese numeros enteros (ingrese -1 para terminar): " << endl;
    while (true) {
        cin >> numero;
        if (numero == -1) break;
        pila.push(numero);
    }

    // Solicitar el número entero "n"
    cout << "Ingrese el numero entero 'n': ";
    cin >> n;

    // Mostrar la pila original antes de la operación
    cout << "Pila original: ";
    mostrarPila(pila);

    // Obtener la nueva pila con los valores sumados
    Pila<int> pilaResultado = sumarNro(pila, n);

    // Mostrar la pila original después de la operación
    cout << "Pila original despues de la operacion: ";
    mostrarPila(pila);

    // Mostrar la nueva pila con los valores sumados
    cout << "Pila resultante: ";
    mostrarPila(pilaResultado);

    return 0;
}

