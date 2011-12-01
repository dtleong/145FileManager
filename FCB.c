#include "FCB.h"

struct file_control_block* init_fcb() {
	struct data_block* bList[MAX_BLOCKS];
	int i;

	for(i=0; i<MAX_BLOCKS; i++) bList[i] = NULL;
	
	struct file_control_block fcb = {bList};
	struct file_control_block* fcbp = &fcb;
	return fcbp;
}


