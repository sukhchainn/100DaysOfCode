#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

union Element
{
    int i;
    float f;
    char c;
    long l;
    double d;
};

typedef struct
{
    Element *element;
    int top;
    int size;
    // 0 means Ok, 1 means overflow, -1 means underflow
    int flag;
} Stack;

Stack stack(int num) {
    Stack stack;
    stack.size = num;
    stack.element = (Element*) calloc(num, sizeof(Element));
    stack.top = -1;
    return stack;
}

void push(Stack* stack, Element e) {
    if (stack->top > stack->size) {
        stack->flag = 1;
    }
    else if (stack->flag == -1)
        stack->flag = 0;
    stack->top++;
    stack->element[stack->top] = e;
}

Element pop(Stack* stack) {
    if (stack->top == -1) {
        stack->flag = -1;
    }
    else if (stack->flag == 1)
        stack->flag = 0;
    return stack->element[stack->top--];
}

Element top(Stack* stack) {
    return stack->element[stack->top];
}

// 1 means true, 0 menas false
int empty(Stack* stack) {
    return stack->top == -1 ? 1 : 0;
}

int size(Stack* stack) {
    return stack->size;
}

int main()
{
    printf("Stack Implementation: \nEnter the size of the stack!");
    int n;
    scanf("%d", &n);

    Stack s = stack(n);
    Element e;
    e.i = 10;

    push(&s, e);
    e.i = 20;
    push(&s, e);
    e.i = 30;
    push(&s, e);

    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
    printf("%d ", pop(&s));
    printf("\n%d ", empty(&s));
    printf("\n%d ", size(&s));
    printf("\n%d ", top(&s));

    free(s.element);
    return 0;
}
