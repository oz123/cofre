#include <sqlite3.h> 
#ifndef DRIVER_H
#define DRIVER_H

int drvr_opendb(const char *, sqlite3 **ppconn);
int drvr_check_tables(sqlite3 **conn);


#define create_tbl_nodes "CREATE TABLE NODES (ID INTEGER PRIMARY KEY \
                          AUTOINCREMENT,DATA BLOB NOT NULL";
#define create_tbl_tags "CREATE TABLE TAGS \
                         (ID INTEGER PRIMARY KEY AUTOINCREMENT, \
                         DATA BLOB NOT NULL UNIQUE)";
#define create_tbl_lookup "CREATE TABLE LOOKUP" \
                          "(NODE INTEGER NOT NULL, TAG INTEGER NOT NULL," \
                          " PRIMARY KEY(NODE, TAG))";
#define create_tbl_key "CREATE TABLE KEY (THEKEY TEXT NOT NULL DEFAULT '')";
#define pop_key "INSERT INTO KEY VALUES('')";
#define create_tbl_db_version "CREATE TABLE DBVERSION (DBVERSION TEXT NOT NULL DEFAULT '0.4')";
#define instert_db_version "INSERT INTO DBVERSION VALUES('0.4')";

#endif
