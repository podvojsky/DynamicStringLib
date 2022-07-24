/**
 * @file dyn_str_tests.c
 * @author Lukáš Podvojský (xpodvo00)
 * @brief Tests for dynamic string library
 * @date 2022-07-24
 */

#include "dyn_str.h"

int main() {
    DynamicString test_string;

    DynStrInit(&test_string);
    DynStrDebug(&test_string);
    printf("Successfully initiated!\n\n");

    DynStrFree(&test_string);
    DynStrDebug(&test_string);
    printf("Successfully freed!\n\n");

    return EXIT_SUCCESS;
}