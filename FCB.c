#include "FCB.h"

static DataBlock *bList[MAX_BLOCKS];

void initFCB(){

	int i;

	for(i=0; i<MAX_BLOCKS; i++) bList[i] = NULL;
	
	struct file_colntrol_block* fcb = {bList};
}


