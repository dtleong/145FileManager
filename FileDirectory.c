#include "FileDirectory.h"

static FileInfo* fileTable[MAX_FILES];

void initFileInfo() {

int i;

for(i=0; i<MAX_FILES; i++) fileTable[i] = NULL;
}

int fOpen(char* filename) {
/* see board pseudo code */
} 
