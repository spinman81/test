#ifndef _STACK_H_
#define _STACK_H_

#include "linked_list.h"

typedef struct _Stack {
    LinkedList* list;
    
    void (*release)(struct _Stack*);
    void (*push)(struct _Stack*, int);
    int (*pop)(struct _Stack*);
    int (*top)(struct _Stack*);
    bool (*empty)(struct _Stack*);
} Stack;

Stack* stack();

#endif // _STACK_H_