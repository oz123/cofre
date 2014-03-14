#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cli.h"
#define CHARSIZE 20


void cli_ui(void){
    bool loop = true ;
    char response[CHARSIZE];
    while (loop) {
    puts("cofre>");
    fgets(response, CHARSIZE, stdin);
    }

}

