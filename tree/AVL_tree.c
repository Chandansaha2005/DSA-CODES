#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct node
{
    int data;
    struct node *left, *right;
    int ht;
} node;

// Function prototypes
node *insert(node *, int);
node *Delete(node *, int);
void preorder(node *);
void inorder(node *);
int height(node *);
int BF(node *);
node *rotateright(node *);
node *rotateleft(node *);
node *LL(node *);
node *RR(node *);
node *LR(node *);
node *RL(node *);

int main()
{
    node *root = NULL;
    int x, n, i, op;

    do
    {
        printf("\n1)Create");
        printf("\n2)Insert");
        printf("\n3)Delete");
        printf("\n4)Print");
        printf("\n5)Quit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Enter no. of elements: ");
            scanf("%d", &n);
            printf("Enter tree data:\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &x);
                root = insert(root, x);
            }
            break;
        case 2:
            printf("Enter a data: ");
            scanf("%d", &x);
            root = insert(root, x);
            break;
        case 3:
            printf("Enter a data: ");
            scanf("%d", &x);
            root = Delete(root, x);
            break;
        case 4:
            if (root == NULL)
            {
                printf("Tree is empty.\n");
            }
            else
            {
                printf("Preorder sequence:\n");
                preorder(root);
                printf("\n\nInorder sequence:\n");
                inorder(root);
                printf("\n");
            }
            break;
        }
    } while (op != 5);

    return 0;
}

// AVL operations
node *insert(node *T, int x)
{
    if (T == NULL)
    {
        T = (node *)malloc(sizeof(node));
        T->data = x;
        T->left = T->right = NULL;
        T->ht = 0;
    }
    else if (x < T->data)
    {
        T->left = insert(T->left, x);
        if (BF(T) == 2)
            T = (x < T->left->data) ? LL(T) : LR(T);
    }
    else if (x > T->data)
    {
        T->right = insert(T->right, x);
        if (BF(T) == -2)
            T = (x > T->right->data) ? RR(T) : RL(T);
    }
    T->ht = height(T);
    return T;
}

node *Delete(node *T, int x)
{
    if (T == NULL)
        return NULL;

    if (x < T->data)
    {
        T->left = Delete(T->left, x);
        if (BF(T) == -2)
            T = (BF(T->right) <= 0) ? RR(T) : RL(T);
    }
    else if (x > T->data)
    {
        T->right = Delete(T->right, x);
        if (BF(T) == 2)
            T = (BF(T->left) >= 0) ? LL(T) : LR(T);
    }
    else
    {
        if (T->right != NULL)
        {
            node *p = T->right;
            while (p->left != NULL)
                p = p->left;
            T->data = p->data;
            T->right = Delete(T->right, p->data);
            if (BF(T) == 2)
                T = (BF(T->left) >= 0) ? LL(T) : LR(T);
        }
        else
        {
            node *temp = T->left;
            free(T);
            return temp;
        }
    }

    T->ht = height(T);
    return T;
}

// Utility functions
int height(node *T)
{
    int lh = (T && T->left) ? 1 + T->left->ht : 0;
    int rh = (T && T->right) ? 1 + T->right->ht : 0;
    return (lh > rh) ? lh : rh;
}

int BF(node *T)
{
    int lh = (T && T->left) ? 1 + T->left->ht : 0;
    int rh = (T && T->right) ? 1 + T->right->ht : 0;
    return lh - rh;
}

// Rotations
node *rotateright(node *x)
{
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node *rotateleft(node *x)
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node *LL(node *T)
{
    return rotateright(T);
}
node *RR(node *T)
{
    return rotateleft(T);
}
node *LR(node *T)
{
    T->left = rotateleft(T->left);
    return rotateright(T);
}
node *RL(node *T)
{
    T->right = rotateright(T->right);
    return rotateleft(T);
}

// Traversals
void preorder(node *T)
{
    if (T != NULL)
    {
        printf("%d(BF=%d) ", T->data, BF(T));
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(node *T)
{
    if (T != NULL)
    {
        inorder(T->left);
        printf("%d(BF=%d) ", T->data, BF(T));
        inorder(T->right);
    }
}
