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

struct file_control_block* init_fcb() {
	struct data_block* bList[MAX_BLOCKS];
	int i;

	for(i=0; i<MAX_BLOCKS; i++) bList[i] = NULL;
	
	struct file_control_block fcb = {bList};
	struct file_control_block* fcbp = &fcb;
	return fcbp;
}


