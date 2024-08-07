#ifndef QUOTE_REPOSITORY
#define QUOTE_REPOSITORY

#include "BaseRepository.hpp"
#include "../common/entity/Quote.hpp"
#include "../common/utils/SqlResponse.hpp"
#include "../common/utils/SqlResponseParse.cpp"

class QuoteRepository: public BaseRepository<quote::Quote> {
    public:
        QuoteRepository(): BaseRepository<quote::Quote>("quote"){}

        void populateField(quote::Quote* resultObject, const char* columnName, const utils::SqlResponseField* field){

            if(strcmp(columnName, "id") == 0){
                resultObject->setId(utils::sqlToString(field));
            } else if(strcmp(columnName, "text") == 0){
                resultObject->setText(utils::sqlToString(field));
            } else if(strcmp(columnName, "author_id") == 0){
                resultObject->setAuthorId(utils::sqlToString(field));
            } else if(strcmp(columnName, "image") == 0){
                resultObject->setImage(utils::sqlToString(field));
            } else if(strcmp(columnName, "creation_date") == 0){
                resultObject->setCreationDate(utils::sqlToInt64(field));
            } else if(strcmp(columnName, "context") == 0){
                resultObject->setContext(utils::sqlToString(field));
            } else {
                //Throw error
            }
        }
        
    //Define custom queries if needed
};

#endif