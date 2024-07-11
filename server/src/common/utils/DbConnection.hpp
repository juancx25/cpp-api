#ifndef DB_CONNECTION
#define DB_CONNECTION

#include <sqlite3.h>
#include <stdexcept>
#include <stdint.h>
#include "SqlResponse.hpp"

class DbConnection {
    private:
        static const int MAX_STEP_ATTEMPTS = 100;
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

            // Prepare and compile SQL statement
            sqlite3_stmt* preparedStatement;
            sqlite3_prepare_v3(this->db, sqlQuery, UINT32_MAX, 0, &preparedStatement, NULL);
            dbResponse->numCols = sqlite3_column_count(preparedStatement);

            // Get all column names for future reference
            dbResponse->columnNames = (const char**)malloc(sizeof(char*) * dbResponse->numCols);
            for (int col = 0; col < dbResponse->numCols; col++){
                dbResponse->columnNames[col] = sqlite3_column_name(preparedStatement, col);
            }
            
            // Step to retrieve a new row and parse its contents into the response
            int currentStepResult = SQLITE_BUSY;
            int currentStepAttempts = 0;
            while(currentStepResult == SQLITE_ROW || (currentStepResult == SQLITE_BUSY && currentStepAttempts < MAX_STEP_ATTEMPTS)) {
                currentStepResult = sqlite3_step(preparedStatement);
                switch(currentStepResult){
                    case SQLITE_ROW:
                    {
                        currentStepAttempts = 0;
                        utils::SqlResponseField** rowData = (utils::SqlResponseField**)malloc(sizeof(utils::SqlResponseField*) * dbResponse->numCols);
                        for (int i = 0; i < dbResponse->numCols; i++){
                            utils::SqlResponseField* field = (utils::SqlResponseField*)malloc(sizeof(utils::SqlResponseField));
                            const void* aux = sqlite3_column_blob(preparedStatement, i);
                            field->size = sqlite3_column_bytes(preparedStatement, i);
                            field->content = (void*) malloc(sizeof(void*)*field->size);
                            memcpy(field->content, aux, field->size);
                            field->dataType = sqlite3_column_type(preparedStatement, i);
                            rowData[i] = field;
                        }
                        dbResponse->result.push_back(rowData);
                        dbResponse->numRows++;
                        break;
                    }
                    case SQLITE_BUSY:
                    {
                        currentStepAttempts++;
                        break;
                    }
                        
                    default:
                    {
                        //TODO: Throw exception
                        break;
                    }
                }
            };
            return dbResponse;
        }
};

#endif