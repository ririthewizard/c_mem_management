#include "stack.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

void stack_push(stack_t *stack, void *obj) {

}

stack_t *stack_new(size_t capacity) {
    stack_t *new_stack = malloc(sizeof(size_t));
    if (new_stack == NULL) {
	return NULL; 
    }

    new_stack->count = 0;
    new_stack->capacity = capacity;
    new_stack->data = malloc(new_stack->capacity * sizeof(void *));
    
    if (new_stack->data == NULL) {
	free(new_stack);
	return NULL;
    }

    return new_stack;
}

