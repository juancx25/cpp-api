#include <string>

namespace filter {

    enum ComparisonOperator {
        EQUAL,
        GREATER_THAN,
        LESS_THAN,
        GREATER_THAN_OR_EQUAL,
        LESS_THAN_OR_EQUAL,
        NOT_EQUAL,
        BETWEEN,
        LIKE,
        IN
    };

    std::string getOperation(ComparisonOperator op){
        std::string result;
        switch (op){
            case EQUAL: result = "=";
            break;
            case GREATER_THAN: result = ">";
            break;
            case LESS_THAN: result = "<";
            break;
            case GREATER_THAN_OR_EQUAL: result = ">=";
            break;
            case LESS_THAN_OR_EQUAL: result = "<=";
            break;
            case NOT_EQUAL: result = "<>";
            break;
            case BETWEEN: result = "BETWEEN";
            break;
            case LIKE: result = "LIKE";
            break;
            case IN: result = "IN";
            break;
        }
        return result;
    }
    
}