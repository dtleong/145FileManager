#include "FileDirectory.h"


struct file_directory* f_dir_init (char *dir_name)
{
  struct file_info *file_table[MAX_FILES];
  struct file_directory *fdp;
  int i;

  for (i = 0; i < MAX_FILES; i++)
    file_table[i] = NULL;

  struct file_directory fd = { dir_name, file_table };
  fdp = &fd;
  return fdp;
}

int f_mk_fs (struct file_directory *fd, char *filename)
{
/* This is where fcbs are initialized */
}

/* Open a file */
int f_open (struct file_directory *fd, char *filename)
{
/* Open a file named filename */
}

/* Close a file */
int f_close (struct file_directory *fd, char *filename)
{

}

/* Create a new file */
int f_create (struct file_directory *fd, char *filename)
{

}

/* Delete a file */
int f_delete (struct file_directory *fd, char *filename)
{

}

/* Append a byte to the end of a file */
int f_append_byte (struct file_directory *fd, int file_handle, int byte)
{

}

/* Append a string to the end of a file */
int f_append_string (struct file_directory *fd, int file_handle, char *string)
{

}

/* list files */
void f_ls (struct file_directory *fd)
{

}

/* list a file */
void f_ls1 (struct file_directory *fd, char *fname)
{

}
