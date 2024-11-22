#include <limits.h>
#include <stdlib.h>
#include "queue.h"

static void _release(Queue* self) {
    self->list->release(self->list);
    free(self);
}

static void _push(Queue* self, int data) {
    self->list->push_back(self->list, data);
}

static int _pop(Queue* self) {
    return self->list->pop_front(self->list);
}

static int _top(Queue* self) {
    return self->list->front(self->list);
}

Queue* queue() {
    Queue* q = (Queue*)calloc(1, sizeof(Queue));
    q->list = linked_list();
    return q;
}