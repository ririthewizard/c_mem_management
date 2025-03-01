#include "stack.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

void stack_free(stack_t *stack) {
    if (stack == NULL) {
	return;
    }
    
    if (stack->data != NULL) {
	free(stack->data);
    }
    free(stack);
}

void *stack_pop(stack_t *stack) {
    if (stack->count == 0) {
	return NULL;
    }
    void *tmp = stack->data[stack->count - 1];
    stack->count--;
    return tmp;
}

void stack_push(stack_t *stack, void *obj) {
    if (stack->count == stack->capacity) {
	stack->capacity *= 2;
	void *tmp_mem = realloc(stack->data, stack->capacity * sizeof(void *));
	if (tmp_mem == NULL) {
	    stack->capacity /= 2;
	    return;
	}
	stack->data = tmp_mem;
    }
    stack->data[stack->count] = obj;
    stack->count++;
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

