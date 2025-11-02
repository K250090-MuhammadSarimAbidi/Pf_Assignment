#include <stdio.h>

#define MAX 5  

void push(int stack[], int *top) {
    int value;

    if (*top == MAX - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d", &value);

    (*top)++;
    stack[*top] = value;

    printf("%d pushed onto stack.\n", value);
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }

    printf("%d popped from stack.\n", stack[*top]);
    (*top)--;
}

void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

void display(int stack[], int top) {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Current Stack (top to bottom):\n");
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int stack[MAX];
    int top = -1;
    int choice;

    printf("===== Stack Implementation using Arrays =====\n");

    do {
        printf("\n----------- MENU -----------\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("0. EXIT\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 0:
                printf("Exiting program... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

