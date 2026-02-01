// THIS IS CURRENTLY A FAKE SIMULATION, NEEDS TO BE CHANGED LATER

#include "dfs.h"
#include <stdint.h>
#include <stdio.h>

int32_t store_chunk(int32_t chunk_id, const uint8_t *data, size_t size) {
    char filename[64];
    snprintf(filename, sizeof(filename), "chunk_%d.dat", chunk_id);

    FILE *fp = fopen(filename, "wb");
    if (!fp)
        return -1;

    fwrite(data, 1, size, fp);
    fclose(fp);

    return 0;
}

int32_t load_chunk(int32_t chunk_id, uint8_t *buffer, size_t buffer_size,
                   size_t *bytes_read) {
    char filename[64];
    snprintf(filename, sizeof(filename), "chunk_%d.dat", chunk_id);

    FILE *fp = fopen(filename, "rb");
    if (!fp)
        return -1;

    *bytes_read = fread(buffer, 1, buffer_size, fp);
    fclose(fp);

    return 0;
}
