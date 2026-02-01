#include "dfs.h"
#include <stdint.h>
#include <string.h>

typedef struct {
    char filename[256];
    int32_t chunk_count;
} file_metadata_t;

static file_metadata_t files[MAX_FILES];
static int32_t file_count = 0;

int32_t register_file(const char *filename, int32_t chunk_count) {
    if (file_count >= MAX_FILES)
        return -1;
    strncpy(files[file_count].filename, filename,
            sizeof(files[file_count].filename));

    files[file_count].chunk_count = chunk_count;
    file_count++;

    return 0;
}

int32_t get_chunk_count(const char *filename, int32_t *chunk_count) {
    for (int32_t i = 0; i < file_count; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            *chunk_count = files[i].chunk_count;
            return 0;
        }
    }
    return -1;
}
