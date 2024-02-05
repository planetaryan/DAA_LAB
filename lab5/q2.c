#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new binary tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
void insert(TreeNode** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    TreeNode* current = *root;
    TreeNode* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (data < parent->data)
        parent->left = createNode(data);
    else
        parent->right = createNode(data);
}

// Function to calculate the height of a binary tree
int height(TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

// Function to find the diameter of a binary tree using DFS
int diameter(TreeNode* root) {
    if (root == NULL)
        return 0;

    // Calculate the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Calculate the diameter passing through the current node
    int diameterThroughRoot = leftHeight + rightHeight + 1;

    // Recursively calculate the diameters of the left and right subtrees
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    // Return the maximum of the three diameters
    return ((leftDiameter > rightDiameter) ? leftDiameter : rightDiameter);
}

// Driver function
int main() {
    TreeNode* root = NULL;
    int data;
    char choice;

    do {
        printf("Enter data for a node: ");
        scanf("%d", &data);
        insert(&root, data);
        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Calculate and print the diameter of the binary tree
    printf("Diameter of the binary tree is: %d\n", diameter(root));

    return 0;
}
