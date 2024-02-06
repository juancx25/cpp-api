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
        //TODO: Find a better way of doing this
        author::Author* parseResponse(utils::SqlResponse* response, uint32_t offset){
            author::Author* result = NULL;
            try{
                result = new author::Author();
                for (int i = offset; i < (response->numCols + offset); i++){
                    if (strcmp(response->result[0], "id") == 0){
                        result->id = response->result[i] ? response->result[i] : "null";
                    }
                    i++;
                    if (strcmp(response->result[1], "name") == 0){
                        result->name = response->result[i] ? response->result[i] : "null";
                    }
                    i++;
                    if (strcmp(response->result[2], "picture") == 0){
                        result->picture = response->result[i] ? response->result[i] : "null";
                    }
                }
            } catch (...){
                //TODO: Handle error
            }
            return result;
        }
        
    //Define more queries if needed
};

#endif