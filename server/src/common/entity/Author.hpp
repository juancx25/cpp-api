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
            Author(){
                this->fieldMap.insert(std::make_pair("id", &Author::setId));
                this->fieldMap.insert(std::make_pair("name", &Author::setName));
                this->fieldMap.insert(std::make_pair("picture", &Author::setPicture));
            }
            std::map<std::string, void (Author::*)(std::string)> fieldMap ;/* = {
                { "id", this->setId },
                { "name", this->setName },
                { "picture", this->setPicture }
            }; */
            NLOHMANN_DEFINE_TYPE_INTRUSIVE(Author, id, name, picture)

            void setId(std::string id){
                this->id = id;
            }
            void setName(std::string name){
                this->name = name;
            }
            void setPicture(std::string picture){
                this->picture = picture;
            }

            std::string getId(){
                return this->id;
            }
            std::string getName(){
                return this->name;
            }
            std::string getPicture(){
                return this->picture;
            }
    };
}

#endif