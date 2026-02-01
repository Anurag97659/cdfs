#ifndef DFS_H
#define DFS_H

#include <stddef.h>
#include <stdint.h>

#define CHUNK_SIZE (64 * 1024)
#define MAX_CHUNKS 1024
#define MAX_FILES 128

// Storage layer
int32_t store_chunk(int32_t chunk_id, const uint8_t *data, size_t size);
int32_t load_chunk(int32_t chunk_id, uint8_t *buffer, size_t buffer_size,
                   size_t *bytes_read);

// Metadata layer
int32_t register_file(const char *filename, int32_t chunk_count);
int32_t get_chunk_count(const char *filename, int32_t *chunk_count);

// Client API
int32_t cdfs_put(const char *local_path, const char *cdfs_path);
int32_t cdfs_get(const char *cdfs_path, const char *local_path);

#endif
