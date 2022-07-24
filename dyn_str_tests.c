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

    printf("Value: %s\n", test_string.value);
    printf("Lenght: %d\n", test_string.len);
    printf("Size: %d\n", test_string.size);
    printf("Successfully initiated!\n");
    return EXIT_SUCCESS;
}