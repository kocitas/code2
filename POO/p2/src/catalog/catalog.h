#ifndef CATALOG_H
#define CATALOG_H

#include <string>
#include "persons.h"
#include <vector>

class CyclistCatalog{

    private: 

        std::vector<Cyclist> cyclists_;    
    
    public:
    CyclistCatalog() = default;

        bool Load(const std::string &path);
        size_t Size();
        const std::vector<Cyclist>& Data() const;


};



class DirectorCatalog{

    private: 
        
        std::vector<Director> directors_;    
    
    public:
        DirectorCatalog() = default;

        bool Load(const std::string &path);
        size_t Size();
        const std::vector<Director>& Data() const;


};

#endif // PERSONS_H
