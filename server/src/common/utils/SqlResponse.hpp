#ifndef SQL_RESPONSE
#define SQL_RESPONSE

#include <stdint.h>

namespace utils{
    class SqlResponse {
        public:
            ~SqlResponse(){
                if (this->result){
                    uint32_t responseLength = this->numCols*(this->numRows+1);
                    for (int i = 0; i < responseLength; i++){
                        free(this->result[i]);
                    }
                    free(result);
                }
            }

            //TODO: These should be private
            char** result;
            int numRows;
            int numCols;
            char* errorMessage;
    };
}

#endif