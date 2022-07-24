#ifndef DYN_STR_H
#define DYN_STR_H

#define ALLOC_BLOCK_SIZE 1024

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef struct {
    char *value;    // Stored string value (with null terminator)
    int len;        // String lenght (number of characters excluding null character)
    int size;       // String size that has been alocated
} DynamicString;

void DynStrInit(DynamicString *s);

#endif
