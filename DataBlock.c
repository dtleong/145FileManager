#include "FSCommon.h"
#include "DataBlock.h"
#include <string.h>

/*  API for init_data_block()
	purpose: Initialize a new datablock
	parameters: NONE
	input preconditions: A file directory and a file control block have been created and f_open() or f_create have been called. If f_append_byte() or f_append_string() have been called and the datablock originally written to does nothave enough space and the number of datablocks associated with the file control block is equal to or less than 3, init_data_block will be called.
	output/postconditions: A pointer to the new data block is returned.
	usage: struct data_block* init_data_block()
	Principal designer: daleong
	Status: Designed, documented, implemented
*/

/*  API for data_block_append_byte()
	purpose: Appends a byte to the end of a data block
	parameters: [struct data_block* dbp] [char* byte]
	input preconditions: The data block must be initialized. The data block must not be filled.
	output/postconditions: [int] Return number of bytes appended (1 or 0).
	usage: int data_block_append_byte(struct data_block* dbp, char* byte)
	Principal designer: daleong
	Status: Designed, documented, implemented
*/

struct data_block* init_data_block() {
       char* data[MAX_BYTES];
       int i;

       for( i = 0; i < MAX_BYTES; i++) data[i] = NULL;
       struct data_block db = {data};
       struct data_block* dbp;
       dbp = &db;
       return dbp;
}

int data_block_append_byte(struct data_block* db, char* byte) {
	int i;
	for( i = 0; i < MAX_BYTES; i++)
	if( db->data[i] != NULL ) {
		continue;
	} else {
		db->data[i] = byte;
		return 1;
	}
	return 0;
}

/*  API for delete_data_block()
	purpose: Garbage collection for data[] to delete the data_block
	parameters: [struct data_block*]
	input preconditions: pointer existing to a data_block
	output/postconditions: [void] All fields in data[] equal NULL
	usage: void delete_data_block(struct data_block* db)
	Principal designer: mvigil
	Status: designed
*/
void delete_data_block(struct data_block* db) {
	int i;
	for(i=0; i<MAX_BYTES; i++) {
		db->data[i] = NULL;
	}
	return;
}
