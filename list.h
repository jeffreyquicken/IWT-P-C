// ==================== Enkelvoudige Gelinkte Lijst ====================

struct ListNode {
	int value;
	struct ListNode *next;
};

struct List {
	struct ListNode *first;
};

struct List * list_create();
void list_print(struct List *list);
int list_length(struct List *list);
void list_append(struct List *list, int value);
int list_get(struct List *list, int index, int *error);
void list_delete(struct List *list);

int list_remove(struct List *list, int index);
int list_pop(struct List *list, int *error);

void list_prepend(struct List *list, int value);
void list_insert(struct List *list, int index, int value);



// ==================== Dubbel Gelinkte Lijst ====================

struct DListNode {
	int value;
	struct DListNode *prev;
	struct DListNode *next;
};

struct DList {
	struct DListNode *first;
	struct DListNode *last;
	int length;
};

struct DList * dlist_create();
void dlist_print(struct DList *dlist);
void dlist_delete(struct DList *dlist);

void dlist_print_reverse(struct DList *dlist);
int dlist_length(struct DList *dlist);
int dlist_get(struct DList *list, int index, int *error);
void dlist_append(struct DList *dlist, int value);
int dlist_remove(struct DList *dlist, int index);



// ==================== Stacks ====================

struct StackNode {
	char *string;
	struct StackNode *next;
};

struct Stack {
	struct StackNode *top;
};

struct Stack * stack_create();
void stack_push(struct Stack *stack, const char *string);
char * stack_pop(struct Stack *stack);
int stack_isempty(struct Stack *stack);
void stack_delete(struct Stack *stack);
void stack_print(struct Stack *stack);

void stack_reverse(struct Stack* stack);
char * stack_join(struct Stack* stack, const char *delimiter);


//char * realpath(const char *path);


