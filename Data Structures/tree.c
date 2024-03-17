#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    char name[256];
    struct Node* leftMostChild;
    struct Node* rightSibling;
} Node;

// Hàm để tạo một Node mới
Node* makeNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->leftMostChild = NULL;
    newNode->rightSibling = NULL;
    return newNode;
}

// Hàm để thêm một con vào cuối danh sách con của một Node
void addChild(Node* parent, const char* childName) {
    Node* newChild = makeNode(childName);
    if (parent->leftMostChild == NULL) {
        parent->leftMostChild = newChild;
    } else {
        Node* temp = parent->leftMostChild;
        while (temp->rightSibling != NULL) {
            temp = temp->rightSibling;
        }
        temp->rightSibling = newChild;
    }
}

// Hàm để in danh sách con của một Node
void findChildren(Node* parent) {
    Node* current = parent->leftMostChild;
    while (current != NULL) {
        printf("%s ", current->name);
        current = current->rightSibling;
    }
    printf("\n");
}

// Hàm để in danh sách tất cả thành viên trong gia đình (in-order traversal)
void printFamily(Node* root) {
    if (root != NULL) {
        printFamily(root->leftMostChild);
        printf("%s ", root->name);
        printFamily(root->rightSibling);
    }
}

// Hàm để tính chiều cao của một Node trên cây
int height(Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = height(node->leftMostChild);
        int rightHeight = height(node->rightSibling);
        return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
    }
}

// Hàm để đếm số thành viên trong gia đình (số nút của cây)
int countMembers(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftCount = countMembers(root->leftMostChild);
        int rightCount = countMembers(root->rightSibling);
        return 1 + leftCount + rightCount;
    }
}

// Hàm để lưu cây ra file
void storeToFile(Node* root, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file for writing\n");
        exit(EXIT_FAILURE);
    }

    // Sử dụng in-order traversal để lưu cây ra file
    if (root != NULL) {
        fprintf(file, "%s\n", root->name);
        storeToFile(root->leftMostChild, filename);
        storeToFile(root->rightSibling, filename);
    }

    fclose(file);
}

// Hàm để giải phóng bộ nhớ của cây
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->leftMostChild);
        freeTree(root->rightSibling);
        free(root);
    }
}

int main() {
    Node* familyTree = NULL;

    while (1) {
        char command[20];
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "Load") == 0) {
            char filename[256];
            scanf("%s", filename);
            // Gọi hàm để nạp dữ liệu từ file và xây dựng cây
            // (Chưa được triển khai ở đây)
        } else if (strcmp(command, "FindChildren") == 0) {
            char name[256];
            scanf("%s", name);
            Node* parentNode = /* Tìm Node có tên là name trong cây */;
            if (parentNode != NULL) {
                findChildren(parentNode);
            } else {
                printf("Person not found\n");
            }
        } else if (strcmp(command, "AddChild") == 0) {
            char parentName[256];
            char childName[256];
            scanf("%s %s", parentName, childName);
            Node* parentNode = /* Tìm Node có tên là parentName trong cây */;
            if (parentNode != NULL) {
                addChild(parentNode, childName);
            } else {
                printf("Parent not found\n");
            }
        } else if (strcmp(command, "Print") == 0) {
            // In ra danh sách tất cả thành viên trong gia đình
            printFamily(familyTree);
            printf("\n");
        } else if (strcmp(command, "Height") == 0) {
            char name[256];
            scanf("%s", name);
            Node* targetNode = /* Tìm Node có tên là name trong cây */;
            if (targetNode != NULL) {
                int h = height(targetNode);
                printf("Height of %s: %d\n", name, h);
            } else {
                printf("Person not found\n");
            }
        } else if (strcmp(command, "Count") == 0) {
            int numMembers = countMembers(familyTree);
            printf("Number of family members: %d\n", numMembers);
        } else if (strcmp(command, "Store") == 0) {
            char filename[256];
            scanf("%s", filename);
            // Gọi hàm để lưu cây ra file
            // (Chưa được triển khai ở đây)
        } else {
            printf("Invalid command\n");
        }
    }

    // Giải phóng bộ nhớ của cây trước khi kết thúc chương trình
    freeTree(familyTree);

    return 0;
}
