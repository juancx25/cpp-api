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
        
    //Define custom queries if needed
};

#endif