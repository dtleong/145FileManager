#include "FCB.h"

static struct data_block* bList[MAX_BLOCKS];

struct file_control_block* initFCB(){

	int i;

	for(i=0; i<MAX_BLOCKS; i++) bList[i] = NULL;
	
	struct file_colntrol_block* fcb = {bList};
	return fcb;
}


