#ifndef BASE_REPOSITORY
#define BASE_REPOSITORY

#include "../common/utils/DbConnection.hpp"
#include "../common/utils/SqlResponse.hpp"
#include "../common/consts/consts.cpp"
#include "../common/utils/filter/QueryFilter.hpp"
#include <list>

template <typename T> class BaseRepository {  
    protected:

        DbConnection* connection;
        std::string tableName; 
        
    private:

        T* parseResponse(utils::SqlResponseField** row, uint16_t numCols, const char** columnNames){

            T* result = NULL;
            if (row){
                result = new T();
                for (uint32_t i = 0; i < numCols; i++){
                    this->populateField(result, columnNames[i], row[i]);
                }
            }
            return result;
        }

        std::string createQueryString(filter::QueryFilter* fieldFilter = NULL, uint32_t limit = UINT32_MAX, uint64_t offset = 0){

            std::string query = "SELECT * FROM " + this->tableName;
            if (fieldFilter){
                query.append(" WHERE CAST(" + fieldFilter->getColumnName() +" AS text) " +
                filter::getOperation(fieldFilter->getOperation()) +
                " '" + fieldFilter->getFilterValue() + "'");
            }
            if (limit != UINT32_MAX){
                query.append(" LIMIT " + limit);
            }
            if (offset != 0){
                query.append(" OFFSET " + offset);
            }
            return query.append(";");
        }

    public:
    
        BaseRepository(std::string tableName){
            this->tableName = tableName;
            //Shouldn't we create a connection each time we make a query?
            this->connection = new DbConnection(consts::DB_PATH);
        }
        ~BaseRepository(){
            delete this->connection;
        }

        /**
         * @brief 
         * 
         * @param resultObject destination object where field will be populated
         * @param fieldName field name in database
         * @param value field containing the value to be set
         */
        virtual void populateField(T* resultObject, const char* columnName, const utils::SqlResponseField* field) = 0;


        T* findAny(filter::QueryFilter* fieldFilter = NULL){
            std::string sqlQuery = this->createQueryString(fieldFilter);             
            utils::SqlResponse* dbResponse = this->connection->execute(sqlQuery.c_str());
            if (dbResponse->numRows > 0){
                return this->parseResponse(dbResponse->result.front(), dbResponse->numCols, dbResponse->columnNames);
            } else {
                // This means we haven't found anything. Throw exception?
                return NULL;
            }
        }

        std::list<T*> findAll(filter::QueryFilter* fieldFilter = NULL){
            std::string sqlQuery = this->createQueryString(fieldFilter);
            std::list<T*> all;
            utils::SqlResponse* dbResponse = this->connection->execute(sqlQuery.c_str());
            for (int row = 0; row < dbResponse->numRows; row++){
                all.push_back(this->parseResponse(dbResponse->result[row], dbResponse->numCols, dbResponse->columnNames));
            }
            return all;
        }

        // Standard wrappers

        T* findById(std::string id){
            
            return this->findAny(new filter::QueryFilter("id", id, filter::ComparisonOperator::EQUAL));
        }
};

#endif