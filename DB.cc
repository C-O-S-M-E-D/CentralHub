/*

Database Adapter for SQLite

*/

#include "DB.h"

using namespace std;

DB::DB() {

}

DB::~DB() {

}

int DB::close_db() {
	sqlite3_close(db);
}

int DB::open_db( char *name_ ) {
	
	int result = sqlite3_open( name_, &db );
	if (!result) { 
		fprintf( stderr, "Database %s couldn't be opened", name_ );	
		close_db();
		return 0;
	} else return 1;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName){

	int i = -1;
	while( ++i < argc ) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   	}
  	printf("\n");
   	return 0;
}

int DB::exec_db( char *cmd ) {

	char *err = 0;
	int result;
	char *sql = cmd;
	
	int result = sqlite3_exec( db, sql, callback, 0, &err );

	if( result != SQLITE_OK ) {
		fprintf( stderr, "SQL error %s\n", err );
		sqlite3_free( err );
		return 0;
	} 

	sqlite3_close( db );
	return 1;


}

void gettypetext( char *result, datatype_db input ) {

	*result = "TEXT";
}

int DB::create_tb( char *name_, vector<char *> *members, vector<datatype_db> *types ) {

	char *sql;
	sprintf( sql, "CREATE TABLE %s( ", name_ );

	vector<char *>::iterator itr = members->begin();
	vector<SQLTYPE>::iterator itrt = types->begin();
	while( itr != members->end() ) {

		char *type;
		gettypetext( type, *itrt );
		sprintf( sql, "%s %s TEXT", sql, *itr );
		itr++;
		itrt++;
	
		if( itr != members->end() ) sprintf( sql, "%s,", sql );
	}

	sprintf( sql, "%s);", sql );

	return exec_db( sql );
}

int DB::insert_tb( char *name_ ) {
	char *sql = "INSERT INTO TEST () VALUES ();"	
	return exec_db( sql );
}
