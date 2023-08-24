#include <stdio.h>
#include <stdlib.h>
struct Node
 {
    int i,data;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b)
 {
    return (a > b) ? a : b;
}

int height(struct Node* node) 
{
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(struct Node* node)
 {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node* newNode(int data) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node* y)
 {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x) 
{
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct Node* insert(struct Node* node, int data) 
{
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Duplicate keys are not allowed in AVL
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) 
	{
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
	 {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void printTree(struct Node* node, int space) 
{
	int i;
    if (node == NULL)
        return;

    space += 5;

    printTree(node->right, space);

    printf("\n");
    for ( i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", node->data);

    printTree(node->left, space);
}

int main() 
{
    struct Node* root = NULL;
    int i;
    int data[] = {10, 20, 30, 40, 50, 25, 5};
    int n = sizeof(data) / sizeof(data[0]);

    for (i = 0; i < n; i++) 
	{
        root = insert(root, data[i]);
        printf("Insert: %d\n", data[i]);
        printTree(root, 0);
        printf("-------------------------\n");
    }

    return 0;
}

