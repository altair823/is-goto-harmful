#include <stddef.h>

#define INIT_MAP_SIZE 8

typedef struct {
    size_t size;
    void **buckets;
} map_t;

map_t *create_map();
