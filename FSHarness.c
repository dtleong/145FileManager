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
		sprintf( &value,"foo%d", i);
		
		/* Will need error handling here */
		handle[i] = f_create(fdir, value);
		if (handle[i] == -1) {
			printf("Error creating file.");
		}
		
		printf("creating file %d is %s\n",i,value);
		printf("handle[%i] = %i\n", i, handle[i]);
		/* File has 1-4 DataBlocks associated with it */
		//for ( j = 0; j < 10/*(128 * (4 * rand() % 1))*/; j++) {
			//printf("before f_append_byte\n");
			//if(handle[i] != -1) {
				//printf("Valid handle: append byte.\n");
				//f_append_byte(fdir, handle[i], i);
				//printf("after f_append_byte");
		//}
	}

	
	/* Delete some files */
	printf("deleting handle[%i] = %i\n", i = 2, handle[2]);	
	f_delete(fdir, handle[2]);
	printf("delete sucess]n");
	//f_delete(fdir,handle[7]);
	//f_append_string(fdir,handle[5], "hello, world!\n");
        //printf("all creation done\n");	
	//f_ls(fdir);
        //printf("ls on fdir\n");	
	//f_ls1(fdir,"foo4");
        //printf("ls on foo4\n");	
	//f_ls1(fdir,"foo3"); /* Should return "File not found." */
}
