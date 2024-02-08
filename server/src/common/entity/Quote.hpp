#ifndef QUOTE_ENTITY
#define QUOTE_ENTITY

#include "string"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace quote {
    class Quote {
        private:
            std::string id;
            std::string text;
            std::string authorId;
            std::string image;
            uint32_t creationDate;
            std::string context;
        public:
            
            // SETTERS
            void setId(std::string id){ this->id = id; }
            void setText(std::string text){ this->text = text; }
            void setAuthorId(std::string authorId){ this->authorId = authorId; }
            void setImage(std::string image){ this->image = image; }
            void setCreationDate(uint32_t creationDate){ this->creationDate = creationDate; }
            void setContext(std::string context){ this->context = context; }
            // GETTERS
            std::string getId(){ return this->id; }
            std::string getText(){ return this->text; }
            std::string getAuthorId(){ return this->authorId; }
            std::string getImage(){ return this->image; }
            uint32_t getCreationDate(){ return this->creationDate; }
            std::string getContext(){ return this->context; }

            NLOHMANN_DEFINE_TYPE_INTRUSIVE(Quote, id, text, authorId, image, creationDate, context)
    };
}

#endif