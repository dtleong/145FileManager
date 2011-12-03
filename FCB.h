#include "FSCommon.h"
#include "DataBlock.h"

struct file_control_block* init_fcb();

int fcb_append_byte(struct file_control_block* fcbp, char* byte);
