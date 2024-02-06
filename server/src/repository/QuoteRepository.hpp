#ifndef QUOTE_REPOSITORY
#define QUOTE_REPOSITORY

#include "BaseRepository.hpp"
#include "../common/entity/Quote.hpp"

class QuoteRepository: public BaseRepository<quote::Quote> {
    public:
        QuoteRepository(): BaseRepository<quote::Quote>("quote"){}
        
    //Define custom queries if needed
};

#endif