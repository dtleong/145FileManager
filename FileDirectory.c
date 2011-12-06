#include "FileDirectory.h"
#include <string.h>


struct file_directory *
f_dir_init (char *dir_name)
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

int
f_mk_fs (struct file_directory *fd, char *filename)
{
/* This is where fcbs are initialized */
}

/* Open a file */
int
f_open (struct file_directory *fd, char *filename)
{
/* Open a file named filename */
	int i;
	for (i = 0; i < MAX_FILES; i++) {
		// check  file_info->name against *filename
		// return index (file handle) if found
		if (strcmp (filename, fd->file_table[i]->file_name) == 0) {
			// here is where we would add the file number to the open file table.
			return i;
		} else {
			return -1;
		}
	}
}

/* Close a file */
  int f_close (struct file_directory *fd, char *filename)
  {

  }

/* Create a new file */
  int f_create (struct file_directory *fd, char *filename)
  {
    struct file_info *fi = file_info_init (filename);

    int i;
    for (i = 0; i < MAX_FILES; i++)
      {
	if (fd->file_table[i] == NULL)
	  {
	    fd->file_table[i] = fi;
	    return 1;
	  }
      }

    return 0;
  }

/* Delete a file */
  int f_delete (struct file_directory *fd, char *filename)
  {

  }

/* Append a byte to the end of a file */
  int f_append_byte (struct file_directory *fd, int file_handle, int byte)
  {
    char *cbyte = itoa (byte);
    file_info_append_byte (fd->file_table, cbyte);
  }

/* Append a string to the end of a file */
  int f_append_string (struct file_directory *fd, int file_handle,
		       char *string)
  {
    file_info_append (fd->file_table, string);
  }

/* list files */
  void f_ls (struct file_directory *fd)
  {
    printf ("FILE_NAME :: CREATED :: LAST_MODIFIED\n");
    int i;
    for (i = 0; i < MAX_FILES; i++)
      {
	if (fd->file_table[i] != NULL)
	  {
	    struct tm *created;
	    struct tm *modified;

	    created = localtime (&fd->file_table[i]->created);
	    modified = localtime (&fd->file_table[i]->last_modified);

	    printf ("%s :: %i %i/%i/%i %i:%i:%i :: %i %i/%i/%i %i:%i:%i\n",
		    fd->file_table[i]->file_name, created->tm_wday,
		    created->tm_mday, created->tm_mon, created->tm_year,
		    created->tm_hour, created->tm_min, created->tm_sec,
		    modified->tm_wday, modified->tm_mday, modified->tm_mon,
		    modified->tm_year, modified->tm_hour, modified->tm_min,
		    modified->tm_sec);
	  }
      }
    return;
  }

/* list a file */
  void f_ls1 (struct file_directory *fd, char *fname)
  {

    printf ("FILE_NAME :: CREATED :: LAST_MODIFIED\n");
    int i;
    for (i = 0; i < MAX_FILES; i++)
      {
	if (fd->file_table[i] != NULL)
	  {
	    if (strcmp (fname, fd->file_table[i]->file_name) == 0)
	      {
		struct tm *created;
		struct tm *modified;

		created = localtime (&fd->file_table[i]->created);
		modified = localtime (&fd->file_table[i]->last_modified);

		printf
		  ("%s :: %i %i/%i/%i %i:%i:%i :: %i %i/%i/%i %i:%i:%i\n",
		   fd->file_table[i]->file_name, created->tm_wday,
		   created->tm_mday, created->tm_mon, created->tm_year,
		   created->tm_hour, created->tm_min, created->tm_sec,
		   modified->tm_wday, modified->tm_mday, modified->tm_mon,
		   modified->tm_year, modified->tm_hour, modified->tm_min,
		   modified->tm_sec);
	      }
	  }
      }
    return;
  }
