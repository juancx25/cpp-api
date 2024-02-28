#ifndef SQL_RESPONSE_PARSE
#define SQL_RESPONSE_PARSE

#include <string>
#include "SqlResponse.hpp"

namespace utils{
    std::string sqlToString(const utils::SqlResponseField* row){
        return std::string((const char*)row->content, row->size);
    }

    uint64_t sqlToUint64(const utils::SqlResponseField* row){
        return *((uint64_t*) row->content);
    }
}

#endif