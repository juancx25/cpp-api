#include <crow.h>
#include "./common/utils/ResponseUtils.cpp"
#include "./service/QuoteService.hpp"
#include "./service/AuthorService.hpp"
#include "./common/utils/filter/QueryFilter.hpp"

crow::SimpleApp app;

int main(){

    QuoteService* quoteService = new QuoteService();
    AuthorService* authorService = new AuthorService();

    // TODO: Implement controllers
    CROW_ROUTE(app, "/quote/<string>").methods(crow::HTTPMethod::GET)
    ([&](std::string id){
        return response::toJson(quoteService->getQuoteById(id));
    });
    CROW_ROUTE(app, "/quotes").methods(crow::HTTPMethod::GET)
    ([&](const crow::request& req){
        const char* authorId = req.url_params.get("authorId=");
        return authorId ? response::listToJson(quoteService->getAllQuotesByAuthorId(std::string(authorId))) : response::listToJson(quoteService->getAllQuotes());
    });
    
    CROW_ROUTE(app, "/author/<string>").methods(crow::HTTPMethod::GET)
    ([&](std::string id){
        return response::toJson(authorService->getAuthorById(id));
    });
    CROW_ROUTE(app, "/authors").methods(crow::HTTPMethod::GET)
    ([&](){
        return response::listToJson(authorService->getAllAuthors());
    });

    app.port(8090).multithreaded().run();

    delete quoteService;
    delete authorService;
    
    return 0;
}
