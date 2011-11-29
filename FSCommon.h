#include <stdio.h>

#define MAX_BYTES 128
#define MAX_BLOCKS 4
#define NAME_SIZE 6
#define MAX_FILES 50

/* A data_block struct definition */
struct data_block {
	char* data[MAX_BYTES];
};

/* A file_info struct definition */
struct file_info {

        time_t created;
        time_t last_modified;
        char* file_name;
	struct data_block* blocks[MAX_BLOCKS];

};

/* A file_directory struct definition */
struct file_directory {
        char* name;
        struct file_info* file_table[MAX_FILES];
};

