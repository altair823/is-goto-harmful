#include <hash.h>
#include <hash_goto.h>
#include <stdio.h>

int main() {
    int a = 2133135;
    void *key = (void *) &a;
    unsigned long value = hash(key, sizeof(int));
    printf("Hash value: %lu\n", value);
    unsigned long value_goto = hash_goto(key, sizeof(int));
    printf("Hash value goto: %lu\n", value_goto);
    return 0;
}