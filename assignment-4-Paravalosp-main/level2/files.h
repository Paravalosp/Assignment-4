#ifndef FILES_H
#define FILES_H

/**
 * Le buffer status 
 */
enum files_status {
    FILES_EOF = 1,
    FILES_OK = 0,
    FILES_ERR_ARGS = -1,
    FILES_ERR_OTHER = -2,
};

/**
 * struct values initiated 
 */
struct files_t {
    int fd;
    int ib_size;
    int position;
    int ib_position;
    int ib_left;
    char* internal_buffer;
};

/**
 * open files given path, and buffersize
 */
struct files_t* files_open(char* path, int buffer_size);
/**
 * read file, and manipulate buffer accordingly 
 */
enum files_status files_read(struct files_t* file, char* buffer, int bufflen);
/**
 * close and free file/malloc
 */
void files_close(struct files_t* file);

#endif
