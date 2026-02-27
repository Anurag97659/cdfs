#include "dfs.h"
#include <stdint.h>
#include <string.h>

static file_metadata_t files[MAX_FILES];
static int32_t file_count = 0;

int32_t register_file(const char *filename,const chunk_info_t* chunks, int32_t chunk_count) {
    
    if(file_count >= MAX_FILES){
        return -1;
    }

    if(!filename || !chunks){
        return -1;
    }

    if(chunk_count < 0 || chunk_count > MAX_CHUNKS){
        return -1;
    }

    for(int32_t i = 0; i < file_count; i++){
        if(strcmp(files[i].filename, filename) == 0)return -1;
    }

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
    
    if(!filename || !out){
        return -1;
    }

    for(int32_t i = 0; i < file_count; i++){
        if(strcmp(files[i].filename, filename) == 0){
            
            file_metadata_t *src = &files[i];
            
            strncpy(out->filename, src->filename, MAX_FILENAME - 1);
            out->filename[MAX_FILENAME - 1] = '\0';
            out->chunk_count = src->chunk_count;
            for (int32_t j = 0; j < src->chunk_count && j < MAX_CHUNKS; j++) {
                out->chunks[j] = src->chunks[j];
            }
            return 0;
        }
    }
    return -1;
}
   
