#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


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


void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}


void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}


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

    
    
    while (1) {
        printf("Enter a key to search/insert in the BST (enter -1 to exit): ");
        scanf("%d",&key);
       
        if ( key == -1) {
            break;
        }
        
        
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
