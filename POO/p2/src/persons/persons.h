#ifndef PERSONS_H
#define PERSONS_H

#include <string>

class Person {
private:
        /*se declaran las variables*/
    std::string name_;
    int birth_year_;

public:
    /*se declaran los constructores*/
    Person();                                   // Por defecto: "UNKNOWN", -1
    Person(const std::string& name, int year);  // Constructor con parámetros
    /*en los constructores se declara los string por referencia*/

    
    // Observadores (getters)
    std::string getName() const;
    int getBirthYear() const;

    // Modificadores (setters)
    void setName(const std::string& name);
    void setBirthYear(int year);

};


/*clase heredada cyclist*/

class Cyclist : public Person{//declaracion con herencia 
        
    private:
        /*se declaran las variables */
        std::string team_;
        std::string cyclist_id_;

    public: 

        Cyclist();
        Cyclist(const std::string& name, int year, const std::string& team, const std::string& id);
    
           // setters
        void setTeam(const std::string &team);
        void setCyclist_id(const std::string &Cyclist_id);

          //getters
        std::string getTeam() const;   
        std::string getCyclist_id() const;    
     
};
    class Director : public Person{//declaracion con herencia
     private:
    std::string team_;
    std::string uci_license_id_;
    int director_since_;

        public:
    Director();  
    Director(const std::string& name, int year, const std::string& team,
             const std::string& license_id, int since);

    // Setters
    void setTeam(const std::string& team);
    void setUciLicenseId(const std::string& license_id);
    void setDirectorSince(int since);

    // Getters
    std::string getTeam() const;
    std::string getUciLicenseId() const;
    int getDirectorSince() const;
};

#endif // PERSONS_H
