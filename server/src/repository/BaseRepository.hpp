#ifndef BASE_REPOSITORY
#define BASE_REPOSITORY

#include "../common/utils/DbConnection.hpp"
#include "../common/utils/SqlResponse.hpp"
#include "../common/consts/consts.cpp"
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

    public:
    
        BaseRepository(std::string tableName){
            this->tableName = tableName;
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

        // Standard retrieval methods
        T* findById(std::string id){
            std::string sqlQuery = std::string("SELECT * FROM " + this->tableName + " WHERE id = '" + id + "';");
            utils::SqlResponse* dbResponse = this->connection->execute(sqlQuery.c_str());
            return this->parseResponse(dbResponse->result.front(), dbResponse->numCols, dbResponse->columnNames);
        }

        /**
         * @brief Get a LIST with all table results. NOT recommmended for long tables.
         * 
         * @return std::list<T*> a list with all parsed objects to return.
         */
        std::list<T*> findAll(){
            std::string sqlQuery = std::string("SELECT * FROM " + this->tableName + ";");
            std::list<T*> all;
            utils::SqlResponse* dbResponse = this->connection->execute(sqlQuery.c_str());
            for (int row = 0; row < dbResponse->numRows; row++){
                all.push_back(this->parseResponse(dbResponse->result[row], dbResponse->numCols, dbResponse->columnNames));
            }
            return all;
        }
};

#endif