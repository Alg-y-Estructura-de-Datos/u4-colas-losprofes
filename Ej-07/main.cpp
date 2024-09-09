#include <iostream>
#include "../Cola/Cola.h"

using namespace std;

struct Documento {
    string nombre;
    int paginas;

    Documento(const string& nombre = "", int paginas = 0) : nombre(nombre), paginas(paginas) {}

    void mostrar() const {
        cout << "Documento: " << nombre << ", Paginas: " << paginas << endl;
    }
};

// Función para mostrar la cola de impresión
void mostrarCola(Cola<Documento>& cola) {
    Cola<Documento> colaAux;

    cout << "Estado actual de la cola de impresion:" << endl;
    while (!cola.esVacia()) {
        Documento doc = cola.desencolar();
        doc.mostrar();
        colaAux.encolar(doc);
    }

    // Restaurar la cola original
    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
    }
}

// Función para agregar un documento a la cola de impresión
void agregarDocumento(Cola<Documento>& cola) {
    string nombre;
    int paginas;
    cout << "Ingrese el nombre del documento: ";
    cin.ignore();  // Limpiar el buffer de entrada
    getline(cin, nombre);
    cout << "Ingrese el numero de paginas: ";
    cin >> paginas;

    Documento nuevoDoc(nombre, paginas);
    cola.encolar(nuevoDoc);
    cout << "Documento agregado a la cola de impresion." << endl;
}

// Función para imprimir el siguiente documento en la cola
void imprimirDocumento(Cola<Documento>& cola) {
    if (cola.esVacia()) {
        cout << "No hay documentos en la cola de impresion." << endl;
        return;
    }

    Documento docImpreso = cola.desencolar();
    cout << "Imprimiendo: ";
    docImpreso.mostrar();
}

int main() {
    Cola<Documento> colaImpresion;
    int opcion;

    do {
        cout << "\n--- Menu de Opciones ---\n";
        cout << "1. Mostrar cola de impresion\n";
        cout << "2. Agregar nuevo documento a la cola\n";
        cout << "3. Imprimir siguiente documento\n";
        cout << "4. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarCola(colaImpresion);
            break;
            case 2:
                agregarDocumento(colaImpresion);
            break;
            case 3:
                imprimirDocumento(colaImpresion);
            break;
            case 4:
                cout << "Saliendo del programa..." << endl;
            break;
            default:
                cout << "Opción invalida. Intentelo de nuevo." << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}