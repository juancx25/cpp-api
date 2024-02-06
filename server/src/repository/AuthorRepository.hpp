#ifndef AUTHOR_REPOSITORY
#define AUTHOR_REPOSITORY

#include "BaseRepository.hpp"
#include "../common/entity/Author.hpp"
#include "../common/utils/DbConnection.hpp"
#include "../common/utils/SqlResponse.hpp"
#include <string.h>

class AuthorRepository: public BaseRepository<author::Author> {
    public:
        AuthorRepository(): BaseRepository<author::Author>(){
            this->tableName = std::string("author");
        }

        author::Author* parseResponse(utils::SqlResponse* response, uint32_t row = 0){
            author::Author* result = NULL;
            try {
                result = new author::Author();
                if (result->fieldMap.size() != response->numCols) {} //throw error maybe?
                uint16_t offset = response->numCols + row;  // First N values are column names

                for (int i = 0; i < offset; i++){
                    std::string fieldName(response->result[i]);
                    auto setterMethod = result->fieldMap.at(fieldName);
                    if (setterMethod){
                        (result->*setterMethod)(response->result[response->numCols+i] ? response->result[response->numCols+i] : "null");
                    } else {} //throw exception 
                }
            } catch (...){
                //TODO: Handle error
            }
            return result;
        }
        
    //Define more queries if needed
};

#endif