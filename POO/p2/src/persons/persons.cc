#include "persons.h"

/*
notas: 

1. al igual que en el header se pasan las cosas por referencia para mayor eficiencia

2. al inicializar los construcotres se puede hacer asi: 

Person::Person(int name){name_=name}

pero es mas eficiente hacerlo Person::Person(int name) : name_(name) puesto que se
ejecuta en un solo paso 
*/


/*<----CLASE PERSON---->*/

//Constructor por defecto
Person::Person() : name_("UNKNOWN"), birth_year_(-1){}

//Constructor con parametros
Person::Person(const std::string &name, int year) : name_(name), birth_year_(year) {}

//getters (observadores)
std::string Person::getName() const {return name_;}
int Person::getBirthYear() const { return birth_year_; }

//setters (modificadores)
void Person::setName(const std::string& name) { name_ = name; }
void Person::setBirthYear(int year) { birth_year_ = year; }

/*<----CLASE CYCLIST---->*/


//constructor por defecto
Cyclist::Cyclist() : Person(), team_("UNKNOWN"), cyclist_id_("UNKNOWN") {}

//Para inicializar un hijo en el constructor se pone Person(---), atr1(), atr2()

//constructor con parametros
Cyclist::Cyclist(const std::string& name, int year,
                 const std::string& team, const std::string& cyclist_id)
    : Person(name, year), team_(team), cyclist_id_(cyclist_id) {}

// Getters (observadores)
std::string Cyclist::getTeam() const { return team_; }
std::string Cyclist::getCyclistId() const { return cyclist_id_; }

// Setters (modificadores)
void Cyclist::setTeam(const std::string& team) { team_ = team; }
void Cyclist::setCyclistId(const std::string& cyclist_id) { cyclist_id_ = cyclist_id; }


/*<----CLASE DIRECTOR----> */

Director::Director()
    : Person(), team_("UNKNOWN"), uci_license_id_("UNKNOWN"), director_since_(-1) {}

//Para inicializar un hijo en el constructor se pone Person(---), atr1(), atr2()

Director::Director(const std::string& name, int year,
                   const std::string& team, const std::string& uci_license_id,
                   int director_since)
    : Person(name, year), team_(team), uci_license_id_(uci_license_id), director_since_(director_since) {}


// Getters (observadores)
std::string Director::getTeam() const { return team_; }
std::string Director::getUciLicenseId() const { return uci_license_id_; }
int Director::getDirectorSince() const { return director_since_; }

// Setters (modificadores)
void Director::setTeam(const std::string& team) { team_ = team; }
void Director::setUciLicenseId(const std::string& uci_license_id) { uci_license_id_ = uci_license_id; }
void Director::setDirectorSince(int director_since) { director_since_ = director_since; }