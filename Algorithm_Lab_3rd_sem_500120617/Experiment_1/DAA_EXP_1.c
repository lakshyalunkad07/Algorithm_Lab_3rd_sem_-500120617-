#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Iterative insert function
struct Node* insertIterative(struct Node* root, int key) {
    struct Node* newNode = createNode(key);
    if (root == NULL) {
        return newNode;
    }

    struct Node* current = root;
    struct Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

// Recursive insert function
struct Node* insertRecursive(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insertRecursive(root->left, key);
    } else {
        root->right = insertRecursive(root->right, key);
    }

    return root;
}

// Inorder traversal to print the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    int numElements = 10;
    int keys[] = {50, 30, 20, 40, 70, 60, 80, 10, 25, 55};
    struct Node* root = NULL;

    // Time iterative insertion
    clock_t start = clock();
    for (int i = 0; i < numElements; i++) {
        root = insertIterative(root, keys[i]);
    }
    clock_t end = clock();
    double timeIterative = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Iterative Insertion Time: %f seconds\n", timeIterative);

    // Reset the root for recursive insertion
    root = NULL;

    // Time recursive insertion
    start = clock();
    for (int i = 0; i < numElements; i++) {
        root = insertRecursive(root, keys[i]);
    }
    end = clock();
    double timeRecursive = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Recursive Insertion Time: %f seconds\n", timeRecursive);

    // Display the inorder traversal (for verification)
    printf("Inorder Traversal of the Recursive Tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
