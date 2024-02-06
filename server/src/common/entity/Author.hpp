#ifndef AUTHOR
#define AUTHOR

#include "string"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace author {
    class Author{//TODO: Private?
        public:
        
            std::string id;
            std::string name;
            std::string picture;
            NLOHMANN_DEFINE_TYPE_INTRUSIVE(Author, id, name, picture)
    };
}

#endif