#include <iostream>
#include <string>
#include "../Cola/Cola.h"

using namespace std;

struct Paciente {
    string nombre;
    string telefono;

    Paciente() {}  // Constructor predeterminado

    Paciente(const string& nombre, const string& telefono) : nombre(nombre), telefono(telefono) {}

    // Método para imprimir los detalles del paciente
    void imprimir() const {
        cout << "Nombre: " << nombre << ", Telefono: " << telefono << endl;
    }
};

// Función para mostrar un paciente
void mostrarPaciente(const Paciente& paciente) {
    paciente.imprimir();
}

// Función para mostrar la cola de pacientes
void mostrarCola(Cola<Paciente>& cola) {
    Cola<Paciente> colaAux;

    while (!cola.esVacia()) {
        Paciente paciente = cola.desencolar();
        mostrarPaciente(paciente);
        colaAux.encolar(paciente);
    }

    // Restaurar la cola original
    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
    }
}

// Función para agregar un paciente a la cola
void agregarPaciente(Cola<Paciente>& cola) {
    string nombre, telefono;
    cout << "Ingrese el nombre del paciente: ";
    cin.ignore();  // Limpiar el buffer de entrada
    getline(cin, nombre);
    cout << "Ingrese el telefono del paciente: ";
    getline(cin, telefono);

    Paciente nuevoPaciente(nombre, telefono);
    cola.encolar(nuevoPaciente);
    cout << "Paciente agregado exitosamente." << endl;
}

// Función para atender al siguiente paciente
void atenderPaciente(Cola<Paciente>& cola) {
    if (cola.esVacia()) {
        cout << "No hay pacientes en espera." << endl;
        return;
    }

    Paciente pacienteAtendido = cola.desencolar();
    cout << "Atendiendo a: ";
    mostrarPaciente(pacienteAtendido);
}

int main() {
    Cola<Paciente> colaPacientes;
    int opcion;

    do {
        cout << "\n--- Menu de Opciones ---\n";
        cout << "1. Mostrar pacientes en espera\n";
        cout << "2. Agregar nuevo paciente\n";
        cout << "3. Atender al siguiente paciente\n";
        cout << "4. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Pacientes en espera:\n";
                mostrarCola(colaPacientes);
                break;
            case 2:
                agregarPaciente(colaPacientes);
                break;
            case 3:
                atenderPaciente(colaPacientes);
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