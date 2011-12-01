#include "FileInfo.h"
#include <string.h>


/*  API for init_file_info()
        purpose: Create a new file_info
        parameters: [char* filename]
        input preconditions: NONE
        output/postconditions: [struct file_info* fi] A pointer to the new file_info struct is returned.
        usage: struct file_info* init_file_info(char* filename)
        Principal designer: mvigil
        Status: Designed, documented, implemented
*/

struct file_info* init_file_info(char *name) {

	time_t created;
	time_t modified;
	char fname[NAME_SIZE];
	struct file_control_block* fcb;

	int i;

	created = time(NULL);
	modified = time(NULL);
	strcpy(fname,name);

	fcb=init_fcb();

	struct file_info fi = {created, modified, fname, fcb};
        struct file_info* fip=&fi;
	return fip;
}

