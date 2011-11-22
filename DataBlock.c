#include "DataBlock.h"
#include <stdio.h>

static char *bList[MAX_BYTES];
 
void initDataBlock() {

int i;


for(i=0; i<MAX_BYTES; i++) bList[i] = NULL;

}


