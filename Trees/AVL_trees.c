#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
};
int get_height(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return n->height;
    }
}
struct node *create_node(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int get_balance(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return get_height(n->left) - get_height(n->right);
}
struct node *right_rotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(get_height(y->right), get_height(y->left)) + 1;
    x->height = max(get_height(x->right), get_height(x->left)) + 1;

    return x;
}
struct node *left_rotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = x->left;

    y->left = x;
    x->right = t2;

    y->height = max(get_height(y->right), get_height(y->left)) + 1;
    x->height = max(get_height(x->right), get_height(x->left)) + 1;

    return y;
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return create_node(key);
    }

    if (key < node->data)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->data)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }
    node->height = 1 + max(get_height(node->left), get_height(node->right));

    int bf = get_balance(node);

    // Left-Left case
    if (bf > 1 && key < node->left->data)
    {
        return right_rotate(node);
    }
    // Right-Right case
    if (bf < -1 && key > node->right->data)
    {
        return left_rotate(node);
    }
    // Left-Right case
    if (bf > 1 && key > node->left->data)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    // Right-Left case
    if (bf < -1 && key < node->right->data)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}
void pre_order_traversal(struct node *n)
{
    if (n != NULL)
    {
        printf("%d ", n->data);
        pre_order_traversal(n->left);
        pre_order_traversal(n->right);
    }
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    pre_order_traversal(root);
    return 0;
}