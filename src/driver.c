#include <stdio.h>
#include <stdlib.h>
#include "driver.h"
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
/*
 * Open the db file_name 
 * return 0 if OK
 * return 1 if not 
 * This method should also return the cursor!*/
int drvr_opendb(const char *file_name, sqlite3 **conn ){
   int rc;
   rc = sqlite3_open(file_name, conn);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(*conn));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
      printf("conn %p\n" , conn);
   }
   return 0;
}

/* not implemented yet!*/
int check_tables(sqlite3 *conn){
    char *zErrMsg = 0;
    int rc = 0;
    const char sql[] = "CREATE TABLE COMPANY("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "ADDRESS        CHAR(50)," \
         "SALARY         REAL );";

   /* Execute SQL statement */
   rc = sqlite3_exec(conn, sql, callback, 0, &zErrMsg);
   printf("rc is %d", rc);
   if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(conn);
   return 0;   
}
