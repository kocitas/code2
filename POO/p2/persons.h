#ifndef PERSONS_H
#define PERSONS_H

#include <string>

class Person {
private:
    std::string name_;
    int birth_year_;

public:
    // Constructores
    Person();                                   // Por defecto: "UNKNOWN", -1
    Person(const std::string& name, int year);  // Constructor con parámetros

    // Modificadores (setters)
    void setName(const std::string& name);
    void setBirthYear(int year);

    // Observadores (getters)
    std::string getName() const;
    int getBirthYear() const;
};


/*clase heredada cyclist*/

class Cyclist : public Person{
        
    private:
        
        std::string team_;
        std::string cyclist_id_;

    public: 

        Cyclist();
        Cyclist(const std::string name,int year ,const std::string team, const std::string cyclist_id );
    
           // Modificadores (setters)
        void setTeam(const std::string team);
        void setCyclist_id(const std::string Cyclist_id);

          // Observadores (getters)
        std::string getTeam() const;   
        std::string getCyclist_id() const;    
     
};
    class Director : public Person{
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
