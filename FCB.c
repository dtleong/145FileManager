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

/*  API for void delete_fcb()
        purpose: Call delet on each of the data_blocks then nullify the pointers to those blocks
        parameters: [struct file_control_block* fcbp]
        input preconditions: The file control block must be initialized.
        output/postconditions: [void] The pointers to the data_blocks are nullified.
        Principal designer: mvigil
        Status: designed, documented, implemented
*/
void delete_fcb(struct file_control_block* fcb) {
	int i;
	for( i=0; i <MAX_BLOCKS; i++ ) {
		delete_data_block(fcb->db[i]);
		fcb->db[i] = NULL;
	}
	return;
}


