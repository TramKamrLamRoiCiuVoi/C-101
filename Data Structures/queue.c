#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Định nghĩa cấu trúc Queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Hàm để kiểm tra xem hàng đợi có rỗng hay không
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Hàm để tạo một Node mới
Node* makeNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm để thêm một phần tử vào cuối hàng đợi
void enqueue(Queue* queue, int value) {
    Node* newNode = makeNode(value);

    if (isEmpty(queue)) {
        // Nếu hàng đợi rỗng, front và rear đều trỏ đến newNode
        queue->front = queue->rear = newNode;
    } else {
        // Ngược lại, thêm newNode vào cuối hàng đợi và cập nhật rear
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Enqueued: %d\n", value);
}

// Hàm để lấy một phần tử từ đầu hàng đợi
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue underflow\n");
        exit(1);
    }

    // Lấy giá trị từ front và di chuyển front đến phần tử tiếp theo
    int value = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    
    // Nếu hàng đợi trở thành rỗng sau khi dequeue, cập nhật rear thành NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    // Giải phóng bộ nhớ của nút đã được dequeue
    free(temp);

    printf("Dequeued: %d\n", value);
    return value;
}

// Hàm để xem giá trị ở đầu hàng đợi mà không xóa nó
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    return queue->front->data;
}

// Hàm để in nội dung của hàng đợi
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        Node* current = queue->front;
        printf("Queue contents: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    // Khởi tạo hàng đợi
    Queue myQueue;
    myQueue.front = myQueue.rear = NULL;

    // Thực hiện các thao tác trên hàng đợi
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    printQueue(&myQueue);

    dequeue(&myQueue);
    printQueue(&myQueue);

    printf("Front element: %d\n", peek(&myQueue));

    enqueue(&myQueue, 40);
    enqueue(&myQueue, 50);
    enqueue(&myQueue, 60);
    printQueue(&myQueue);

    dequeue(&myQueue);
    printQueue(&myQueue);

    return 0;
}
