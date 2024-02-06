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
    public:
        BaseRepository(){
            this->connection = new DbConnection(consts::DB_PATH);
        }
        BaseRepository(std::string tableName){
            this->tableName = tableName;
            this->connection = new DbConnection(consts::DB_PATH);
        }

        virtual T* parseResponse(utils::SqlResponse*, uint32_t offset = 0) = 0;
        
        T* findById(std::string id){
            std::string sqlQuery = std::string("SELECT * FROM " + this->tableName + " WHERE id = '" + id + "';");
            this->connection->execute(sqlQuery.c_str());
            return this->parseResponse(this->connection->responseData, this->connection->responseData->numCols);
        }

        std::list<T*> findAll(){
            std::string sqlQuery = std::string("SELECT * FROM " + this->tableName + ";");
            this->connection->execute(sqlQuery.c_str());
            std::list<T*> all;
            for (int i = 0; i<this->connection->responseData->numRows; i++){
                all.push_back(this->parseResponse(this->connection->responseData, this->connection->responseData->numCols * (i+1)));
            }
            return all;
        }
};

#endif