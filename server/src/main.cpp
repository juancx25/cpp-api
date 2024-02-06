#include <crow.h>
#include "./common/utils/ResponseUtils.cpp"
#include "./service/QuoteService.hpp"
#include "./service/AuthorService.hpp"

crow::SimpleApp app;

int main(){

    QuoteService quoteService = QuoteService();
    AuthorService* authorService = new AuthorService();

    CROW_ROUTE(app, "/quotes/<string>").methods(crow::HTTPMethod::GET)
    ([&](std::string id){
        return response::toJson(quoteService.getQuoteById(id));
    });
    CROW_ROUTE(app, "/authors/<string>").methods(crow::HTTPMethod::GET)
    ([&](std::string id){
        return response::toJson(*(authorService->getAuthorById(id)));
    });
    CROW_ROUTE(app, "/authors").methods(crow::HTTPMethod::GET)
    ([&](){
        return response::listToJson(authorService->getAllAuthors());
    });

    app.port(8080).multithreaded().run();
    
    return 0;
}