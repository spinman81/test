#include <stdlib.h>
#include "node.h"

static LinkedListNode* _linked_list_node(int data) {
    LinkedListNode* node = calloc(1, sizeof(LinkedListNode));
    node->data = data;
}

NodeFactory* node_factory() {
    NodeFactory* factory = (NodeFactory*)calloc(1, sizeof(NodeFactory));
    factory->linked_list_node = _linked_list_node;
    return factory;
}