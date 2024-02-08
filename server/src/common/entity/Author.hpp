#ifndef AUTHOR
#define AUTHOR

#include <string>
#include <map>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace author {
    class Author{
        private:
            std::string id;
            std::string name;
            std::string picture;
        public:

            // SETTERS
            void setId(std::string id){ this->id = id; }
            void setName(std::string name){ this->name = name; }
            void setPicture(std::string picture){ this->picture = picture; }
            // GETTERS
            std::string getId(){ return this->id; }
            std::string getName(){ return this->name; }
            std::string getPicture(){ return this->picture; }

            NLOHMANN_DEFINE_TYPE_INTRUSIVE(Author, id, name, picture)
    };
}

#endif