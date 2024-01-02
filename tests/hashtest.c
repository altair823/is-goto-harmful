#include <hash.h>
#include <stdio.h>

int main() {
    int a = 2133135;
    void *key = (void *) &a;
    unsigned long value = hash(key, sizeof(int));
    printf("Hash value: %lu\n", value);
    return 0;
}