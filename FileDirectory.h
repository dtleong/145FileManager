#include "FileInfo.h"
#include <stdio.h>

#define MAX_FILES 50

/* A file_directory struct definition */
struct file_directory {
	char* name;
	FileInfo* file_table[MAX_FILES];
};

/* Initialize a directory */
void f_dir_init();

/* Make a new file system */
int f_mk_dir(struct file_directory* fd, char* filename);

/* Open a file */
int f_open(struct file_directory* fd, char* filename);

/* Close a file */
int f_close(struct file_directory* fd, char* filename);

/* Create a new file */
int f_create(struct file_directory* fd, char* filename);

/* Delete a file */
int f_delete(struct file_directory* fd, char* filename);

/* Append a byte to the end of a file */
int f_append_byte(struct file_directory* fd, int file_handle, int byte); 
