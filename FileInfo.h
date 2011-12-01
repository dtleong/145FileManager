#include "FSCommon.h"
#include <time.h>
#include <stdio.h>

/*  API for init_file_info()
        purpose: Create a new file_info
        parameters: [char* filename]
        input preconditions: NONE
        output/postconditions: [struct file_info* fi] A pointer to the new file_info struct is returned.
        usage: struct file_info* init_file_info(char* filename)
        Principal designer: mvigil
        Status: Designed, documented, implemented
*/
struct file_info* init_file_info(char* filename); 
