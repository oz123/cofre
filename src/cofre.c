/* vim: set expandtab sts=2 ts=2 sw=2 ai: */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "cofre.h"
#include "argparse.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

static const char *const usage[] = {
    "test_argparse [options] [[--] args]",
    NULL,
};


int main(int argc, const char **argv)
{
    int force = 0;
    int test = 0;
    int num = 0;
    const char *path = NULL;
    int perms = 0;
    bool has_key = false;
    char *pzErrMsg = 0;
    sqlite3 *pconn ; // malloc(sizeof(sqlite3*));
    int rc = 0;
    
    struct argparse_option options[] = {
        OPT_HELP(),
        OPT_BOOLEAN('f', "force", &force, "force to do"),
        OPT_BOOLEAN('t', "test", &test, "test only"),
        OPT_STRING('p', "path", &path, "path to read"),
        OPT_INTEGER('n', "num", &num, "selected num"),
        OPT_END(),
    };

    struct argparse argparse;
    argparse_init(&argparse, options, usage, 0);
    
    argc = argparse_parse(&argparse, argc, argv);
    if (argc < 2) {
        argparse_usage(&argparse);
    }
    if (force != 0)
        printf("force: %d\n", force);
    if (test != 0)
        printf("test: %d\n", test);
    if (path != NULL)
        printf("path: %s\n", path);
    if (num != 0)
        printf("num: %d\n", num);
    if (argc != 0) {
        printf("argc: %d\n", argc);
        int i;
        for (i = 0; i < argc; i++) {
            printf("argv[%d]: %s\n", i, *(argv + i));
        }
    }
    if (perms) {
        printf("perms: %d\n", perms);
    }

    drvr_opendb("people.db", &pconn);
    
   /* Create SQL statement */
   const char *sql = "CREATE TABLE COMPANY("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "ADDRESS        CHAR(50)," \
         "SALARY         REAL );";

   /* Execute SQL statement */
   rc = sqlite3_exec(pconn, sql, callback, 0, &pzErrMsg);
   printf("%d\n",rc);
   if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", pzErrMsg);
      sqlite3_free(pzErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(pconn);
    
    /* has_key  is initialized as false, but inside crypto_get_key
     * it is assigned true properlly */
    crypto_get_key("secret", &has_key);

    printf(has_key ? "true" : "false");
    printf("\n");

    cli_ui();
    return 0;
}


