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
        std::map<const char*, void (T::*)(std::string)> fieldMap;
    public:
        BaseRepository(std::string tableName){
            this->tableName = tableName;
            this->connection = new DbConnection(consts::DB_PATH);
        }

        T* parseResponse(utils::SqlResponse* response, uint32_t row = 0){
            T* result = NULL;
            try {
                result = new T();
                if (result->fieldMap.size() != response->numCols) {} //throw error maybe?
                uint16_t offset = response->numCols + row;  // First N values are column names

                for (int i = 0; i < offset; i++){
                    std::string fieldName(response->result[i]);
                    uint32_t fieldPos = response->numCols*(row+1) + i;
                    auto setterMethod = result->fieldMap.at(fieldName);
                    if (setterMethod){
                        (result->*setterMethod)(response->result[fieldPos] ? response->result[fieldPos] : "null");
                    } else {} //throw exception 
                }
            } catch (...){
                //TODO: Handle error
            }
            return result;
        }
        
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