/**
 * @file dyn_str.h
 * @author Lukáš Podvojský (xpodvo00)
 * @brief Dynamic string library
 * @date 2022-07-24
 */

#ifndef DYN_STR_H
#define DYN_STR_H

// Number of bytes to allocate on top of already allocated space
// when reallocation is performed.
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

void DynStrFree(DynamicString *s);

void DynStrDebug(DynamicString *s);

void DynStrClean(DynamicString *s);

void DynStrAppend(DynamicString *s, char c);

void DynStrAppendBeg(DynamicString *s, char c);

void DynStrSizeCheck(DynamicString *s, int char_size);

void DynStrSet(DynamicString *s, const char *value);

#endif
