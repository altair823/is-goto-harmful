#include <hash_goto.h>

unsigned long hash_goto(void *key, size_t size) {
    char *str = (char *) key;
    unsigned long hash = 5381;
    int c;
    loop:
    if ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        goto loop;
    }
    return hash;
}