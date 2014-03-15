#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "CuTest.h"
#include "../src/driver.h"

    char* BtrToUpper(char* str) {
        return str;
    }
    
    void TestBtrToUpper(CuTest *tc) {
        char *input = "hello world";
        char* actual = BtrToUpper(input);
        char* expected = "HELLO WORLD";
        CuAssertStrEquals(tc, expected, actual);
    }

    CuSuite* BtrUtilGetSuite() {
        CuSuite* suite = CuSuiteNew();
        SUITE_ADD_TEST(suite, TestBtrToUpper);
        return suite;
    }
