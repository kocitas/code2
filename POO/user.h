#ifndef USER_H
#define USER_H
#include <string>

class User{

        private: 

            std::string id_;
            std::string surname_; 
            std::string name_;
            std::string nationality_;
            int d_;
            int m_;
            int y_;
            bool complete_;

        public: 

            User(std::string id);
            User(std::string id_, std::string surname_, std::string name_, std::string nationality_, int d_, int m_, int y_, bool complete_){
                id_=id; surname_=surname; name_=name; nacionality_=nacionality; 
            }


};

#endif