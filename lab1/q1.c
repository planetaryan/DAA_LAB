#include <stdio.h>
#include <stdlib.h>

// Define a typedef for the Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST and search for the key
Node* insertAndSearch(Node* root, int key) {
    if (root == NULL) {
        printf("Key inserted.\n");
        return createNode(key);
    }

    if (key == root->data) {
        printf("Key found.\n");
    } else if (key < root->data) {
        root->left = insertAndSearch(root->left, key);
    } else {
        root->right = insertAndSearch(root->right, key);
    }

    return root;
}

// Function for in-order traversal
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function for pre-order traversal
void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function for post-order traversal
void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Node* root = NULL;
    int key;

    // Taking user input for the key
    
    while (1) {
        printf("Enter a key to search/insert in the BST (enter -1 to exit): ");
        scanf("%d",&key);
        // Use the outer key variable
        if ( key == -1) {
            break;
        }
        
        // Perform insert and search operation
        root = insertAndSearch(root, key);
    }

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
