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

        T* parseResponse(utils::SqlResponse* response, uint32_t currentRow = 0){
            T* result = NULL;
            try {
                result = new T();
                uint16_t dataOffset = response->numCols; // Data starts here

                for (uint32_t currentCol = 0; currentCol < response->numCols; currentCol++){
                    std::string fieldName(response->result[currentCol]);
                    uint32_t fieldPos = dataOffset*(currentRow+1) + currentCol;
                    std::string fieldValue = response->result[fieldPos] ? response->result[fieldPos] : "null";
                    this->populateField(result, fieldName, fieldValue);
                }
            } catch (...){
                //TODO: Handle error
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
         * @param value value to set, as string
         */
        virtual void populateField(T* resultObject, std::string fieldName, std::string value) = 0;

        // Standard retrieval methods
        T* findById(std::string id){
            std::string sqlQuery = std::string("SELECT * FROM " + this->tableName + " WHERE id = '" + id + "';");
            utils::SqlResponse* dbResponse = this->connection->execute(sqlQuery.c_str());
            return this->parseResponse(dbResponse);
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
                all.push_back(this->parseResponse(dbResponse, row));
            }
            return all;
        }
};

#endif