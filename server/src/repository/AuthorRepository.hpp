#ifndef AUTHOR_REPOSITORY
#define AUTHOR_REPOSITORY

#include "BaseRepository.hpp"
#include "../common/entity/Author.hpp"
#include "../common/utils/DbConnection.hpp"
#include "../common/utils/SqlResponse.hpp"
#include <string.h>

class AuthorRepository: public BaseRepository<author::Author> {
    public:
        AuthorRepository(): BaseRepository<author::Author>("author"){}

        void populateField(author::Author* resultObject, std::string fieldName, std::string value){

            if(strcmp(fieldName.c_str(), "id") == 0){
                resultObject->setId(value);
            } else if(strcmp(fieldName.c_str(), "name") == 0){
                resultObject->setName(value);
            } else if(strcmp(fieldName.c_str(), "picture") == 0){
                resultObject->setPicture(value);
            } else {
                //Throw error
            }
        }


    //Define custom queries if needed
};

#endif