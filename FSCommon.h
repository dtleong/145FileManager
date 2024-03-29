#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include "disk.h"

#define MAX_BYTES 128
#define MAX_BLOCKS 4
#define NAME_SIZE 6
#define MAX_FILES 50

class Filemanager {
	struct file_directory_table[MAX_BLOCKS];

	public:
		int fMkdir(char *name);
		int fCd(char *name);
};	

FileManager::FileManager (struct file_directory_table[MAX_BLOCKS]) {
	int i;
	for ( i = 0; i < MAX_BLOCKS; i++ ) {
		file_directory_table[i] = NULL;
	}
}

/* A data_block struct definition */
struct data_block {
	char* data[MAX_BYTES];
};

/* A file_control_block defintion */
struct file_control_block {
	struct data_block* db[MAX_BLOCKS];
};

/* A file_info struct definition */
struct file_info {

        time_t created;
        time_t last_modified;
        char* file_name;
	struct file_control_block* fcb;

};

/* A file_directory struct definition */
struct file_directory {
// Should name have space allocated to it?
        char* name;
        struct file_info* file_table[MAX_FILES];
	int open_file_table[MAX_FILES];
};


char * itoa(int i);


