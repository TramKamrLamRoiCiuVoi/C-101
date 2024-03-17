#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Định nghĩa cấu trúc của ngăn xếp
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Hàm để kiểm tra xem ngăn xếp có rỗng hay không
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Hàm để kiểm tra xem ngăn xếp có đầy hay không
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Hàm để đẩy một phần tử vào ngăn xếp
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow, cannot push %d\n", item);
    } else {
        stack->top++;
        stack->items[stack->top] = item;
        printf("Pushed %d to the stack\n", item);
    }
}

// Hàm để rút một phần tử từ ngăn xếp
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return -1;
    } else {
        int poppedItem = stack->items[stack->top];
        stack->top--;
        printf("Popped %d from the stack\n", poppedItem);
        return poppedItem;
    }
}

// Hàm để xem phần tử đầu tiên từ đỉnh ngăn xếp mà không loại bỏ nó
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack->items[stack->top];
    }
}

// Hàm để in ra nội dung của ngăn xếp
void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack myStack;
    myStack.top = -1;  // Khởi tạo ngăn xếp

    // Thực hiện các thao tác trên ngăn xếp
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    printStack(&myStack);

    pop(&myStack);
    printStack(&myStack);

    printf("Top element: %d\n", peek(&myStack));

    push(&myStack, 40);
    push(&myStack, 50);
    push(&myStack, 60);
    printStack(&myStack);

    pop(&myStack);
    printStack(&myStack);

    return 0;
}
