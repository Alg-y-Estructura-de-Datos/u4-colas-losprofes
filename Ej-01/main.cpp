#include <iostream>
#include "../Pila/Pila.h"  // Incluye la biblioteca de la pila

using namespace std;

int main() {

    cout << "Ejercicio 03/01" << endl;

    Pila<char> pila;
    char caracter;

    cout << "Ingrese una palabra o frase (termine con un punto): ";

    // Lee caracteres hasta que se ingrese un punto
    do {
        cin.get(caracter);
        if (caracter != '.') {
            pila.push(caracter);
        }
    } while (caracter != '.');

    cout << "Palabra o frase invertida: ";

    // Desapila cada caracter y lo imprime, invirtiendo así la palabra o frase
    while (!pila.esVacia()) {
        cout << pila.pop();
    }

    cout << endl;

    return 0;
}

