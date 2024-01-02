#include <map.h>

#include <assert.h>

int main() {
    map_t *map = create_map();
    int key = 1;
    int value = 2;
    insert(map, &key, sizeof(int), &value, sizeof(int));
    int result;
    size_t value_size = get(map, &key, sizeof(int), &result);
    assert(value_size == sizeof(int));
    assert(result == value);

    char key2[] = "hello";
    char value2[] = "world";
    insert(map, key2, sizeof(key2), value2, sizeof(value2));
    char result2[6];
    size_t value_size2 = get(map, key2, sizeof(key2), result2);
    assert(value_size2 == sizeof(value2));
    assert(memcmp(result2, value2, sizeof(value2)) == 0);

    char key3 = 'a';
    int value3 = 3231;
    insert(map, &key3, sizeof(char), &value3, sizeof(int));
    int result3;
    size_t value_size3 = get(map, &key3, sizeof(char), &result3);
    assert(value_size3 == sizeof(int));
    assert(result3 == value3);
    
    return 0;
}