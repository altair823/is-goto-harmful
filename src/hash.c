#include <hash.h>


unsigned long hash(void *key, size_t size) {
    char *str = (char *) key;
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}