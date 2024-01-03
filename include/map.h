#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <hash.h>
#include <structs.h>


map_t *create_map();

void allocate_and_copy(bucket_t *bucket, void *key, size_t key_size, void *value, size_t value_size);

void resize_if_needed(map_t *map, int index);

void insert(map_t *map, void *key, size_t key_size, void *value, size_t value_size);

size_t get(map_t *map, void *key, size_t key_size, void *value);