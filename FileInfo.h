#include "FSCommon.h"
#include <time.h>

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

/*  API for modify_file_info_time()
        purpose: Updates a file_info last modified time to the current time
        parameters: [struct file_info*]
        input preconditions: file_info has been initialized. 
        output/postconditions: NONE. The last modified time of file_info is equal to the current time.
        usage: void modify_file_info_time(struct file_info* fi)
        Principal designer: mvigil
        Status: Designed, documented, implemented
*/
void  modify_file_info_time();

/* API for file_info_append_byte()
        purpose: Appends a byte to the end of a file
        parameters: [struct file_info* fi] [char* byte]
        input preconditions: The file must not already be filled to max capacity.The file must be initialized.
        output/postconditions: [int] Return number of bytes appended (1 or 0).
        usage: int file_info_append_byte(struct file_info* fi, char* byte)
        Principal designer: mvigil
        Status: Designed, documented
*/
int file_info_append_byte(struct file_info* fi, char* byte);

