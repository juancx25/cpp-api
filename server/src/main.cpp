#include <crow.h>
//#include "./common/utils/filter/QueryFilter.hpp"
#include "./controller/AuthorController.hpp"
#include "./controller/QuoteController.hpp"

crow::SimpleApp application;

int main(){

    // Instantiate controllers
    AuthorController* authorController = new AuthorController(application);
    QuoteController* quoteController = new QuoteController(application);

    // Run application with configurations
    application
        .port(8090)
        .multithreaded()
        .run();

    // Clear memory after quitting
    delete authorController;
    delete quoteController;
    
    return 0;
}
