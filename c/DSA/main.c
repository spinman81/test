#include <stdio.h>
#include <stdlib.h>
#include "linked_list_test.h"
#include "stack_test.h"

typedef void TestFunc();

int main(int argc, char** argv) {
    printf("Starting C DSA ...\n");

    TestFunc* tests[] = {linked_list_test, stack_test};
    int size = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < size; i++) {
        tests[i]();
    }
}