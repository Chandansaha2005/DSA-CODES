#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left, *right;
} Node;

// Function to create a new node with a given value
Node *newNodeCreate(int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to search for a node with a specific key in the tree
Node *searchNode(Node *root, int target)
{
    if (root == NULL || root->key == target)
        return root;
    if (root->key < target)
        return searchNode(root->right, target);
    return searchNode(root->left, target);
}

// Function to insert a node with a specific value in the tree
Node *insertNode(Node *node, int value)
{
    if (node == NULL)
        return newNodeCreate(value);
    if (value < node->key)
        node->left = insertNode(node->left, value);
    else if (value > node->key)
        node->right = insertNode(node->right, value);
    return node;
}

// Function to perform post-order traversal
void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}

// Function to perform in-order traversal
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}

// Function to perform pre-order traversal
void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to find the minimum value
Node *findMin(Node *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left != NULL)
        return findMin(root->left);
    return root;
}

// Function to delete a node from the tree
Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
        return NULL;
    if (x > root->key)
        root->right = deleteNode(root->right, x);
    else if (x < root->key)
        root->left = deleteNode(root->left, x);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL)
        {
            Node *temp;
            if (root->left == NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. In-order Traversal\n");
        printf("5. Pre-order Traversal\n");
        printf("6. Post-order Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (searchNode(root, value) != NULL)
                printf("%d found in tree.\n", value);
            else
                printf("%d not found in tree.\n", value);
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Node %d deleted (if it existed).\n", value);
            break;
        case 4:
            printf("In-order Traversal: ");
            inOrder(root);
            printf("\n");
            break;
        case 5:
            printf("Pre-order Traversal: ");
            preOrder(root);
            printf("\n");
            break;
        case 6:
            printf("Post-order Traversal: ");
            postOrder(root);
            printf("\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
