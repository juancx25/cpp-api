#ifndef SQL_RESPONSE
#define SQL_RESPONSE

#include <stdint.h>

namespace utils{

    struct SqlResponseField {
        void* content;
        uint32_t size;
        int dataType;
    };

    class SqlResponse {
        public:
            SqlResponse(){
                this->columnNames = NULL;
                this->errorMessage = NULL;
                this->numRows = 0;
                this->numCols = 0;
            }
            ~SqlResponse(){
                free(columnNames);
                
            }

            std::vector<SqlResponseField**> result;
            const char** columnNames;
            uint32_t numRows;
            uint16_t numCols;
            char* errorMessage;
    };
}

#endif