#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node using typedef
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inorder traversal (Left -> Root -> Right)
void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Preorder traversal (Root -> Left -> Right)
void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal (Left -> Right -> Root)
void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Function to build tree recursively from user input
Node *buildTree()
{
    int value;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &value);

    if (value == -1) // If user enters -1, return NULL (no child)
        return NULL;

    Node *newNode = createNode(value);
    printf("Enter left child of %d:\n", value);
    newNode->left = buildTree(); // Recursively build left subtree
    printf("Enter right child of %d:\n", value);
    newNode->right = buildTree(); // Recursively build right subtree

    return newNode;
}

void main()
{
    printf("Build your binary tree:\n");
    Node *root = buildTree(); // Build the tree interactively

    printf("\nInorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");
}
