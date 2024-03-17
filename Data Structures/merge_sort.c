#include <stdio.h>
#include <stdlib.h>

// Hàm để trộn hai mảng con đã sắp xếp thành một mảng đã sắp xếp
void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Tạo mảng tạm thời
    int* leftArray = (int*)malloc(n1 * sizeof(int));
    int* rightArray = (int*)malloc(n2 * sizeof(int));

    // Sao chép dữ liệu vào mảng tạm thời
    for (i = 0; i < n1; i++) {
        leftArray[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        rightArray[j] = arr[middle + 1 + j];
    }

    // Trộn các mảng tạm thời lại với nhau
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Sao chép phần còn lại của leftArray, nếu có
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Sao chép phần còn lại của rightArray, nếu có
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    // Giải phóng bộ nhớ của mảng tạm thời
    free(leftArray);
    free(rightArray);
}

// Hàm thực hiện sắp xếp trộn
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Tìm phần tử giữa mảng
        int middle = left + (right - left) / 2;

        // Sắp xếp đệ quy cho nửa bên trái và nửa bên phải
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Trộn hai nửa đã sắp xếp
        merge(arr, left, middle, right);
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

    // Áp dụng sắp xếp trộn
    mergeSort(arr, 0, n - 1);

    printf("Mang sau khi sap xep tron: ");
    printArray(arr, n);

    return 0;
}
