#include <iostream>
#include "../Pila/Pila.h"  // Incluye la biblioteca de la pila

using namespace std;

// Función que suma los elementos de la pila hasta encontrar el número n
int sumarHastaN(Pila<int>& pila, int n) {
    Pila<int> pilaAux;
    int suma = 0;
    bool encontrado = false;

    // Desapilar elementos para sumar y verificar la posición de "n"
    while (!pila.esVacia()) {
        int valor = pila.pop();
        if (valor == n) {
            encontrado = true;
            pilaAux.push(valor);  // Guarda el valor "n" en la pila auxiliar
            break;
        } else {
            suma += valor;
            pilaAux.push(valor);
        }
    }

    // Restaurar la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }

    // Si "n" no se encuentra, sumar los elementos restantes
    if (!encontrado) {
        // Al reponer los elementos en la pila, la pilaAux estará vacía y no podemos sumarla directamente
        // Desapilamos de nuevo para sumar
        int sumaTotal = 0;
        while (!pila.esVacia()) {
            sumaTotal += pila.pop();
        }
        // Restaurar la pila original después de sumar
        while (!pilaAux.esVacia()) {
            pila.push(pilaAux.pop());
        }
        return sumaTotal;
    }

    return suma;
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

    cout << "Ejercicio 03/04" << endl;

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

    // Mostrar la pila antes de la operación
    cout << "Pila antes de sumar: ";
    mostrarPila(pila);

    // Sumar los elementos según la posición de "n"
    int suma = sumarHastaN(pila, n);

    // Mostrar el resultado de la suma
    cout << "La suma de los elementos es: " << suma << endl;

    return 0;
}