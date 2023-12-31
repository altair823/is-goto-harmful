#pragma once

#include <stddef.h>

typedef struct {
    void *key;
    size_t key_size;
    void *value;
    size_t value_size;
} bucket_t;

#define MAP_SIZE 8
#define INIT_BUCKET_LIST_SIZE 1

typedef struct {
    size_t sizes[MAP_SIZE];
    size_t tops[MAP_SIZE];
    bucket_t *buckets[MAP_SIZE];
} map_t;