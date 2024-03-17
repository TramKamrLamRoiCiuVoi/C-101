#include <stdio.h>

// Hàm để hoán đổi giá trị của hai phần tử
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm để tìm vị trí chính xác của phần tử chốt trong mảng và phân hoạch mảng
int partition(int arr[], int low, int high) {
    // Chọn phần tử chốt (ở đây là phần tử cuối cùng)
    int pivot = arr[high];

    // Index của phần tử nhỏ hơn chốt
    int i = (low - 1);

    // Duyệt qua mảng và đặt các phần tử nhỏ hơn chốt về phía trái
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Đặt phần tử chốt vào đúng vị trí
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Hàm để thực hiện sắp xếp nhanh
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Tìm vị trí chính xác của phần tử chốt
        int pivotIndex = partition(arr, low, high);

        // Áp dụng đệ quy cho cả hai phần của mảng
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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

    // Áp dụng sắp xếp nhanh
    quickSort(arr, 0, n - 1);

    printf("Mang sau khi sap xep nhanh: ");
    printArray(arr, n);

    return 0;
}
