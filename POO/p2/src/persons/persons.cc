#include "persons.h"

/*costructor sin parametros*/
Person::Person() {
    name_ = "UNKNOWN";
    birth_year_ = -1;
}

Person::Person(const std::string& name, int year) {
    name_ = name;
    birth_year_ = year;
}

/*getter*/
std::string Person::getName() const { return name_; }
int Person::getBirthYear() const { return birth_year_; }

/*setter*/

    void setName(const std::string& name);
    void setBirthYear(int year);


/*<----clase ciclista---->*/


Cyclist::Cyclist() {//constructor 
    team_ = "UNKNOWN";
    cyclist_id_ = "UNKNOWN";
}

//constructor completo 
Cyclist::Cyclist(const std::string& name, int year, const std::string& team, const std::string& id)
    : Person(name, year) {//asi se inicializa, los atributos heredados
    team_ = team;
    cyclist_id_ = id;
}


void Cyclist::setTeam(std::string team) { team_ = team; }
void Cyclist::setCyclist_id(std::string cyclist_id) { cyclist_id_ = cyclist_id; }
std::string Cyclist::getTeam() const { return team_; }
std::string Cyclist::getCyclist_id() const { return cyclist_id_; }



/*<----Clase director---->*/

//constructor basico
Director::Director() {
    team_ = "UNKNOWN";
    uci_license_id_ = "UNKNOWN";
    director_since_ = -1;
}

//constructor completo
Director::Director(const std::string& name, int year, const std::string& team,
                   const std::string& license_id, int since)
    : Person(name, year) {
    team_ = team;
    uci_license_id_ = license_id;
    director_since_ = since;
}

//setter team 
void Director::setTeam(const std::string& team) {
    team_ = team;
}

//setter license
void Director::setUciLicenseId(const std::string& license_id) {
    uci_license_id_ = license_id;
}

//setter since
void Director::setDirectorSince(int since) {
    director_since_ = since;
}

//getter team
std::string Director::getTeam() const {
    return team_;
}

//getter license
std::string Director::getUciLicenseId() const {
    return uci_license_id_;
}

//getter since
int Director::getDirectorSince() const {
    return director_since_;
}
