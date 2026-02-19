#include "dfs.h"
#include <stdint.h>
#include <string.h>

// typedef struct {
//     char filename[256];
//     int32_t chunk_count;
// } file_metadata_t;

static file_metadata_t files[MAX_FILES];
static int32_t file_count = 0;

int32_t register_file(const char *filename,chunk_info_t* chunks, int32_t chunk_count) {
    if (file_count >= MAX_FILES)return -1;
    
    file_metadata_t *file = &files[file_count];
    strncpy(file->filename, filename, MAX_FILENAME - 1);
    file->filename[MAX_FILENAME - 1] = '\0';

    file->chunk_count = chunk_count;
    for(int32_t i = 0; i < chunk_count; i++){
        file->chunks[i] = chunks[i];
    }
    file_count++;

    return 0;
}

int32_t get_file_metadata(const char *filename, file_metadata_t *out){
    for(int32_t i = 0; i < file_count; i++){
        if(strcmp(files[i].filename, filename) == 0){
            *out = files[i];
            return 0;
        }
    }
    return -1;
}
   
