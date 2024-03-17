#include <stdio.h>

// Hàm để hoán đổi giá trị của hai phần tử
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm thực hiện sắp xếp lựa chọn
void selectionSort(int arr[], int n) {
    int i, j, min_index;

    // Duyệt qua từng phần tử của mảng
    for (i = 0; i < n - 1; i++) {
        // Tìm phần tử nhỏ nhất trong phần chưa sắp xếp
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên của phần chưa sắp xếp
        swap(&arr[min_index], &arr[i]);
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

    // Áp dụng sắp xếp lựa chọn
    selectionSort(arr, n);

    printf("Mang sau khi sap xep lựa chọn: ");
    printArray(arr, n);

    return 0;
}
