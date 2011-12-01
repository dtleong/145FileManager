#include <stdio.h>

#include "disk.h"

 

static int threshold;

static char *bList[NUM_BLOCKS];

 

void initDisk() {

int i;

 

for(i=0; i<NUM_BLOCKS; i++) bList[i] = D_NULL;

threshold = (int) (RELIABILITY*PERIOD);

sleep(3);

}

 

int dRead(int addr, char *buf) {

int i;

char *bufPtr;

 

if(addr >= NUM_BLOCKS) return ERROR;

if(rand() > threshold) return ERROR;

if(bList[addr] != D_NULL) {

bufPtr = bList[addr];

for(i=0; i<BLOCK_SIZE; i++) buf[i] = *bufPtr++;

}

else

for(i=0; i<BLOCK_SIZE; i++) buf[i] = 0;

return NO_ERROR;

}

 

int dWrite(int addr, char *buf) {

int i;

char *bufPtr;

 

if(addr >= NUM_BLOCKS) return ERROR;

if(rand() > threshold) return ERROR;

if(bList[addr] == D_NULL)

bList[addr] = (char *)malloc(BLOCK_SIZE);

bufPtr = bList[addr];

for(i=0; i<BLOCK_SIZE; i++)

*bufPtr++ = buf[i];

return NO_ERROR;

}
