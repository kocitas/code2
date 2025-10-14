#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "persons.h"
#include "catalog.h"

int main(){
    
    CyclistCatalog cyclistCatalog;
    DirectorCatalog directorCatalog;

     // Ciclistas
    if (!cyclistCatalog.Load("../data/cyclists.csv")) {
        std::cerr << "Error al cargar cyclists.csv\n";
        return 1;
    }

    std::cout << "Número de ciclistas: " << cyclistCatalog.Size() << "\n";
    for (size_t i = 0; i < cyclistCatalog.Size(); i++) {
        const Cyclist& c = cyclistCatalog.Data()[i]; // referencia para no copiar
        std::cout << "Ciclista: "
                  << c.getName() << ", "
                  << c.getBirthYear() << ", "
                  << c.getCyclistId() << ", "
                  << c.getTeam() << "\n";
    }


  // Directores
    if (!directorCatalog.Load("../data/directors.csv")) {
        std::cerr << "Error al cargar directors.csv\n";
        return 1;
    }

    std::cout << "\nNúmero de directores: " << directorCatalog.Size() << "\n";
    for (const Director& d : directorCatalog.Data()) { // range-for con referencia
        std::cout << "Director: "
                  << d.getName() << ", "
                  << d.getBirthYear() << ", "
                  << d.getUciLicenseId() << ", "
                  << d.getTeam() << ", "
                  << d.getDirectorSince() << "\n";

    }
                  return 0;
    

}