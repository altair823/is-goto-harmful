#pragma once

#include <stddef.h>

/**
 * @brief hash function
 * 
 * @param key key to hash
 * @param size size of key in bytes
 * @return unsigned int hash value
 */
unsigned long hash(void *key, size_t size);

