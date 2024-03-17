#include <stdio.h>

// Hàm để hoán đổi giá trị của hai phần tử
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm để sắp xếp vun đống một nút tại vị trí i trong mảng với kích thước n
void heapify(int arr[], int n, int i) {
    int largest = i;    // Khởi tạo nút lớn nhất là i
    int leftChild = 2 * i + 1;    // Vị trí của nút con trái
    int rightChild = 2 * i + 2;   // Vị trí của nút con phải

    // So sánh nút lớn nhất với nút con trái
    if (leftChild < n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    // So sánh nút lớn nhất với nút con phải
    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    // Nếu nút lớn nhất không phải là nút gốc
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Gọi đệ quy để heapify nút đã đổi chỗ
        heapify(arr, n, largest);
    }
}

// Hàm để thực hiện sắp xếp vun đống
void heapSort(int arr[], int n) {
    // Xây dựng heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Loại bỏ phần tử một cách lần lượt từ heap
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);   // Di chuyển phần tử lớn nhất đến cuối mảng
        heapify(arr, i, 0);       // Gọi heapify để tái tạo heap cho phần mảng chưa được sắp xếp
    }
}

// Hàm để in mảng
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang ban dau: ");
    printArray(arr, n);

    // Áp dụng sắp xếp vun đống
    heapSort(arr, n);

    printf("Mang sau khi sap xep vun đống: ");
    printArray(arr, n);

    return 0;
}
