#include <stdio.h>
#include <sqlite3.h> 
#include <string>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;

   rc = sqlite3_open("test.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
      
      /* const char* sql = "INSERT INTO author (id, name, picture) " \
         "VALUES ('bf321d69-afca-4ed6-9d0c-441e9a1de871', 'Marcelo Gallardo', NULL);"; */
      const char* sql = "SELECT * FROM author";
   
      rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
      if( rc != SQLITE_OK ){
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
      } else {
         fprintf(stdout, "Records created successfully\n");
      }
   }


   sqlite3_close(db);
}

void createAuthor(std::string id, std::string name){
   
}