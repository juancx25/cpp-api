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

        std::list<quote::Quote*> getAllQuotes(const char* authorId){
            filter::QueryFilter* authorIdFilter = authorId ? new filter::QueryFilter("author_id", std::string(authorId), filter::ComparisonOperator::EQUAL) : NULL;
            return quoteRepository->findAll(authorIdFilter);
        }
};