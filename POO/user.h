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
            /*sobrecarga de constructores*/
            User(std::string id)//constructor con id
            : id_(id), surname_(""), name_(""), nationality_(""), d_(0), m_(0), y_(0), complete_(false)
            {
            }
         
;


#endif