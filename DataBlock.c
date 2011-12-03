#include "FSCommon.h"
#include "DataBlock.h"

/*  API for init_data_block()
	purpose: Initialize a new datablock
	parameters: NONE
	input preconditions: A file directory and a file control block have been created and f_open() or f_create have been called. If f_append_byte() or f_append_string() have been called and the datablock originally written to does nothave enough space and the number of datablocks associated with the file control block is equal to or less than 3, init_data_block will be called.
	output/postconditions: A pointer to the new data block is returned.
	usage: struct data_block* init_data_block()
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
