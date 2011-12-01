#include "FileInfo.h"
#include <stdio.h>


struct file_info* initFileInfo() {

	char* name;
	time_t created;
	time_t modified;
	struct data_block* db;

	int i;



	for(i=0; i<NAME_SIZE; i++) name[i] = NULL;

	for(i=0; i<MAX_BLOCKS; i++) db[i] = NULL;
	created = time(NULL);
	modified = time(NULL);

	struct file_info* fi = {created, modified, name, db}
	return fi;
}

