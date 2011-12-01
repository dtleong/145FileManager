#include <stdio.h>
#include "disk.h"
#include "FileDirectory.h"


int main() {

	int testfiles = 10;
	int handle[20];
	
	/* Initialize array with NULL values */
	for (int i = 0; i < 20; i++) {
		handle[i] = NULL;
	}
	
	struct file_directory *fdir;
	fdir = f_dir_init("myblock.txt");
	
	/* Make and delete files */
	for (int i = 0; i < changes; i++) {
		char *value = sprintf("foo %d", i);
		
		/* Will need error handling here */
		handle[i] = f_create(&fdir, value);
		
		/* File has 1-4 DataBlocks associated with it */
		for (int j = 0; j < (128 * (4 * rand() % 1)); j++) {
			f_append_byte(%fdir, handle[i], i);
		}
	}
	
	/* Delete some files */
	f_delete(&f_dir,handle[3]);
	f_delete(&f_dir,handle[7]);
	f_append_string(handle[5], "hello, world!\n");
	
	f_ls();
	f_ls("foo5");
	f_ls("foo3"); /* Should return "File not found." */
}
