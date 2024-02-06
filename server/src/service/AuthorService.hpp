#ifndef AUTHOR_SERVICE
#define AUTHOR_SERVICE

#include "../common/entity/Author.hpp"
#include "../repository/AuthorRepository.hpp"
#include <list>

class AuthorService{
    private:
        AuthorRepository* authorRepository;
    public:
        AuthorService(){
            authorRepository = new AuthorRepository();
        }
        
        author::Author* getAuthorById(std::string id){
            return this->authorRepository->findById(id);
        }

        std::list<author::Author*> getAllAuthors(){
            return this->authorRepository->findAll();
        }
};

#endif