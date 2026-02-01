#include "dfs.h"
#include <stdint.h>
#include <stdio.h>

int32_t cdfs_put(const char *local_path, const char *cdfs_path) {
    FILE *fp = fopen(local_path, "rb");
    if (!fp)
        return -1;

    uint8_t buffer[CHUNK_SIZE];
    int32_t chunk_id = 0;

    while (1) {
        size_t bytes = fread(buffer, 1, CHUNK_SIZE, fp);
        if (bytes == 0)
            break;

        store_chunk(chunk_id, buffer, bytes);
        chunk_id++;
    }
    fclose(fp);

    register_file(cdfs_path, chunk_id);
    return 0;
}

int32_t cdfs_get(const char *cdfs_path, const char *local_path) {
    int32_t chunk_count;
    if (get_chunk_count(cdfs_path, &chunk_count) != 0)
        return -1;

    FILE *fp = fopen(local_path, "wb");
    if (!fp)
        return -1;

    uint8_t buffer[CHUNK_SIZE];
    size_t bytes_read;

    for (int32_t i = 0; i < chunk_count; i++) {
        load_chunk(i, buffer, CHUNK_SIZE, &bytes_read);
        fwrite(buffer, 1, bytes_read, fp);
    }
    fclose(fp);
    return 0;
}
