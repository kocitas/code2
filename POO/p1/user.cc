#include "user.h"

// Constructor por defecto
User::User() {
    id_ = "";
    surname_ = "";
    name_ = "";
    nationality_ = "";
    d_ = 0;
    m_ = 0;
    y_ = 0;
    complete_ = false;
}

// Constructor con parámetros
User::User(const std::string &id, const std::string &surname, const std::string &name,
           const std::string &nationality, int d, int m, int y) {
    id_ = id;
    surname_ = surname;
    name_ = name;
    nationality_ = nationality;
    d_ = d;
    m_ = m;
    y_ = y;
    complete_ = !id.empty() && !surname.empty() && !name.empty() && !nationality.empty() && d > 0 && m > 0 && y > 0;
}

// Getters
std::string User::GetId() const { return id_; }
std::string User::GetSurname() const { return surname_; }
std::string User::GetName() const { return name_; }
std::string User::GetNationality() const { return nationality_; }
int User::GetDay() const { return d_; }
int User::GetMonth() const { return m_; }
int User::GetYear() const { return y_; }
bool User::GetComplete() const { return complete_; }

// Setters
bool User::SetId(const std::string &id) { if(id.empty()) return false; id_ = id; return true; }
bool User::SetSurname(const std::string &surname) { if(surname.empty()) return false; surname_ = surname; return true; }
bool User::SetName(const std::string &name) { if(name.empty()) return false; name_ = name; return true; }
bool User::SetNationality(const std::string &nat) { if(nat.empty()) return false; nationality_ = nat; return true; }
bool User::SetDay(int d) { if(d<1) return false; d_ = d; return true; }
bool User::SetMonth(int m) { if(m<1) return false; m_ = m; return true; }
bool User::SetYear(int y) { if(y<1) return false; y_ = y; return true; }
