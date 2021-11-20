#include "files.h"

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct files_t* files_open(char* path) {
    // TODO: Malloc and open
    if(open(path, O_RDONLY) == -1){
        return NULL;
    }
    struct files_t *file = malloc (sizeof (struct files_t));
    file->fd = (int)open(path, O_RDONLY);

    return file;
}

enum files_status files_read(struct files_t* file, char* buffer, int bufflen) {
    // TODO
    int bytes = read(file->fd, buffer, bufflen);

    if (bytes < 0){
        return FILES_ERR_OTHER;
    }
    else if (file == NULL || buffer == NULL | bufflen == 0){
        return FILES_ERR_ARGS;
    }

    if (bytes >= 0){
        if (bytes == 0){
            return FILES_EOF;
        }
        buffer = read(file->fd, buffer, bufflen);
        
    }
    return FILES_OK;
}


void files_close(struct files_t* file) {
   // TODO: Close and free
    if(file == NULL){
        return NULL;
    }
    free(file);
    close(file);
    
    
}
