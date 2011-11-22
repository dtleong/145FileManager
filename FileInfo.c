#include "FileInfo.h"
#include <stdio.h>

static char* name[NAME_SIZE]; 
static FCB* fcb;
static time_t created;
static time_t modified;


void initFileInfo() {

int i;



for(i=0; i<NAME_SIZE; i++) name[i] = NULL;

fcb = NULL;
created = time(NULL);
modified = time(NULL);
}

