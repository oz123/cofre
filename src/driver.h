#include <sqlite3.h> 

int drvr_opendb(const char *, sqlite3 **conn);
int check_tables(sqlite3 *conn);
