#include "FSCommon.h"

/*  API for f_dir_init()
        purpose: Initialize a new directory
        parameters: [char* dir_name]
        input preconditions: NONE
        output/postconditions: [struct file_directpry* fd] A pointer to the initialized file_directory is returned.
	                       It now has a name assigned to it and has the content's of it's file_info array nullified.
        usage: struct file_directory* f_dir_init(char* dir_name
        Principal designer: mvigil
        Status: Designed, documented, implemented
*/
struct file_directory* f_dir_init(char* dir_name);

/*  API for f_open()
        purpose: Open a file in a directory
        parameters: [struct file_directory* fd] [char* filename]
        input preconditions: File has been created in the directory. Pointer to directory is null.
        output/postconditions: [int file_handle] A file handle is returned. If the file cannot be opened, return -1.
        usage: int f_open(struct file_directory* fd, char* filename)
        Principal designer: mvigil
        Status: Designed, documented
*/
int f_open(struct file_directory* fd, char* filename);

/*  API for f_close()
        purpose: Close  a file in a directory
        parameters: [struct file_directory* fd] [char* filename]
        input preconditions: File has been created in the directory. Pointer to directory is not null.
	output/postconditions: [int status] A status is returned regarding the success of closing the file. 1 is success, 0 is failure.
        usage: int f_close(struct file_directory* fd, char* filename)
        Principal designer: mvigil
        Status: Designed, documented
*/
int f_close(struct file_directory* fd, char* filename);

/*  API for f_create()
        purpose: Create a new file in a directory
        parameters: [struct file_directory* fd] [char* filename]
        input preconditions: Pointer to directory is not null.
        output/postconditions: [int status] A status is returned regarding the success of creation of the file. 1 is success, 0 is failure.
        usage: int f_create(struct file_directory* fd, char* filename)
        Principal designer: mvigil
        Status: Designed, documented
*/
int f_create(struct file_directory* fd, char* filename);

/*  API for f_delete()
        purpose: Delete a file in a directory. Nullify the data_blocks it points to.
        parameters: [struct file_directory* fd] [char* filename]
        input preconditions: File has been deleted in the directory
        output/postconditions: [int status] A status is returned regarding the success of deleting the file. 1 is success, 0 is failure.
        usage: int f_delete(struct file_directory* fd, char* filename)
        Principal designer: mvigil
        Status: Designed, documented
*/
int f_delete(struct file_directory* fd, char* filename);

/*  API for f_append_byte()
        purpose: Append a byte of data to the end of a file in a directory.
        parameters: [struct file_directory* fd] [int file_handle] [int byte]
        input preconditions: File has been created in the directory. Pointer to directory is not null.
        output/postconditions: [int status] A status is returned regarding the success of qppending to the file. 1 is success, 0 is failure.
        usage: int f_append_byte(struct file_directory* fd, int file_handle, int byte)
        Principal designer: mvigil
        Status: Designed, documented
*/
int f_append_byte(struct file_directory* fd, int file_handle, int byte);

/*  API for f_append_string()
        purpose: Append a string of data to the end of a file in a directory.
        parameters: [struct file_directory* fd] [int file_handle] [char* string]
        input preconditions: File has been created in the directory. Pointer to directory is not null. 
        output/postconditions: [int status] A status is returned regarding the success of qppending to the file. 1 is success, 0 is failure.
        usage: int f_append_string(struct file_directory* fd, int file_handle, char* string)
        Principal designer: mvigil
        Status: Designed, documented
*/
int f_append_string(struct file_directory* fd, int file_handle, char* string);
