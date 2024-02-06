#ifndef DB_CONNECTION
#define DB_CONNECTION

#include <sqlite3.h>
#include <string>
#include <stdexcept>
#include "SqlResponse.hpp"
#include <string.h>

static int callback(void *data, int argc, char **argv, char **azColName);
//static int setResponseData(void* object, int columnCount, char** fields, char** columns);
char** copyStrArr(char** oldArr, int len);

class DbConnection {
    private:
        sqlite3* db;
    public:
        utils::SqlResponse* responseData;

        DbConnection(const char* dbName){
            if (sqlite3_open(dbName, &(this->db)) != SQLITE_OK){
                throw std::runtime_error("Could not connect to database");
            }
            this->responseData = new utils::SqlResponse();
        }
        ~DbConnection(){
            sqlite3_close(db);
        }

        /* void execute(const char* sqlQuery){
            //TODO: Handle errors
            if (sqlite3_exec(this->db, sqlQuery, setResponseData, this->responseData, NULL) != SQLITE_OK){
                throw std::runtime_error("Error trying to access the DB");
            }
        } */
        void execute(const char* sqlQuery){
            
            if (sqlite3_get_table(this->db, sqlQuery, &(this->responseData->result), &(this->responseData->numRows), &(this->responseData->numCols), &(this->responseData->errorMessage)) != SQLITE_OK){
                throw std::runtime_error("Error trying to access the DB");
            }
        }
};

static int printDBResponse(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}


//TODO: Move this?
/* static int setResponseData(void* object, int columnCount, char** fields, char** columns){
    printDBResponse(object, columnCount, fields, columns);
    utils::SqlResponse* responseData = (utils::SqlResponse*) object;
    responseData->columnCount = columnCount;
    responseData->fields = fields;//copyStrArr(fields, columnCount);
    responseData->columns =columns; //copyStrArr(columns, columnCount);
    return 0;
} */

char** copyStrArr(char** oldArr, int len){
    char** newArray = (char**) malloc(sizeof(char*) * len);
    for (int j=0;j<len;j++){
        newArray[j] = (char*) malloc((strlen(oldArr[j]) + 1) * sizeof(char));
        strcpy(newArray[j], oldArr[j]);
    }
    return newArray;
}

#endif