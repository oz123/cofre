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
int drvr_opendb(const char *file_name, sqlite3 **ppconn ){
   int rc;
   rc = sqlite3_open(file_name, ppconn);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(*ppconn));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
      printf("conn %p\n" , ppconn);
   }
   return 0;
}

int drvr_check_tables(sqlite3 **pconn){
    char *zErrMsg = 0;
    int rc = 0;
    const char sql[] = "CREATE TABLE COMPANY("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "ADDRESS        CHAR(50)," \
         "SALARY         REAL );";
    
   const char *create_tbl_nodes_sql = creat_nodes;
   printf("%s\n", create_tbl_nodes_sql);
   /* Execute SQL statement */
   rc = sqlite3_exec(*pconn, create_tbl_nodes_sql, callback, 0, &zErrMsg);
   printf("rc is %d\n", rc);
   if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(*pconn);
   return 0;   
}
