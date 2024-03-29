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

  int open_file_table[MAX_FILES];
  for ( i = 0; i < MAX_FILES; i++)
	open_file_table[i] = -1; 

  struct file_directory fd = { dir_name, file_table, open_file_table };
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
	int file_handle;
	for (i = 0; i < MAX_FILES; i++) {
		// check  file_info->name against *filename
		// return index (file handle) if found
		if (strcmp (filename, fd->file_table[i]->file_name) == 0) {
			file_handle = i;
			break;
		} else if (strcmp (filename, fd->file_table[i]->file_name) == 0 && i == MAX_FILES){
			return -1;
		}
	}
	int first_available = -1;
	for (i = 0; i < MAX_FILES; i++) {
		if (fd->open_file_table[i] == -1 && first_available != -1) {
			first_available = i;
		}
	        if (fd->open_file_table[i] == file_handle) {
			return file_handle;
                } else {
                        continue;
                }
        }
	fd->open_file_table[first_available] = file_handle;
	return file_handle;
}

/* Close a file */
  int f_close (struct file_directory *fd, char *filename) {
	int i;
	int file_handle;
	for (i = 0; i < MAX_FILES; i++) {
		if (strcmp (filename, fd->file_table[i]->file_name) == 0) {
			file_handle = i;
			break;
		} else {
			return -1;
		}
	}
	for (i = 0; i < MAX_FILES; i++) {
		if (fd->open_file_table[i] == file_handle) {
			fd->open_file_table[i];
			return 1;
		} else {
			continue;
		}
	} 

  }

/* Create a new file */
  int f_create (struct file_directory *fd, char *filename)
  {
    struct file_info *fi = init_file_info (filename);

    int i;
    for (i = 0; i < MAX_FILES; i++)
      {
	if (fd->file_table[i] == NULL)
	  {
	    fd->file_table[i] = fi;
	    return i;
	  }
      }
    return -1;
  }

/* Delete a file */
  void f_delete (struct file_directory* fd, int fh)
  {
	if (fd->file_table[fh] != NULL)	{
		delete_file_info(fd->file_table[fh]);
	} else {
		return;
	}
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
    file_info_append_byte (fd->file_table, string);
  }

/* list files */
  void f_ls (struct file_directory *fd)
  {
    printf ("FILE_NAME :: CREATED :: LAST_MODIFIED\n");
    int i;
    for (i = 0; i < MAX_FILES; i++)
      {
	printf("listing file %d\n",i);
	if (fd->file_table[i] != NULL)
	  {
	    struct tm *created;
	    struct tm *modified;
            printf("i = %d\n");
	    created = localtime (fd->file_table[i]->created);
	    modified = localtime (fd->file_table[i]->last_modified);

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

		created = localtime (fd->file_table[i]->created);
		modified = localtime (fd->file_table[i]->last_modified);

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

/* list open files */
  void f_lsof (struct file_directory *fd)
  {
    printf ("FILE_NAME :: CREATED :: LAST_MODIFIED\n");
    int i;
    int file_handle;
    for (i = 0; i < MAX_FILES; i++)
      {
        printf("listing file %d\n",i);
        if (fd->open_file_table[i] != NULL)
          {
            file_handle = fd->open_file_table[i];
            struct tm *created;
            struct tm *modified;
            printf("i = %d\n");
            created = localtime (fd->file_table[file_handle]->created);
            modified = localtime (fd->file_table[file_handle]->last_modified);

            printf ("%s :: %i %i/%i/%i %i:%i:%i :: %i %i/%i/%i %i:%i:%i\n",
                    fd->file_table[file_handle]->file_name, created->tm_wday,
                    created->tm_mday, created->tm_mon, created->tm_year,
                    created->tm_hour, created->tm_min, created->tm_sec,
                    modified->tm_wday, modified->tm_mday, modified->tm_mon,
                    modified->tm_year, modified->tm_hour, modified->tm_min,
                    modified->tm_sec);
          }
      }
    return;
  }

