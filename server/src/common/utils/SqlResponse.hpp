#ifndef SQL_RESPONSE
#define SQL_RESPONSE

namespace utils{
    /* struct SqlResponse {
        int columnCount;
        char** fields;
        char** columns;
    }; */
    struct SqlResponse {
        char** result;
        int numRows;
        int numCols;
        char* errorMessage;
    };
}

#endif