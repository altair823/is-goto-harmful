#include <map.h>
#include <map_goto.h>

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

    map_t *map_goto = create_map_goto();
    int key_goto = 1;
    int value_goto = 2;
    insert_goto(map_goto, &key_goto, sizeof(int), &value_goto, sizeof(int));
    int result_goto;
    size_t value_size_goto = get_goto(map_goto, &key_goto, sizeof(int), &result_goto);
    assert(value_size_goto == sizeof(int));
    assert(result_goto == value_goto);

    char key2_goto[] = "hello";
    char value2_goto[] = "world";
    insert_goto(map_goto, key2_goto, sizeof(key2_goto), value2_goto, sizeof(value2_goto));
    char result2_goto[6];
    size_t value_size2_goto = get_goto(map_goto, key2_goto, sizeof(key2_goto), result2_goto);
    assert(value_size2_goto == sizeof(value2_goto));
    assert(memcmp(result2_goto, value2_goto, sizeof(value2_goto)) == 0);

    char key3_goto = 'a';
    int value3_goto = 3231;
    insert_goto(map_goto, &key3_goto, sizeof(char), &value3_goto, sizeof(int));
    int result3_goto;
    size_t value_size3_goto = get_goto(map_goto, &key3_goto, sizeof(char), &result3_goto);
    assert(value_size3_goto == sizeof(int));
    assert(result3_goto == value3_goto);

    return 0;
}