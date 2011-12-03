#define MAX_BYTES 128

struct data_block* init_data_block();

int data_block_append_byte(struct data_block* db, char* byte);
