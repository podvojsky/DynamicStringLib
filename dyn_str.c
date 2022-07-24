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
 * @param s Pointer to uninitialized dynamic string.
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

/**
 * @brief Free allocated memory of string.
 * 
 * @param s Pointer to allocated dynamic string.
 */
void DynStrFree(DynamicString *s) {
    free(s->value);
    s->size = 0;
    s->len = 0;
}

/**
 * @brief Free and initialize dynamic string.
 * 
 * @param s Pointer to dynamic string.
 */
void DynStrClean(DynamicString *s) {
    DynStrFree(s);
    DynStrInit(s);
}

/**
 * @brief Print debug information.
 * 
 * @param s Pointer to dynamic string.
 */
void DynStrDebug(DynamicString *s) {
    if (s->size != 0) {
        printf("Value: %s\n", s->value);
    }
    printf("Lenght: %d\n", s->len);
    printf("Size: %d\n", s->size);
}

/**
 * @brief Append character at the end of the string.
 * 
 * @param s Pointer to dynamic string.
 * @param c Character to append.
 */
void DynStrAppend(DynamicString *s, char c) {
    if (s->size == 0) {
        fprintf(stderr, "Inside DynStrAppend(): String wasn't initialized\n");
    }
    if (s->len+1 > s->size-1) {
        s->value = realloc(s->value, s->size + ALLOC_BLOCK_SIZE);
        if (s->value == NULL) {
            perror("Inside DynStrAppend()");
        }
        s->size = s->size + ALLOC_BLOCK_SIZE;
    }
    s->value[s->len] = c;
    s->value[s->len+1] = '\0';
    ++(s->len);
}

/**
 * @brief Append character to the beginning of the string.
 * 
 * @param s Pointer to dynamic string.
 * @param c Character to append.
 */
void DynStrAppendBeg(DynamicString *s, char c) {
    if (s->size == 0) {
        fprintf(stderr, "Inside DynStrAppendBeg(): String wasn't initialized\n");
    }
    if (s->len+1 > s->size-1) {
        s->value = realloc(s->value, s->size + ALLOC_BLOCK_SIZE);
        if (s->value == NULL) {
            perror("Inside DynStrAppendBeg()");
        }
        s->size = s->size + ALLOC_BLOCK_SIZE;
    }

    for (int i = s->len; i >= 0; --i) {
        s->value[i+1] = s->value[i];
    }
    s->value[0] = c;
    ++(s->len);
}
