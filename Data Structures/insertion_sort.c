#include <stdio.h>

// Hàm thực hiện sắp xếp chèn
void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Di chuyển các phần tử lớn hơn key về phía sau
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Chèn key vào đúng vị trí trong dãy đã sắp xếp
        arr[j + 1] = key;
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

    // Áp dụng sắp xếp chèn
    insertionSort(arr, n);

    printf("Mang sau khi sap xep chèn: ");
    printArray(arr, n);

    return 0;
}
