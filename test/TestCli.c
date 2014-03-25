#define _POSIX_C_SOURCE  2
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include "CuTest.h"
#include "../src/driver.h"

sqlite3 *pconn;
#define DATA_SIZE 512
 
void get_sqlite_data(char *out){
    FILE *pf;
    
    // Execute a process listing
    char *command = "sqlite3 -line test_db.db '.schema'";
    
    // Setup our pipe for reading and execute our command.
    pf = popen(command,"r"); 
 
    if(!pf){
      fprintf(stderr, "Could not open pipe for output.\n");
      return;
    }
 
    // Grab data from process execution
    fgets(out, DATA_SIZE , pf);
 
    if (pclose(pf) != 0)
        fprintf(stderr," Error: Failed to close command stream \n");
 
    return;
}

char* StrToUpper(char* str) {
        int i = 0;
        while ( str[i] != '\0'){
            str[i] = toupper(str[i]);
            i++;
            }
        return str;
    }
    
void TestStrToUpper(CuTest *tc) {
        // char *input = "hello world";
        // This is implicit const char *input!
        // This is why it will cause segmentation fault
        // We can't change a const variable
        char input[] = "hello world";
        char* actual = StrToUpper(input);
        char* expected = "HELLO WORLD";
        CuAssertStrEquals(tc, expected, actual);
    }

void 
TestDriver(CuTest *tc) {
     drvr_opendb("test_db.db", &pconn);
     drvr_check_tables(&pconn);
     CuAssertTrue(tc, ! access("test_db.db", F_OK ));
     char output[512];
     get_sqlite_data(output);
     printf("this is the output: %s", output);
     char * expected = "CREATE TABLE COMPANY(ID INT PRIMARY KEY     "\
                       "NOT NULL,NAME           TEXT    NOT NULL,AGE            INT     "\
                       "NOT NULL,ADDRESS        CHAR(50),SALARY         REAL );";
        

}

    CuSuite* StrUtilGetSuite() {
        CuSuite* suite = CuSuiteNew();
        SUITE_ADD_TEST(suite, TestDriver);
        SUITE_ADD_TEST(suite, TestStrToUpper);
        return suite;
    }
