#include <limits.h>
#include <stdlib.h>
#include "stack.h"

static void _release(Stack* self) {
    self->list->release(self->list);
    self->list = NULL;
    free(self);
}

static void _push(Stack* self, int data) {
    self->list->push_front(self->list, data);
}

static int _pop(Stack* self) {
    int data = self->list->pop_front(self->list);
    return data;
}

static int _top(Stack* self) {
    return self->list->front(self->list);
}

static bool _empty(Stack* self) {
    return self->list->empty(self->list);
}

Stack* stack() {
    Stack* s = (Stack*)calloc(1, sizeof(Stack));
    s->list = linked_list();
    s->release = _release;
    s->push = _push;
    s->pop = _pop;
    s->top = _top;
    s->empty = _empty;
    return s;
}