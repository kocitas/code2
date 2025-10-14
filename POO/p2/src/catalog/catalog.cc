#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "persons.h"
#include "catalog.h"

bool CyclistCatalog::Load(const std::string& path) {
    Cyclist c;
    std::string name, birth_s, id, team;
    int birthyear = 0;
    cyclists_.clear(); // Elimina todos los elementos si hubiera
    std::ifstream in(path);
    if (!in) {
        std::cerr << "-ERROR: No se pudo abrir " << path << "\n";
        return false;
    }
    std::string line;
    if (!std::getline(in, line)) return false; // saltar cabecera
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line); // Define un stream de lectura a partir de line
        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, id, ',')) continue;
        if (!std::getline(iss, team)) continue;
        birthyear = std::stoi(birth_s);
        c.setName(name);
        c.setBirthYear(birthyear);
        c.setCyclistId(id);
        c.setTeam(team);
        cyclists_.push_back(c); // se hace una copia al final del vector
    }
    return !cyclists_.empty();
}


//creamos los metodos 

size_t CyclistCatalog::Size(){
    return cyclists_.size();
}

const std::vector<Cyclist>&CyclistCatalog::Data() const{
    return cyclists_;
}



bool DirectorCatalog::Load(const std::string& path) {
    Director d;
    std::string name, birth_s, uci_license_id, team,since;
    int birthyear = 0, director_since;
    directors_.clear(); // Elimina todos los elementos si hubiera
    std::ifstream in(path);
    if (!in) {
        std::cerr << "-ERROR: No se pudo abrir " << path << "\n";
        return false;
    }
    std::string line;
    if (!std::getline(in, line)) return false; // saltar cabecera
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line); // Define un stream de lectura a partir de line
        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, uci_license_id, ',')) continue;
        if (!std::getline(iss, team, ',')) continue;
        if (!std::getline(iss, since)) continue;
        director_since = std::stoi(since);
        birthyear = std::stoi(birth_s);
       d.setName(name);
       d.setBirthYear(birthyear);
       d.setUciLicenseId(uci_license_id);
       d.setTeam(team);
       d.setDirectorSince(director_since);
;
        directors_.push_back(d); // se hace una copia al final del vector
    }
    return !directors_.empty();
}
size_t DirectorCatalog::Size() {
    return directors_.size();
}

const std::vector<Director>& DirectorCatalog::Data() const {
    return directors_;
}



