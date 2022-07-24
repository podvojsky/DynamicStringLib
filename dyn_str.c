#include "dyn_str.h"

extern int errno;

/**
 * @brief Initialize dynamic string.
 * 
 * @param s String for initialization.
 */
void DynStrInit(DynamicString *s) {
    int init_size = ALLOC_BLOCK_SIZE * sizeof(char);    // Initial size (in bytes) of string to allocate.

    s->value = (char*) malloc(init_size);
    if (s->value == NULL) {
        perror("Inside DynStrInit()");
    }
    s->size = init_size;
    s->len = 0;
    strcpy(s->value, "\0");
}
