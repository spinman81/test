#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdbool.h>
#include "node.h"

#define Node LinkedListNode

typedef struct _LinkedList {
    Node* head;
    Node* tail;
    NodeFactory* node_factory;

    void (*release)(struct _LinkedList*);
    void (*from_array)(struct _LinkedList*, int*, int);
    void (*from_string)(struct _LinkedList*, const char*);
    void (*push_back)(struct _LinkedList*, int);
    void (*push_front)(struct _LinkedList*, int);
    int (*pop_front)(struct _LinkedList*);
    int (*front)(struct _LinkedList*);
    int (*back)(struct _LinkedList*);
    bool (*empty)(struct _LinkedList*);
    void (*print)(struct _LinkedList*);
} LinkedList;

LinkedList* linked_list();

#endif // _LINKED_LIST_H_
