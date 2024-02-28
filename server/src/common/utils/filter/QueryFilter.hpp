#ifndef QUERY_FILTERS
#define QUERY_FILTERS

#include <string>
#include "./ComparisonOperator.cpp"

namespace filter {
    class QueryFilter {
    private:
        std::string columnName;
        std::string filterValue;
        ComparisonOperator operation;
    public:
        QueryFilter(std::string columnName, std::string filterValue, ComparisonOperator operation){
            this->columnName = columnName;
            this->filterValue = filterValue;
            this->operation = operation;
        }

        std::string getColumnName(){ return this->columnName; }
        std::string getFilterValue(){ return this->filterValue; }
        ComparisonOperator getOperation(){ return this->operation; }

        void setColumnName(std::string columnName){ this->columnName = columnName; }
        void setFilterValue(std::string filterValue){ this->filterValue = filterValue; }
        void setOperation(ComparisonOperator operation){ this->operation = operation; }
    };
}

#endif