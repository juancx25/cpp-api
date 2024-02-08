#ifndef QUOTE_REPOSITORY
#define QUOTE_REPOSITORY

#include "BaseRepository.hpp"
#include "../common/entity/Quote.hpp"

class QuoteRepository: public BaseRepository<quote::Quote> {
    public:
        QuoteRepository(): BaseRepository<quote::Quote>("quote"){}

        void populateField(quote::Quote* resultObject, std::string fieldName, std::string value){

            if(strcmp(fieldName.c_str(), "id") == 0){
                resultObject->setId(value);
            } else if(strcmp(fieldName.c_str(), "text") == 0){
                resultObject->setText(value);
            } else if(strcmp(fieldName.c_str(), "author_id") == 0){
                resultObject->setAuthorId(value);
            } else if(strcmp(fieldName.c_str(), "image") == 0){
                resultObject->setImage(value);
            } else if(strcmp(fieldName.c_str(), "creation_date") == 0){
                resultObject->setCreationDate(stoi(value));
            } else if(strcmp(fieldName.c_str(), "context") == 0){
                resultObject->setContext(value);
            } else {
                //Throw error
            }
        }
        
    //Define custom queries if needed
};

#endif