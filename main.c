#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

int test_list()
{
	printf("Testing list:\n");
	int error = 0;
	struct List *list = list_create();

	if (list_length(list) != 0) {
		printf("list_length of empty list should be zero\n");
		return 0;
	}


	// Insert value 101 and test functions
	list_insert(list, 0, 101);
	printf("List length: %i\n", list_length(list));
	if (list_length(list) != 1) {
		printf("list_length should be 1\n");
		return 0;
	}

	printf("Value is: %i\n", list_get(list, 0, &error));
	if (list_get(list, 0, &error) != 101) {
		printf("list_get should return value 101E\n");
		return 0;
	}
	if (error != 0) {
		printf("rror in list_get (1)\n");
		return 0;
	}


	// Insert value 202 and test functions
	list_insert(list, 0, 202);
	printf("List length: %i\n", list_length(list));
	if (list_length(list) != 2) {
		printf("list_length should return 2\n");
		return 0;
	}

	printf("Value is: %i\n", list_get(list, 0, &error));
	if (list_get(list, 0, &error) != 202) {
		printf("list_get should return 202\n");
		return 0;
	}
	if (error != 0) {
		printf("Error in list_length (2)\n");
		return 0;
	}


	// Test remove function
	if (list_remove(list, 1) == 0) {
		printf("Error in list_remove\n");
		return 0;
	}
	if (list_length(list) != 1) {
		printf("list_length should return 1 (after remove)\n");
		return 0;
	}


	// Test pop function
	list_insert(list, 0, 123);
	if (list_pop(list, &error) != 123) {
		printf("list_pop should return 123\n");
		return 0;
	}
	if (error != 0) {
		printf("Error in list_pop\n");
		return 0;
	}

	if (list_pop(list, &error) != 202) {
		printf("list_pop should return 202\n");
		return 0;
	}
	if (error != 0) {
		printf("Error in list_pop\n");
		return 0;
	}

	if (list_length(list) != 0) {
		printf("list_length should return 0 (after pop)\n");
		return 0;
	}


	// TODO: Add our own test functions (!!)

	return 1;
}


int test_dlist()
{
	// TODO: Add your own test functions (!!)
	int error = 0;
	printf("Testing Dlist:\n");
	struct DList *dlist = dlist_create();

	if (dlist_length(dlist) != 0) {
		printf("list_length of empty list should be zero\n");
		return 0;
	}

	//append value 123
	dlist_append(dlist,123);
	printf("Value is: %i\n", dlist_get(dlist, 0, &error));
	if (dlist_get(dlist, 0, &error) != 123) {
		printf("list_get should return value 123\n");
		return 0;
	}

	//append value 456
	dlist_append(dlist,456);
	printf("Value is: %i\n", dlist_get(dlist, 1, &error));
	if (dlist_get(dlist, 1, &error) != 456) {
		printf("list_get should return value 456\n");
		return 0;
	}
	printf("Length is: %i\n", dlist_length(dlist));
	dlist_print_reverse(dlist);
	dlist_remove(dlist,0);
	dlist_print(dlist);
	printf("Length is: %i\n", dlist_length(dlist));
	return 1;
}


int test_stack()
{
	// TODO: Add your own test functions (!!)
	printf("Testing stack:\n");

	struct Stack *stack = stack_create();

	//Testing push
	stack_push(stack, "test");
	stack_push(stack, "stack");
	stack_push(stack, "push");
	stack_print(stack);
	printf("-----Pop-----\n");
	printf("%s\n",stack_pop(stack) );
	printf("%s\n",stack_pop(stack) );
	printf("%s\n",stack_pop(stack) );
	stack_push(stack, "last");
	stack_push(stack, "second");
	stack_push(stack, "first");
	stack_join(stack,"-");
	printf("-----Reversing-----\n");
	stack_print(stack);
	stack_reverse(stack);
	printf("In test: ");
	stack_print(stack);


	return 1;
}


//int test_realpath()
//{
//	// Test 1
//	char *path = realpath("/simple/test");
//	if (path == NULL || strcmp(path, "/simple/test") != 0)
//		printf("Realpath failed on /simple/test/: %s\n", path);
//	free(path);
//
//	// Test 2
//	path = realpath("/simple/test/../two");
//	if (path == NULL || strcmp(path, "/simple/two") != 0)
//		printf("Realpath failed on /simple/test/../two: %s\n", path);
//	free(path);
//
//	// Test 3
//	path = realpath("/simple/../../two");
//	if (path != NULL)
//		printf("Realpath failed on /simple/../../test: %s\n", path);
//	free(path);
//
//	// TODO: Add more tests yourself!
//
//	return 1;
//}


int main(int argc, char *argv[])
{
//	test_list();
//	test_dlist();
	test_stack();
//	test_realpath();

	return 0;
}

