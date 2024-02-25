#ifndef AUTHOR_REPOSITORY
#define AUTHOR_REPOSITORY

#include "BaseRepository.hpp"
#include "../common/entity/Author.hpp"
#include "../common/utils/SqlResponse.hpp"
#include "../common/utils/SqlResponseParse.cpp"
#include <string.h>
#include <iostream>

class AuthorRepository: public BaseRepository<author::Author> {
    public:
        AuthorRepository(): BaseRepository<author::Author>("author"){}

        void populateField(author::Author* resultObject, const char* columnName, const utils::SqlResponseField* field){

            if(strcmp(columnName, "id") == 0){
                resultObject->setId(utils::sqlToString(field));
                std::cout << resultObject->getId() << std::endl;
            } else if(strcmp(columnName, "name") == 0){
                resultObject->setName(utils::sqlToString(field));
                std::cout << resultObject->getName() << std::endl;
            } else if(strcmp(columnName, "picture") == 0){
                resultObject->setPicture(utils::sqlToString(field));
                std::cout << resultObject->getPicture() << std::endl;
            } else {
                //Throw error
            }
        }


    //Define custom queries if needed
};

#endif