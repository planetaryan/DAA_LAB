#include<stdio.h>
#include<stdlib.h>

// An AVL tree node
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// A utility function to get the height of the tree
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int maximum(int a, int b) {
    return (a > b) ? a : b;
}

// Helper function that allocates a new node with the given key
struct Node* createnewNode(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // new node is initially added at leaf
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

// Iterative function to insert a key in the subtree rooted with node and returns the new root of the subtree
struct Node* insert(struct Node* root, int key) {
    struct Node *newNode = createnewNode(key);
    if (root == NULL)
        return newNode;

    struct Node *parent = NULL;
    struct Node *current = root;

    while (current != NULL) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else if (key > current->key)
            current = current->right;
        else
            return root; // Equal keys are not allowed in BST
    }

    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    // Update heights and balance the tree
    struct Node *ptr = root;
    while (ptr != NULL) {
        ptr->height = maximum(height(ptr->left), height(ptr->right)) + 1;

        int balance = getBalance(ptr);

        // If this node becomes unbalanced, then there are 4 cases
        if (balance > 1 && key < ptr->left->key)
            return rightRotate(ptr);
        if (balance < -1 && key > ptr->right->key)
            return leftRotate(ptr);
        if (balance > 1 && key > ptr->left->key) {
            ptr->left = leftRotate(ptr->left);
            return rightRotate(ptr);
        }
        if (balance < -1 && key < ptr->right->key) {
            ptr->right = rightRotate(ptr->right);
            return leftRotate(ptr);
        }

        if (key < ptr->key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    return root;
}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct Node *root) {
    if(root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* Driver program to test above function*/
int main() {
    struct Node *root = NULL;

    /* Constructing tree given in the above figure */
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 11);
    root = insert(root, 12);
    root = insert(root, 18);
    root = insert(root, 17);

    /* The constructed AVL Tree would be
               12
            /    \
           8      18
         /  \    /
        5   11  17
    */

    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);

    return 0;
}
