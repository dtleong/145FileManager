#include "FileDirectory.h"

static file_info* file_table[MAX_FILES];

file_directory* f_dir_init(char* dir_name) {
	struct file_directory* fdp;
	int i;

	for(i=0; i<MAX_FILES; i++) file_table[i] = NULL;
	
	struct file_directory fd = { dir_name, file_table };
	fp = &fd;
	return fp;
}

int f_mk_fs(struct file_directory* fd, char* filename) {
/* This is where fcbs are initia;ized */
}

/* Open a file */
int f_open(struct file_directory* fd, char* filename){
/* Open a file named filename */
}

/* Close a file */
int f_close(struct file_directory* fd, char* filename){

}

/* Create a new file */
int f_create(struct file_directory* fd, char* filename){

}

/* Delete a file */
int f_delete(struct file_directory* fd, char* filename){

}
 
