#include <limits.h>
#include <stdlib.h>
#include "linked_list.h"

static void _release(LinkedList* self) {
    Node* curr = self->head;
    Node* temp = NULL;
    while (curr) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    self->head = NULL;
    self->tail = NULL;
}

static void _from_array(LinkedList* self, int* arr, int size) {
    Node* prev = NULL;
    Node* root = self->head;
    for (int i = 0; i < size; i++) {
        Node* node = self->node_factory->linked_list_node(arr[i]);
        if (prev) {
            prev->next = node;
        }
        else {
            root = node;
        }
        prev = node;
    }
}

static void _from_string(LinkedList* self, const char* str) {
    char s[strlen(str) + 1];
    strcpy(s, str);
    char* p = strtok(s, ",");

    Node* root = self->head;
    Node* prev = NULL;
    while (p) {
        Node* node = self->node_factory->linked_list_node(atoi(p));
        if (prev) {
            prev->next = node;
        }
        else {
            root = node;
        }
        prev = node;
        p = strtok(NULL, ",");
    }
}

static void _push_back(LinkedList* self, int data) {
    Node* node = self->node_factory->linked_list_node(data);
    if (self->tail) {
        self->tail->next = node;
        self->tail = node;
    }
    else {
        self->head = node;
    }
    self->tail = node;
}

static void _push_front(LinkedList* self, int data) {
    Node* node = self->node_factory->linked_list_node(data);
    node->next = self->head;
    self->head = node;
    if (!self->tail) {
        self->tail = node;
    }
}

static int _pop_front(LinkedList* self) {
    int data = INT_MAX;
    if (self->head) {
        Node* node = self->head;
        self->head = node->next;
        if (self->tail == node) {
            self->tail = NULL;
        }
        data = node->data;
        free(node);
    }
    return data;
}

static int _front(LinkedList* self) {
    return self->head ? self->head->data : INT_MAX;
}

static int _back(LinkedList* self) {
    return self->tail ? self->tail->data : INT_MAX;
}

static bool _empty(LinkedList* self) {
    return self->head == NULL;
}

static void _print(LinkedList* self) {
    Node* curr = self->head;
    while (curr->next) {
        printf("%.3d->", curr->data);
        curr = curr->next;
    }
    printf("%.3d\n", curr->data);
}

LinkedList* linked_list() {
    LinkedList* list = (LinkedList*)calloc(1, sizeof(LinkedList));
    list->node_factory = node_factory();
    list->release = _release;
    list->from_array = _from_array;
    list->from_string = _from_string;
    list->push_back = _push_back;
    list->push_front = _push_front;
    list->pop_front = _pop_front;
    list->empty = _empty;
    list->front = _front;
    list->back = _back;
    list->print = _print;
    return list;
}