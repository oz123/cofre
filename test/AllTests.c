#include <stdlib.h>
#include <stdio.h>
#include "CuTest.h"
    
    CuSuite* StrUtilGetSuite();
    CuSuite* BtrUtilGetSuite();
    
    void RunAllTests(void) {
        CuString *output = CuStringNew();
        CuSuite* suite = CuSuiteNew();
        
        CuSuiteAddSuite(suite, StrUtilGetSuite());
        CuSuiteAddSuite(suite, BtrUtilGetSuite());
    
        CuSuiteRun(suite);
        CuSuiteSummary(suite, output);
        CuSuiteDetails(suite, output);
        printf("%s\n", output->buffer);
    }
    
    int main(void) {
        RunAllTests();
    }
