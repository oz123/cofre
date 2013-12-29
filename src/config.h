/* vim: set expandtab ts=2 sw=2 ai: */

/* use ndvilla ini parser 
 * https://github.com/ndevilla/iniparser.git */
#include <iniparser.h>

/* we use these to find if a file exists */
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int conf_file_exists(char *);
void profit(float , float , float );

