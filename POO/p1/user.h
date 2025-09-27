#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string id_;
    std::string surname_;
    std::string name_;
    std::string nationality_;
    int d_, m_, y_;
    bool complete_;

public:
    // Default constructor: Initializes a User object with default values.
        User();
    User(const std::string &id, const std::string &surname, const std::string &name,
         const std::string &nationality, int d, int m, int y);

    // Getters
    std::string GetId() const;
    std::string GetSurname() const;
    std::string GetName() const;
    std::string GetNationality() const;
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
    bool GetComplete() const;

    // Setters
    bool SetId(const std::string &id);
    bool SetSurname(const std::string &surname);
    bool SetName(const std::string &name);
    bool SetNationality(const std::string &nat);
    bool SetDay(int d);
    bool SetMonth(int m);
    bool SetYear(int y);
};

#endif
