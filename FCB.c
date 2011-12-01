#include "FCB.h"

struct file_control_block* initFCB(){
	struct data_block* bList[MAX_BLOCKS];
	int i;

	for(i=0; i<MAX_BLOCKS; i++) bList[i] = NULL;
	
	struct file_control_block* fcb = {bList};
	return fcb;
}


