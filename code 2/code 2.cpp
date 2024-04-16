#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INITIAL_SIZE 5

struct Stack {
    int* items;
    int top;
    int size;
};

typedef struct Stack Stack;

void initialize(Stack* s) {
    s->items = (int*)malloc(INITIAL_SIZE * sizeof(int));
    s->top = -1;
    s->size = INITIAL_SIZE;
}

int isFull(Stack* s) {
    return s->top == s->size - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        s->size *= 2;
        s->items = (int*)realloc(s->items, s->size * sizeof(int));
    }
    s->items[++s->top] = value;
    printf("Pushed %d\n", value);
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop\n");
        return -1;
    }
    printf("Popped %d\n", s->items[s->top]);
    return s->items[s->top--];
}

int main() {
    srand(time(NULL));
    Stack s;
    initialize(&s);
    int i;
    for (i = 0; i < 30; i++) {
        int random_num = rand() % 100 + 1;
        if (random_num % 2 == 0) {
            push(&s, random_num);
        }
        else {
            pop(&s);
        }
    }
    free(s.items); // Remember to free allocated memory
    return 0;
}
