#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

// ==================== Enkelvoudige Gelinkte Lijst ====================

// Create an empty list
//
// Python: list = []
struct List * list_create()
{
	struct List *list = malloc(sizeof(struct List));
	list->first = NULL;
	return list;
}

// Print a human-readable representation of the given list
//
// Python: print(list)
void list_print(struct List *list)
{
	printf("[");

	struct ListNode *current = list->first;

	while (current != NULL)
	{
		printf("%d", current->value);

		// no comma after last value
		if (current->next != NULL)
			printf(", ");

		current = current->next;
	}

	printf("]\n");
}

// Return the length of the given list (i.e., the number of values in it)
//
// Python: length = len(list)
int list_length(struct List *list)
{
	int length = 0;
	struct ListNode *current = list->first;

	while (current != NULL)
	{
		length++;
		current = current->next;
	}

	return length;
}

// Append the given value to the given list
//
// Python: list.append(value)
void list_append(struct List *list, int value)
{
	// create a new ListNode to store the value in
	struct ListNode *node = malloc(sizeof(struct ListNode));
	node->value = value;
	node->next = NULL;

	// if the list is empty, make the new node the first node
	if (list->first == NULL)
		list->first = node;
	else
	{
		// find the last node and set the new node as its next node
		struct ListNode *current = list->first;

		while (current->next != NULL)
			current = current->next;

		current->next = node;
	}
}

// Return the value of the element at the given index. If the given index is out of
// range, the memory location pointed to by error is set to 1 (and the value zero
// is returned), otherwise the memory location pointed to by error is set to 0.
//
// Python: value = list[i]
// (An IndexError would correspond to a return value of 0)
int list_get(struct List *list, int index, int *error)
{
	struct ListNode *current = list->first;

	if (index < 0 || index >= list_length(list)) {
		if (error) *error = 1;
		return 0;
	}

	for (int i = 0; i < index; i++)
		current = current->next;

	if (error) *error = 0;
	return current->value;
}

// Delete the given list
//
// Python: del list
void list_delete(struct List *list)
{
	struct ListNode *current = list->first;

	while (current != NULL)
	{
		struct ListNode *previous = current;
		current = current->next;
		free(previous);
	}

	free(list);
}

// Remove the element at the given index from the given list. If the given index
// is out of range, 0 is returned, otherwise 1 is returned.
//
// Python: del list[i]
// (An IndexError would correspond to a return value of 0)
int list_remove(struct List *list, int index)
{
    struct ListNode *current = list->first;
    struct ListNode *previous = NULL;

    if (index >= list_length(list) || index < 0){
        return 0;
    }
    if(index == 0) {
        list->first = current->next;
        free(current);
        return 1;
    }

    // Go to node to be deleted and keep track of the previous node
    int i;
    for (i = 0; i < index; i++){
        previous = current;
        current = current->next;
    }
    // Unlink the node te be deleted by freeing the allocated memory and
    // setting the pointer of the previous node to the node after the one te be deleted.
    // If the last node has to be deleted we set the pointer of the previous node to NULL.

    if (index == list_length(list)-1) {
        previous->next = NULL;
        free(current);
        return 1;
    }
    else {
        previous->next = current->next;
        free(current);
        return 1;
    }


}

// Return the value of the first element. The first element is removed from the list. If the
// list is empty, the memory location pointed to by error is set to 1 (and the value zero
// is returned), otherwise the memory location pointed to by error is set to 0.
//
// Python: value = list.pop()
// (An IndexError would correspond to a return value of 0)
int list_pop(struct List *list, int *error)
{
    if (list->first == NULL){
        *error = 1;
    }
    int val = list->first->value;
    struct ListNode *current = list->first;
    list->first = current->next;
    free(current);
    *error = 0;
    return val;
}

// Prepend the value to the front of the list.
//
// Python: list.insert(0, value)
void list_prepend(struct List *list, int value)
{
    struct ListNode *new = malloc(sizeof(struct ListNode));
    struct ListNode *previous = malloc(sizeof(struct ListNode));
    new->value = value;
    previous = list->first;
    list->first = new;
    new->next = previous;
}

// Insert the element before the given index in the list. A negative index
// means the element should be added to the front (prepended). An index that
// is too high means the element should be added to the back (appended).
//
// Python: list.insert(index, value)
// (Note that the behavior for negative indices differs slightly in Python)
void list_insert(struct List *list, int index, int value)
{
    if(index <= 0){
        list_prepend(list, value);
    }
    if(index > list_length(list)){
        list_append(list, value);
    }
    else{
        struct ListNode *current = list->first;
        struct ListNode *previous =  malloc(sizeof(struct ListNode));
        struct ListNode *new = malloc(sizeof(struct ListNode));
        new->value = value;
        new->next = NULL;

        int i;
        for (i = 0; i < index; i++){
            previous = current;
            current = current->next;
        }
        previous->next = new;
        new->next = current;
    }

}


// ==================== Dubbel Gelinkte Lijst ====================

// Create an empty list
//
// Python: list = []
struct DList * dlist_create()
{
	struct DList *dlist = malloc(sizeof(struct DList));
	dlist->first = NULL;
	dlist->last = NULL;
	dlist->length = 0;
	return dlist;
}

// Print a human-readable representation of the given list
//
// Python: print(list)
void dlist_print(struct DList *dlist)
{
	printf("[");

	struct DListNode *current = dlist->first;

	while (current != NULL)
	{
		printf("%d", current->value);

		// no comma after last value
		if (current->next != NULL)
			printf(", ");

		current = current->next;
	}

	printf("]\n");
}

// Delete the given list
//
// Python: del list
void dlist_delete(struct DList *dlist)
{
	struct DListNode *curr = dlist->first;

	while (curr != NULL) {
		struct DListNode* todel = curr;
		curr = curr->next;
		free(todel);
	}
	
	free(dlist);
}

// Print the elements of the list in reverse order. For example, if the list contains
// the numbers 3, 7, and 1, it should print "[1, 7, 3]\n".
//
// Python: print(list[::-1])
void dlist_print_reverse(struct DList *dlist)
{
    printf("[");

    struct DListNode *current = dlist->last;

    while (current != NULL)
    {
        printf("%d", current->value);

        // no comma after last value
        if (current->prev != NULL)
            printf(", ");

        current = current->prev;
    }

    printf("]\n");
}

// Return the length of the given list (i.e., the number of values in it)
//
// Python: length = len(list)
int dlist_length(struct DList *dlist)
{
    int length = 0;
    struct DListNode *current = dlist->first;

    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    dlist->length = length;
    return length;
}


// Return the value of the element at the given index. If the given index is out of
// range, the memory location pointed to by error is set to 1 (and the value zero
// is returned), otherwise the memory location pointed to by error is set to 0.
//
// Python: value = list[i]
// (An IndexError would correspond to a return value of 0)
int dlist_get(struct DList *list, int index, int *error)
{
    struct DListNode *current = list->first;

    if (index < 0 || index >= dlist_length(list)) {
        *error = 1;
        return 0;
    }

    for (int i = 0; i < index; i++)
        current = current->next;

    *error = 0;
    return current->value;
}

// Append the given value to the given list
//
// Python: list.append(value)
void dlist_append(struct DList *dlist, int value)
{
    struct DListNode *new = malloc(sizeof(struct DListNode));
    new->next = NULL;
    new->prev = NULL;
    new->value = value;
    struct DListNode *previous;

    if (dlist->first == NULL) {
        dlist->first = new;
        dlist->last = new;
        dlist->length += 1;
    }
    else {
        previous = dlist->last;
        dlist->last = new;
        previous->next = new;
        new->prev = previous;
        dlist->length += 1;
    }
}


// Remove the element at the given index from the given list. If the given index
// is out of range, 0 is returned, otherwise 1 is returned.
//
// Python: del list[i]
// (An IndexError would correspond to a return value of 0)
int dlist_remove(struct DList *dlist, int index)
{
    struct DListNode *current = dlist->first;
    struct DListNode *previous = NULL;

    if (index >= dlist_length(dlist) || index < 0){
        return 0;
    }
    if(index == 0) {
        dlist->first = current->next;
        free(current);
        dlist->length -=1;
        return 1;
    }

    // Go to node to be deleted and keep track of the previous node
    int i;
    for (i = 0; i < index; i++){
        previous = current;
        current = current->next;
    }
    // Unlink the node te be deleted by freeing the allocated memory and
    // setting the pointer of the previous node to the node after the one te be deleted.
    // If the last node has to be deleted we set the pointer of the previous node to NULL.

    if (index == dlist_length(dlist)-1) {
        previous->next = NULL;
        free(current);
        dlist->length -=1;
        return 1;
    }
    else {
        previous->next = current->next;
        current->next->prev = previous;
        free(current);
        dlist->length -=1;
        return 1;
    }
}


// ==================== Stacks ====================

// Create an empty stack
struct Stack * stack_create()
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Push a new string on the stack
void stack_push(struct Stack* stack, const char *string)
{
    struct StackNode *node = malloc(sizeof(struct StackNode));
    node->string= malloc(strlen(string)+1);
    strcpy(node->string, string);
    if(stack_isempty(stack)){

        node->next = NULL;
        stack->top = node;
    }
    else{
        node->next = stack->top;
        stack->top = node;
    }
    }


// Return the first string on the stack. The caller is responsible for freeing
// the returned string. The string is removed from the stack. If the stack is
// empty, the function returns NULL.
char * stack_pop(struct Stack *stack)
{
    if (stack_isempty(stack) == 1){
        return NULL;
    }
    struct StackNode *node = stack->top;
    char *val = malloc(strlen(node->string)+1);
    strcpy(val, node->string);


    if (stack->top->next == NULL){
        stack->top = NULL;
        free(node);
        return val;
    }
    stack->top = node->next;
    free(node);

    return val;
}

// Returns 1 if the stack is empty (i.e. there are no elements to pop).
// Otherwise it returns 0.
int stack_isempty(struct Stack *stack)
{
    if(stack->top == NULL){
        return 1;
    }
    return 0;
}

// Delete the given stack
void stack_delete(struct Stack *stack)
{
    struct StackNode *current = stack->top;

    while (current != NULL) {
        struct StackNode* todel = current;
        current = current->next;
        free(todel->string);
        free(todel);
    }

    free(stack);
}

// Print a human-readable representation of the given list
void stack_print(struct Stack *stack)
{
    if(stack_isempty(stack) == 1){
        printf("Stack is empty\n");
        return;
    }
    struct StackNode *current = stack->top;
    printf("[");
    while (current != NULL) {
        printf("%s", current->string);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;

    }
    printf("]\n");
}

// Reverse the order of all elements (in this case strings) in the stack
//
// Hint: you can reverse a stack by popping elements from it, and pushing
// each element onto a new stack.
void stack_reverse(struct Stack* stack)
{
    struct Stack *reverse = stack_create();
    struct StackNode *current = stack->top;
    int length = 0;
    while (current != NULL) {
        length += 1;
        current = current->next;
    }
    for(int i = 0; i<length; i++){
        stack_push(reverse, stack_pop(stack));
    }
    stack->top = reverse->top;
}

// Return a string which is the concatenation of the strings in the stack.
// The delimiter parameter defines the separator between each string.
//
// For example, with the stack ["top", "middle", "bottom"] and delimiter "_",
// the returned string would be "top_middle_bottom".
char * stack_join(struct Stack* stack, const char *delimiter)
{
    struct StackNode *current = stack->top;
    size_t length = 0;
    while (current != NULL) {
        length += strlen(current->string)+1;
        current = current->next;
    }
    char *result = malloc(length);


    current = stack->top;
    while (current != NULL) {
        strcat(result, current->string);
        if(current->next != NULL){
            strcat(result, delimiter);
        }

        current = current->next;
    }
    return result;

}








// Return the absolute file path. The caller is responsible for freeing
// the returned string. Returns NULL if the path is not valid.
//
// For example:
// - "/home/user" returns "/home/user"
// - "/home/user/../root" returns "/home/root"
// - "/home/../../root" returns NULL
// - "/home/../home/user" returns "/home/user"
char * realpath(const char *path)
{
    struct Stack *stack = stack_create();
    char *str = malloc(strlen(path)+1);
    strcpy(str,path);
    char *token = strtok(str, "/");
    while( token != NULL ) {
        if(stack_isempty(stack) == 1 && strcmp(token, "..") != 0){
            stack_push(stack, "/");
            stack_push(stack, token);
        }
        else{
            if(strcmp(token, "..") == 0 && stack_isempty(stack) == 1){
                return NULL;

            }
            if(strcmp(token, "..") == 0){
                stack_pop(stack);
                stack_pop(stack);

            }
            else{
                stack_push(stack, "/");
                stack_push(stack,token);
            }
        }
        token = strtok(NULL, "/");
    }
    stack_reverse(stack);
    return stack_join(stack,"");
}

