#include <stdio.h>
#include <stdlib.h>

// An AVL tree node
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function prototypes
struct Node* newNode(int key);
struct Node* insert(struct Node* root, int key);
struct Node* minValueNode(struct Node* node);
struct Node* maxValueNode(struct Node* node);
struct Node* search(struct Node* root, int key);
struct Node* successor(struct Node* root, int key);
struct Node* predecessor(struct Node* root, int key);

// A utility function to get maximum of two integers
int maximum(int a, int b) {
    return (a > b) ? a : b;
}

// A utility function to get height of the tree
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Helper function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially added at leaf
    return node;
}

// A utility function to right rotate subtree rooted with y
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = maximum(height(y->left), height(y->right)) + 1;
    x->height = maximum(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = maximum(height(x->left), height(x->right)) + 1;
    y->height = maximum(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted with node and returns the new root of the subtree.
struct Node* insert(struct Node* root, int key) {
    /* 1. Perform the normal BST insertion */
    struct Node* new_node = newNode(key);
    struct Node* parent = NULL;
    struct Node* current = root;

    if (root == NULL)
        return new_node;

    while (current != NULL) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else if (key > current->key)
            current = current->right;
        else // Equal keys are not allowed in BST
            return root;
    }

    if (key < parent->key)
        parent->left = new_node;
    else
        parent->right = new_node;

    /* 2. Update height of this ancestor node */
    parent->height = 1 + maximum(height(parent->left), height(parent->right));

    /* 3. Get the balance factor of this ancestor node to check whether this node became unbalanced */
    int balance = getBalance(parent);

    // If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balance > 1 && key < parent->left->key)
        return rightRotate(parent);

    // Right Right Case
    if (balance < -1 && key > parent->right->key)
        return leftRotate(parent);

    // Left Right Case
    if (balance > 1 && key > parent->left->key) {
        parent->left = leftRotate(parent->left);
        return rightRotate(parent);
    }

    // Right Left Case
    if (balance < -1 && key < parent->right->key) {
        parent->right = rightRotate(parent->right);
        return leftRotate(parent);
    }

    /* return the (unchanged) node pointer */
    return root;
}

// Function to find minimum value node in a subtree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // Loop down to find the leftmost leaf
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Function to find maximum value node in a subtree
struct Node* maxValueNode(struct Node* node) {
    struct Node* current = node;

    // Loop down to find the rightmost leaf
    while (current->right != NULL)
        current = current->right;

    return current;
}

// Function to search a given key in a given BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to find successor (next greater key)
struct Node* successor(struct Node* root, int key) {
    // Search for the given key in the tree
    struct Node* current = search(root, key);

    if (current == NULL)
        return NULL;

    // Case 1: Node has right subtree
    if (current->right != NULL)
        return minValueNode(current->right);

    // Case 2: No right subtree
    struct Node* successor = NULL;
    while (root != NULL) {
        if (current->key < root->key) {
            successor = root;
            root = root->left;
        } else if (current->key > root->key)
            root = root->right;
        else
            break; // Current node is the successor itself
    }

    return successor;
}

// Function to find predecessor (next smaller key)
struct Node* predecessor(struct Node* root, int key) {
    // Search for the given key in the tree
    struct Node* current = search(root, key);

    if (current == NULL)
        return NULL;

    // Case 1: Node has left subtree
    if (current->left != NULL)
        return maxValueNode(current->left);

    // Case 2: No left subtree
    struct Node* predecessor = NULL;
    while (root != NULL) {
        if (current->key > root->key) {
            predecessor = root;
            root = root->right;
        } else if (current->key < root->key)
            root = root->left;
        else
            break; // Current node is the predecessor itself
    }

    return predecessor;
}

// A utility function to print preorder traversal of the tree.
void preOrder(struct Node* root) {
    if(root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Driver program to test above functions
int main() {
    struct Node *root = NULL;

    /* Constructing tree given in the above figure */
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Preorder traversal of the AVL tree is: ");
    preOrder(root);
    printf("\n");

    int key = 30;
    struct Node* succ = successor(root, key);
    struct Node* pred = predecessor(root, key);

    if (succ != NULL)
        printf("Successor of %d is %d\n", key, succ->key);
    else
        printf("Successor of %d does not exist\n", key);

    if (pred != NULL)
        printf("Predecessor of %d is %d\n", key, pred->key);
    else
        printf("Predecessor of %d does not exist\n", key);

    return 0;
}
