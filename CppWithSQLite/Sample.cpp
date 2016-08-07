#include "sqlite3.h"
#include <cstdio>

int main() {

	sqlite3 * conn = nullptr;

	int result = sqlite3_open(":memory:", &conn);

	if (SQLITE_OK != result)
	{
		printf("%s\n", sqlite3_errmsg(conn));
		sqlite3_close(conn);
		return result;
	}

	sqlite3_stmt * query = nullptr;

	result = sqlite3_prepare_v2(conn, 
								"select 'Hello, Andrey P!'", 
								- 1, 
								&query, 
								nullptr);

	if (SQLITE_OK!=result) {
		printf("%s\n", sqlite3_errmsg(conn));
		sqlite3_close(conn);
		return result;
	}

	while (SQLITE_ROW == sqlite3_step(query)) {
		printf("%s\n", sqlite3_column_text(query, 0));
	}


	sqlite3_finalize(query);
	sqlite3_close(conn);
	
	
}