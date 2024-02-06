#include "../common/entity/Quote.hpp"
#include "../repository/QuoteRepository.hpp"

class QuoteService{
    private:
        QuoteRepository* quoteRepository;
    public:
        QuoteService(){
            this->quoteRepository = new QuoteRepository();
        }
        quote::Quote* getQuoteById(std::string id){
            return quoteRepository->findById(id);
        }
        std::list<quote::Quote*> getAllQuotes(){
            return quoteRepository->findAll();
        }
};