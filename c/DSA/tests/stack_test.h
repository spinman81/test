#ifndef _STACK_TEST_H_
#define _STACK_TEST_H_
#include <stdio.h>
#include "stack.h"

void stack_test() {
    Stack* filo = stack();
    filo->push(filo, 1);
    filo->push(filo, 2);
    printf("stack top: %d\n", filo->top(filo));
    filo->pop(filo);
    printf("stack top: %d\n", filo->top(filo));
    filo->pop(filo);
    printf("stack top: %d\n", filo->top(filo));
    filo->release(filo);
}

#endif // _STACK_TEST_H_