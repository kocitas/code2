#include "persons.h"
#include <iostream>
#include <limits>//para usar cin.ignore

// Función para leer datos del usuario
Person ReadPersonFromConsole() {
    std::string name;
    int y;

    std::cout << "Introduce el nombre: ";
    std::getline(std::cin, name);

    std::cout << "Introduce el año de nacimiento: ";
    std::cin >> y;

    //limpiar el buffer para que no quede \n
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return Person(name, y);
}

// Función para leer datos del usuario
Cyclist ReadCyclistFromConsole() {
    std::string name, team, id;
    int y;

    std::cout << "Introduce el nombre: ";
    std::getline(std::cin, name);

    std::cout << "Introduce el team: ";
    std::getline(std::cin, team);

    std::cout << "Introduce el id: ";
    std::getline(std::cin, id);

    std::cout << "Introduce el año de nacimiento: ";
    std::cin >> y;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return Cyclist(name, y, team, id);
}

// Función para leer datos del usuario
Director ReadDirectorFromConsole() {
    std::string name, team, license;
    int y, since;

    std::cout << "Introduce el nombre: ";
    std::getline(std::cin, name);

    std::cout << "Introduce el team: ";
    std::getline(std::cin, team);

    std::cout << "Introduce la licencia: ";
    std::getline(std::cin, license);

    std::cout << "Introduce el año de nacimiento: ";
    std::cin >> y;

    std::cout << "Introduce desde cuándo eres director: ";
    std::cin >> since;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return Director(name, y, team, license, since);
}

// Función para imprimir datos del usuario
void PrintPersonToConsole(const Person& p) {
    std::cout << "\n--- Datos de la persona ---\n";
    std::cout << "Nombre: " << p.getName() << "\n";
    std::cout << "Año de nacimiento: " << p.getBirthYear() << "\n";
    std::cout << "--------------------------\n";
}

// Función para imprimir datos del usuario
void PrintCyclistToConsole(const Cyclist& c) {
    std::cout << "\n--- Datos del ciclista ---\n";
    std::cout << "Nombre: " << c.getName() << "\n";
    std::cout << "Año de nacimiento: " << c.getBirthYear() << "\n";
    std::cout << "Team: " << c.getTeam() << "\n";
    std::cout << "ID: " << c.getCyclistId() << "\n"; // ✅ camelCase
    std::cout << "--------------------------\n";
}

// Función para imprimir datos del usuario
void PrintDirectorToConsole(const Director& d) {
    std::cout << "\n--- Datos del director ---\n";
    std::cout << "Nombre: " << d.getName() << "\n";
    std::cout << "Año de nacimiento: " << d.getBirthYear() << "\n";
    std::cout << "Equipo: " << d.getTeam() << "\n";
    std::cout << "Licencia UCI: " << d.getUciLicenseId() << "\n";
    std::cout << "Director desde: " << d.getDirectorSince() << "\n";
    std::cout << "--------------------------\n";
}

int main() {
    std::cout << "CREANDO OBJETOS...." << std::endl;

    Person p = ReadPersonFromConsole();
    Cyclist c = ReadCyclistFromConsole();
    Director d = ReadDirectorFromConsole();

    // Mostrar los datos
    PrintPersonToConsole(p);
    PrintCyclistToConsole(c);
    PrintDirectorToConsole(d);

    return 0;
}
