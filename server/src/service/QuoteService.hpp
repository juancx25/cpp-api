#include "../common/entity/Quote.hpp"
#include "../repository/QuoteRepository.hpp"
#include "../common/utils/filter/QueryFilter.hpp"

class QuoteService{
    private:
        QuoteRepository* quoteRepository;
    public:
        QuoteService(){
            this->quoteRepository = new QuoteRepository();
        }
        ~QuoteService(){
            delete quoteRepository;
        }

        quote::Quote* getQuoteById(std::string id){
            return quoteRepository->findById(id);
        }

        std::list<quote::Quote*> getAllQuotesByAuthorId(std::string authorId){
            filter::QueryFilter* authorIdFilter = new filter::QueryFilter("author_id", authorId, filter::ComparisonOperator::EQUAL);
            return quoteRepository->findAll(authorIdFilter);
        }

        std::list<quote::Quote*> getAllQuotes(){
            return quoteRepository->findAll();
        }
};