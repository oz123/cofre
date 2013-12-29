/* vim: set expandtab ts=2 sw=2 ai: */
#include "config.h"

/* 
 * Try to open confing ...
 * if no config
 * create the path to config
 * */
int conf_file_exists (char * config_file_name){
   struct stat buf;
   int i = stat ( config_file_name, &buf );
   /* File found */
   if ( i == 0 )
      {
      return 1;
      }
   return 0;
} 

void profit(float p, float q, float tc){
    printf("\nYour profit is %.2f\n", (p * q) - tc);
}
