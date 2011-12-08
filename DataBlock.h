
struct data_block* init_data_block();

int data_block_append_byte(struct data_block* db, char* byte);

/*  API for delete_data_block()
        purpose: Garbage collection for data[] to delete the data_block
        parameters: [struct data_block*]
        input preconditions: pointer existing to a data_block
        output/postconditions: [void] All fields in data[] equal NULL
        usage: void delete_data_block(struct data_block* db)
        Principal designer: mvigil
        Status: designed
*/
void delete_data_block(struct data_block* db);
