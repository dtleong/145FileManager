#include "FSCommon.h"
#include <math.h>

char* itoa (int i) {
	char*  target;
        long l= log10(i);
	target=(char *) malloc(l);
	snprintf(target,l,"%d",i);
	return target;
}

int FileManager::fMkdir(char *name) {
	int i;
	struct file_directory *fdir;
	fdir = f_dir_init(char *name);
	
	for ( i = 0; i < MAX_BLOCKS; i++) {
		if (file_directory_table[i] != NULL) {
			file_directory_table[i] = fdir;
			return 1;
		//if all directory spots are filled, return -1
		} else if (i == 4 && file_directory_table[i] != NULL) {
			return -1;
		}
	}
}

int FileManager::fCd(char *name) {
	int i;
	for ( i = 0; i < MAX_BLOCKS; i++) {
		if (file_directory_table[i]->dir_name == name) {
			return file_directory_table[i];
		else if (i == 4 && file_directory_table[i]->dir_name != name {
			return -1
		}
	}
}
