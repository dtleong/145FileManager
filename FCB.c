#include "FCB.h"

/*  API for init_fcb()
	purpose: Initialize a new file control block
	parameters: NONE
	input preconditions: A file directory has been created, and f_open() or f_create has been called.
	output/postsconditions: [struct file_control_block* fcbp] A pointer to the file control block is returned.
	usage: init_fcb()  
	Principal designer: daleong
	Status: Designed, documented, implemented
*/

/*  API for int fcb_append_byte()
	purpose: Appends a byte to a fcb
	parameters: [struct file_control_block* fcbp] [char* byte]
	input preconditions: The file control block must be initialized. The data block must be initialized.
	output/postconditions: [int] Return number of bytes appended (1 or 0).
	Principal designer: daleong
	Status: designed, documented, implemented
*/

struct file_control_block* init_fcb() {
	struct data_block* bList[MAX_BLOCKS];
	int i;

	for(i=0; i<MAX_BLOCKS; i++) bList[i] = NULL;
	
	struct file_control_block fcb = {bList};
	struct file_control_block* fcbp = &fcb;
	return fcbp;
}

int fcb_append_byte(struct file_control_block* fcbp, char* byte) {
	int i;
	for( i = 0; i < MAX_BLOCKS; i++ )
		if( data_block_append_byte(fcbp->db[i], byte) == 1 ) {
			return 1;
		} 
	return 0;
}
