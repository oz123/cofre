#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include "CuTest.h"
#include "../src/driver.h"

sqlite3 *pconn ; // malloc(sizeof(sqlite3*));

    char* StrToUpper(char* str) {
        int i = 0;
        while ( str[i] != '\0'){
            str[i] = toupper(str[i]);
            i++;
            }
        return str;
    }
    
    void TestStrToUpper(CuTest *tc) {
        // This is implicit const char *input!
        // This is why it will cause segmentation fault
        // We can't change a const variable
        //char *input = "hello world";
        char input[] = "hello world";
        char* actual = StrToUpper(input);
        char* expected = "HELLO WORLD";
        CuAssertStrEquals(tc, expected, actual);
    }

    void TestDriver(CuTest *tc) {
        drvr_opendb("test_db.db", &pconn);
        drvr_check_tables(&pconn);
        CuAssertTrue(tc, ! access("test_db.db", F_OK ));
        
        char * expected = "CREATE TABLE COMPANY(ID INT PRIMARY KEY     "\
                          "NOT NULL,NAME           TEXT    NOT NULL,AGE            INT     "\
                          "NOT NULL,ADDRESS        CHAR(50),SALARY         REAL );";
        
        char * command = "sqlite3 -line test/test_db.db '.schema'";
    }

    /*void TestDriverHasTable(CuTest *tc) {
        drvr_check_tables("test_db.db");
        CuAssertTrue(tc, ! access("test_db.db", F_OK ));
    }*/
   
    CuSuite* StrUtilGetSuite() {
        CuSuite* suite = CuSuiteNew();
        SUITE_ADD_TEST(suite, TestDriver);
        SUITE_ADD_TEST(suite, TestStrToUpper);
        return suite;
    }
