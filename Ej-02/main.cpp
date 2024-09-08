#include <iostream>
#include "../Pila/Pila.h" // Incluye la biblioteca de la pila

using namespace std;

void Reemplazar(Pila<int>& pila, int viejo, int nuevo) {
    Pila<int> pilaAux;

    // Desapila los elementos y reemplaza los valores correspondientes
    while (!pila.esVacia()) {
        int valor = pila.pop();
        if (valor == viejo) {
            pilaAux.push(nuevo);
        } else {
            pilaAux.push(valor);
        }
    }

    // Vuelve a apilar los elementos en la pila original
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
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

    cout << "Ejercicio 03/02" << endl;

    Pila<int> pila;

    // Ejemplo: apilar algunos valores
    pila.push(3);
    pila.push(3);
    pila.push(2);
    pila.push(5);
    pila.push(3);
    pila.push(9);

    // Mostrar la pila antes del reemplazo
    cout << "Pila antes del reemplazo: ";
    mostrarPila(pila);
    cout << endl;

    // Reemplazar el valor 3 por 1
    Reemplazar(pila, 3, 1);

    // Mostrar la pila después del reemplazo
    cout << "Pila después del reemplazo: ";
    while (!pila.esVacia()) {
        cout << pila.pop() << " ";
    }
    cout << endl;

    return 0;
}

