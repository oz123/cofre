#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cli.h"
#define RESPONSESIZE 512

void cli_ui(void){
    bool loop = true ;
    char response[RESPONSESIZE];
    while (loop) {
        fputs("cofre>", stdout);
        fgets(response, RESPONSESIZE, stdin);
        
    } 

}

