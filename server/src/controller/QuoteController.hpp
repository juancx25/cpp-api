#ifndef QUOTE_CONTROLLER
#define QUOTE_CONTROLLER

#include <crow.h>
#include "../service/QuoteService.hpp"
#include "../common/utils/ResponseUtils.cpp"

class QuoteController {

    private:
        QuoteService* quoteService;

    public:
        QuoteController(crow::SimpleApp& app){
            this->quoteService = new QuoteService();

            CROW_ROUTE(app, "/quote/<string>").methods(crow::HTTPMethod::GET)
            ([&](std::string id){
                return response::toJson(quoteService->getQuoteById(id));
            });
            CROW_ROUTE(app, "/quotes").methods(crow::HTTPMethod::GET)
            ([&](const crow::request& req){
                return response::listToJson(quoteService->getAllQuotes(req.url_params.get("authorId=")));
            });
        }

        ~QuoteController(){
            delete this->quoteService;
        }

};

#endif