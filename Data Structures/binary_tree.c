#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node cho cây nhị phân
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm để tạo một Node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Hàm để thêm một giá trị vào cây nhị phân
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Hàm để duyệt cây theo thứ tự trung tâm (in-order traversal)
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Hàm để tìm giá trị nhỏ nhất trong cây nhị phân
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Hàm để xóa một giá trị khỏi cây nhị phân
Node* deleteNode(Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node có một hoặc không có con
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node có hai con: lấy giá trị nhỏ nhất từ cây con phải (cây con lớn hơn)
        Node* temp = findMin(root->right);

        // Gán giá trị nhỏ nhất vào Node cần xóa
        root->data = temp->data;

        // Xóa giá trị nhỏ nhất từ cây con phải
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {
    Node* root = NULL;

    // Thêm giá trị vào cây nhị phân
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Duyệt cây theo thứ tự trung tâm và in ra
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Xóa giá trị khỏi cây và duyệt lại
    root = deleteNode(root, 20);
    printf("In-order traversal after deleting 20: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
