#include <map.h>

map_t *create_map() {
    map_t *map = (map_t *) malloc(sizeof(map_t));
    for (int i = 0; i < MAP_SIZE; i++) {
        map->buckets[i] = NULL;
        map->sizes[i] = 0;
        map->tops[i] = 0;
    }
    return map;
}
void allocate_and_copy(bucket_t *bucket, void *key, size_t key_size, void *value, size_t value_size) {
    bucket->key = (void *) malloc(key_size);
    bucket->key_size = key_size;
    bucket->value = (void *) malloc(value_size);
    bucket->value_size = value_size;
    memcpy(bucket->key, key, key_size);
    memcpy(bucket->value, value, value_size);
}

void resize_if_needed(map_t *map, int index) {
    if (map->tops[index] == map->sizes[index]) {
        map->buckets[index] = (bucket_t *) realloc(map->buckets[index], sizeof(bucket_t) * map->sizes[index] * 2);
        map->sizes[index] *= 2;
    }
}

void insert(map_t *map, void *key, size_t key_size, void *value, size_t value_size) {
    unsigned long digit = hash(key, key_size);
    int index = digit % MAP_SIZE;
    if (map->buckets[index] == NULL) {
        map->buckets[index] = (bucket_t *) malloc(sizeof(bucket_t) * INIT_BUCKET_LIST_SIZE);
        allocate_and_copy(&map->buckets[index][0], key, key_size, value, value_size);
        map->sizes[index] = 1;
    } else {
        resize_if_needed(map, index);
        allocate_and_copy(&map->buckets[index][map->tops[index]], key, key_size, value, value_size);
    }
    map->tops[index]++;
}

size_t get(map_t *map, void *key, size_t key_size, void *value) {
    unsigned long digit = hash(key, key_size);
    int index = digit % MAP_SIZE;
    if (map->buckets[index] == NULL) {
        return 0;
    } else {
        for (int i = 0; i < map->tops[index]; i++) {
            if (memcmp(map->buckets[index][i].key, key, key_size) == 0) {
                memcpy(value, map->buckets[index][i].value, map->buckets[index][i].value_size);
                return map->buckets[index][i].value_size;
            }
        }
        return 0;
    }
}