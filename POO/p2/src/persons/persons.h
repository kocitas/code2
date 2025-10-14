#ifndef PERSONS_H
#define PERSONS_H

#include <string>
/*
notas: 

1. no es necesario pasar por referencia con & ni poner const
pero es mejor acostumbrarse por si alguna vez se trabaja con cadenas largas


*/
class Person {

    private: //atributos
        std::string name_;
        int birth_year_;

    public: //metodos
        Person();
        Person(const std::string &name, int birth_year);

    //getters (observadores)

    std::string getName() const;
    int getBirthYear() const; 

    //setters (modificadores)

    void setName(const std::string &name);
    void setBirthYear(int year); 

};

//clase ciclista (herencia)

class Cyclist : public Person{

    private://atributos
        std::string team_;
        std::string cyclist_id_;

    public://metodos
        Cyclist();
        Cyclist(const std::string& name, int year,
          const std::string& team, const std::string& cyclist_id);

     //getters (observadores)
     std::string getTeam() const;
     std::string getCyclistId() const; 

       //setters (modificadores)
     void setTeam(const std::string& team);
     void setCyclistId(const std::string& cyclist_id);
};

class Director : public Person {


    private://atributos
        std::string team_;
        std::string uci_license_id_;
        int director_since_;

    public://metodos
        Director();
        Director(const std::string& name, int birth_year,
         const std::string& team, const std::string& uci_license_id,
         int director_since);

    //getters (observadores)
        std::string getTeam() const;
        std::string getUciLicenseId() const;
        int getDirectorSince() const; 

    //setters (modificadores)
    void setTeam(const std::string &team);
    void setUciLicenseId(const std::string &uci_license_id);
    void setDirectorSince(int director_since);

};
#endif // PERSONS_H
