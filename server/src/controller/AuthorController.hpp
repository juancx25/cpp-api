#ifndef AUTHOR_CONTROLLER
#define AUTHOR_CONTROLLER

#include <crow.h>
#include "../service/AuthorService.hpp"
#include "../common/utils/ResponseUtils.cpp"

class AuthorController {

    private:
        AuthorService* authorService;

    public:
        AuthorController(crow::SimpleApp& app){
            this->authorService = new AuthorService();

            CROW_ROUTE(app, "/author/<string>").methods(crow::HTTPMethod::GET)
            ([&](std::string id){
                return response::toJson(this->authorService->getAuthorById(id));
            });
            CROW_ROUTE(app, "/authors").methods(crow::HTTPMethod::GET)
            ([&](){
                return response::listToJson(this->authorService->getAllAuthors());
            });
        }

        ~AuthorController(){
            delete this->authorService;
        }

};

#endif