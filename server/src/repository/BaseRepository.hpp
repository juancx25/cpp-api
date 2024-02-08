#ifndef BASE_REPOSITORY
#define BASE_REPOSITORY

#include "../common/utils/DbConnection.hpp"
#include "../common/utils/SqlResponse.hpp"
#include "../common/consts/consts.cpp"
#include <list>

template <typename T> class BaseRepository {   
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
    protected:
        DbConnection* connection;
        std::string tableName;
    public:
        BaseRepository(std::string tableName){
            this->tableName = tableName;
            this->connection = new DbConnection(consts::DB_PATH);
        }

        virtual void populateField(T* resultObject, std::string fieldName, std::string value) = 0;

        
        T* findById(std::string id){
            std::string sqlQuery = std::string("SELECT * FROM " + this->tableName + " WHERE id = '" + id + "';");
            this->connection->execute(sqlQuery.c_str());
            return this->parseResponse(this->connection->responseData);
        }

        std::list<T*> findAll(){
            std::string sqlQuery = std::string("SELECT * FROM " + this->tableName + ";");
            this->connection->execute(sqlQuery.c_str());
            std::list<T*> all;
            for (int i = 0; i<this->connection->responseData->numRows; i++){
                all.push_back(this->parseResponse(this->connection->responseData, i));
            }
            return all;
        }
};

#endif