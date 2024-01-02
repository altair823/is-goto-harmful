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

void insert(map_t *map, void *key, size_t key_size, void *value, size_t value_size) {
    unsigned long digit = hash(key, key_size);
    int index = digit % MAP_SIZE;
    if (map->buckets[index] == NULL) {
        map->buckets[index] = (bucket_t *) malloc(sizeof(bucket_t) * INIT_BUCKET_LIST_SIZE);
        map->buckets[index][0].key = (void *) malloc(key_size);
        map->buckets[index][0].key_size = key_size;
        map->buckets[index][0].value = (void *) malloc(value_size);
        map->buckets[index][0].value_size = value_size;
        memcpy(map->buckets[index][0].key, key, key_size);
        memcpy(map->buckets[index][0].value, value, value_size);
        map->sizes[index] = 1;
        map->tops[index] = 1;
    } else if (map->tops[index] == map->sizes[index]) {
        map->buckets[index] = (bucket_t *) realloc(map->buckets[index], sizeof(bucket_t) * map->sizes[index] * 2);
        map->buckets[index][map->tops[index]].key = (void *) malloc(key_size);
        map->buckets[index][map->tops[index]].key_size = key_size;
        map->buckets[index][map->tops[index]].value = (void *) malloc(value_size);
        map->buckets[index][map->tops[index]].value_size = value_size;
        memcpy(map->buckets[index][map->tops[index]].key, key, key_size);
        memcpy(map->buckets[index][map->tops[index]].value, value, value_size);
        map->sizes[index] *= 2;
        map->tops[index]++;
    } else {
        map->buckets[index][map->tops[index]].key = (void *) malloc(key_size);
        map->buckets[index][map->tops[index]].key_size = key_size;
        map->buckets[index][map->tops[index]].value = (void *) malloc(value_size);
        map->buckets[index][map->tops[index]].value_size = value_size;
        memcpy(map->buckets[index][map->tops[index]].key, key, key_size);
        memcpy(map->buckets[index][map->tops[index]].value, value, value_size);
        map->tops[index]++;
    }
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