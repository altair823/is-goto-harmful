#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <structs.h>
#include <hash_goto.h>

map_t *create_map_goto();

void allocate_and_copy_goto(bucket_t *bucket, void *key, size_t key_size, void *value, size_t value_size);

void resize_if_needed_goto(map_t *map, int index);

void insert_goto(map_t *map, void *key, size_t key_size, void *value, size_t value_size);

size_t get_goto(map_t *map, void *key, size_t key_size, void *value);