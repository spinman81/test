#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "linked_list.h"

typedef struct _Queue {
    LinkedList* list;

    void (*release)(struct _Queue*);
    void (*push)(struct _Queue*, int);
    int (*pop)(struct _Queue*);
    int (*top)(struct _Queue*);
} Queue;

Queue* queue();

#endif // _QUEUE_H_