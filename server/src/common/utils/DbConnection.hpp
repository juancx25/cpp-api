#ifndef DB_CONNECTION
#define DB_CONNECTION

#include <sqlite3.h>
#include <stdexcept>
#include "SqlResponse.hpp"

class DbConnection {
    private:
        sqlite3* db;
    public:
        DbConnection(const char* dbName){
            if (sqlite3_open(dbName, &(this->db)) != SQLITE_OK){
                throw std::runtime_error("Could not connect to database");
            }
        }
        ~DbConnection(){
            sqlite3_close(db);
        }
        utils::SqlResponse* execute(const char* sqlQuery){
            utils::SqlResponse* dbResponse = new utils::SqlResponse();
            if (sqlite3_get_table(
                    this->db,
                    sqlQuery,
                    &(dbResponse->result),
                    &(dbResponse->numRows),
                    &(dbResponse->numCols),
                    &(dbResponse->errorMessage)
                ) != SQLITE_OK){
                const char* errorMsg = dbResponse->errorMessage;
                delete dbResponse;
                // TODO: Should not be runtime exc. and probably caught somewhere else
                throw std::runtime_error(errorMsg);
            }
            return dbResponse;
        }
};

#endif