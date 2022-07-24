/**
 * @file dyn_str.c
 * @author Lukáš Podvojský (xpodvo00)
 * @brief Dynamic string library
 * @date 2022-07-24
 */

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

void DynStrFree(DynamicString *s) {
    free(s->value);
    s->size = 0;
    s->len = 0;
}

void DynStrDebug(DynamicString *s) {
    if (s->size != 0) {
        printf("Value: %s\n", s->value);
    }
    printf("Lenght: %d\n", s->len);
    printf("Size: %d\n", s->size);
}
