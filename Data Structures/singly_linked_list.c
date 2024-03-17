#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc của hồ sơ sinh viên
struct Student {
    char name[50];
    char email[50];
};

// Định nghĩa cấu trúc của nút danh sách liên kết
struct Node {
    struct Student data;
    struct Node* next;
};

// Hàm để in ra hồ sơ của sinh viên
void printStudent(struct Student student) {
    printf("Name: %s\n", student.name);
    printf("Email: %s\n", student.email);
}

// Hàm để in ra danh sách hồ sơ sinh viên
void printList(struct Node* head) {
    while (head != NULL) {
        printStudent(head->data);
        printf("----------\n");
        head = head->next;
    }
}

// Hàm để thêm một hồ sơ vào cuối danh sách
struct Node* addStudent(struct Node* head, struct Student newStudent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    newNode->data = newStudent;
    newNode->next = NULL;

    if (head == NULL) {
        // Nếu danh sách rỗng, nút mới là nút đầu danh sách
        head = newNode;
    } else {
        // Nếu danh sách không rỗng, tìm nút cuối cùng và thêm nút mới vào sau
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

// Hàm để xóa hồ sơ từ danh sách
struct Node* deleteStudent(struct Node* head, char* targetEmail) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL) {
        // So sánh địa chỉ email để xác định nút cần xóa
        if (strcmp(current->data.email, targetEmail) == 0) {
            if (previous == NULL) {
                // Nếu nút cần xóa là nút đầu danh sách
                head = current->next;
            } else {
                // Nếu nút cần xóa không phải là nút đầu danh sách
                previous->next = current->next;
            }

            // Giải phóng bộ nhớ của nút bị xóa
            free(current);
            printf("Student with email %s has been deleted.\n", targetEmail);

            return head;
        }

        previous = current;
        current = current->next;
    }

    printf("Student with email %s not found.\n", targetEmail);
    return head;
}

// Hàm để tìm kiếm hồ sơ trong danh sách
void searchStudent(struct Node* head, char* targetEmail) {
    struct Node* current = head;

    while (current != NULL) {
        if (strcmp(current->data.email, targetEmail) == 0) {
            printf("Student found:\n");
            printStudent(current->data);
            return;
        }

        current = current->next;
    }

    printf("Student with email %s not found.\n", targetEmail);
}

// Hàm để giải phóng bộ nhớ của danh sách
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    struct Node* studentList = NULL;
    FILE* file = fopen("students.txt", "r");

    // Đọc dữ liệu từ file văn bản vào danh sách
    if (file != NULL) {
        struct Student tempStudent;
        while (fscanf(file, "%s %s", tempStudent.name, tempStudent.email) == 2) {
            studentList = addStudent(studentList, tempStudent);
        }
        fclose(file);
    }

    // In danh sách sinh viên
    printf("Student List:\n");
    printList(studentList);

    // Thêm một hồ sơ mới vào cuối danh sách
    struct Student newStudent = {"John Doe", "john.doe@example.com"};
    studentList = addStudent(studentList, newStudent);

    // In lại danh sách sinh viên sau khi thêm
    printf("\nStudent List after adding a new student:\n");
    printList(studentList);

    // Xóa một hồ sơ từ danh sách
    char targetEmail[] = "jane.doe@example.com";
    studentList = deleteStudent(studentList, targetEmail);

    // In lại danh sách sinh viên sau khi xóa
    printf("\nStudent List after deleting a student:\n");
    printList(studentList);

    // Tìm kiếm hồ sơ theo email
    char searchEmail[] = "john.doe@example.com";
    printf("\nSearching for student with email %s:\n", searchEmail);
    searchStudent(studentList, searchEmail);

    // Lưu danh sách sinh viên vào file văn bản
    file = fopen("students_updated.txt", "w");
    if (file != NULL) {
        struct Node* current = studentList;
        while (current != NULL) {
            fprintf(file, "%s %s\n", current->data.name, current->data.email);
            current = current->next;
        }
        fclose(file);
    }

    // Giải phóng bộ nhớ của danh sách
    freeList(studentList);

    return 0;
}
