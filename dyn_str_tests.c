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