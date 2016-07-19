/*

Database Adapter for SQLite

*/

#ifndef DB_H
#define DB_H
#include <stdio.h>
#include <sqlite3.h>
#include <string>
#include <algorithm>
#include <stdlib.h>

union datatype_db {

	int integer;
	char *text;
	float real;
	
};

class DB {

	private:
		sqlite3 *db;		
	public:
		DB();
		~DB();

		int close_db();
		int open_db( char *name_ ); 
		int exec_db( char *cmd );
		int create_tb( char *name_ );
		int insert_tb( char *name_ );

};
#endif
