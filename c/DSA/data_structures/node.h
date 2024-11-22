#ifndef _NODE_H_
#define _NODE_H_

typedef struct _LinkedListNode {
    int data;
    struct _LinkedListNode* next;
} LinkedListNode;

typedef struct _NodeFactory {
    LinkedListNode* (*linked_list_node)(int);
} NodeFactory;

NodeFactory* node_factory();
#endif // _NODE_H_