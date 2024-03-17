#include <stdio.h>

// Hàm để hoán đổi giá trị của hai phần tử
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm thực hiện sắp xếp nổi bọt
void bubbleSort(int arr[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        // Duyệt qua danh sách, đưa phần tử lớn nhất về cuối
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Đổi chỗ phần tử nếu chúng không theo thứ tự
                swap(&arr[j], &arr[j + 1]);
            }
        }
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

    // Áp dụng sắp xếp nổi bọt
    bubbleSort(arr, n);

    printf("Mang sau khi sap xep nổi bọt: ");
    printArray(arr, n);

    return 0;
}
