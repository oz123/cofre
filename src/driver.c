#include <stdio.h>
#include <stdlib.h>
#include "driver.h"

/*
 * Open the db file_name 
 * return 0 if OK
 * return 1 if not 
 */
int drvr_opendb(const char *file_name ){

   sqlite3 *db;
   //char *zErrMsg = 0;
   int rc;

   rc = sqlite3_open(file_name, &db);

   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }
   return 0;
}
