#include "disk.h"
#include "FileDirectory.h"
#include <string.h>

#define CHANGES  5 
	

int main() {

	int testfiles = 10;
	int handle[20];
	int i,j;
	char value[NAME_SIZE];

	/* Initialize array with NULL values */
	for (i = 0; i < 20; i++) {
		handle[i] = -1;
	}
	
	struct file_directory *fdir;
	fdir = f_dir_init("myblock.txt");
	
	/* Make and delete files */
	for (i = 0; i < CHANGES; i++) {
		sprintf( &value,"foo %d", i);
		
		/* Will need error handling here */
		handle[i] = f_create(fdir, value);
		
		/* File has 1-4 DataBlocks associated with it */
		for ( j = 0; j < (128 * (4 * rand() % 1)); j++) {
			f_append_byte(fdir, handle[i], i);
		}
	}
	
	/* Delete some files */
	f_delete(fdir,handle[3]);
	f_delete(fdir,handle[7]);
	f_append_string(fdir,handle[5], "hello, world!\n");
	
	f_ls(fdir);
	f_ls1(fdir,"foo5");
	f_ls1(fdir,"foo3"); /* Should return "File not found." */
}
