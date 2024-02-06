#include "../common/entity/Quote.hpp"

class QuoteService{
    private:
        // Repository goes here
    public:
        QuoteService(){
            // Init
        }
        quote::Quote getQuoteById(std::string id){
            quote::Quote q;
            q.id = id;
            q.text = "Lorem ipsum dolor sit amet";
            return q;
        }
};