#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inorder traversal (Left -> Root -> Right)
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Preorder traversal (Root -> Left -> Right)
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal (Left -> Right -> Root)
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

struct Node* buildTree() 
{
    int value;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &value);
    
    if (value == -1)  // If user enters -1, return NULL (no child)
        return NULL;

    struct Node* newNode = createNode(value);
    printf("Enter left child of %d:\n", value);
    newNode->left = buildTree();  // Recursively build left subtree
    printf("Enter right child of %d:\n", value);
    newNode->right = buildTree(); // Recursively build right subtree

    return newNode;
}

int main() 
{
    printf("Build your binary tree:\n");
    struct Node* root = buildTree();  // Build the tree
    
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}