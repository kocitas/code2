#include <iostream>
#include <limits>
#include "user.h"

// Función para leer datos del usuario
User ReadUserFromConsole() {
    std::string id, surname, name, nationality;
    int d, m, y;

    std::cout << "Introduce el id: ";
    std::getline(std::cin, id);
    std::cout << "Introduce los apellidos: ";
    std::getline(std::cin, surname);
    std::cout << "Introduce el nombre: ";
    std::getline(std::cin, name);
    std::cout << "Introduce la nacionalidad: ";
    std::getline(std::cin, nationality);

    std::cout << "Introduce el día de nacimiento: ";
    std::cin >> d;
    std::cout << "Introduce el mes de nacimiento: ";
    std::cin >> m;
    std::cout << "Introduce el año de nacimiento: ";
    std::cin >> y;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return User(id, surname, name, nationality, d, m, y);
}

// Función para imprimir datos del usuario
void PrintUserToConsole(const User &u) {
    std::cout << "\n--- Datos del usuario ---\n";
    std::cout << "ID: " << u.GetId() << "\n";
    std::cout << "Apellidos: " << u.GetSurname() << "\n";
    std::cout << "Nombre: " << u.GetName() << "\n";
    std::cout << "Nacionalidad: " << u.GetNationality() << "\n";
    std::cout << "Fecha de nacimiento: " << u.GetDay() << "/" << u.GetMonth() << "/" << u.GetYear() << "\n";
    std::cout << "--------------------------\n";
}

// Programa principal
int main() {
    std::cout << "[Paso 1] Creando objeto User...\n";
    User usuario;

    std::cout << "[Paso 2] Leyendo datos del usuario desde consola...\n";
    usuario = ReadUserFromConsole();

    std::cout << "[Paso 3] Mostrando datos del usuario...\n";
    PrintUserToConsole(usuario);

    std::cout << "Programa finalizado.\n";
    return 0;
}
