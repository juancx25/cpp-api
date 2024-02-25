#ifndef SQL_RESPONSE_PARSE
#define SQL_RESPONSE_PARSE

#include <string>
#include "SqlResponse.hpp"

namespace utils{
    std::string sqlToString(const utils::SqlResponseField* row){
        return std::string((const char*)row->content, row->size);
    }

    uint32_t sqlToUint32(const utils::SqlResponseField* row){
        return *((uint32_t*) row->content);
    }
}

#endif