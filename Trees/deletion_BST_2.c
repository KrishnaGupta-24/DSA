#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};

// Function to create a new node
struct node *create(int data) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to insert a node into the BST
struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return create(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// In-order traversal function
void traversal(struct node *root) {
    if (root != NULL) {
        traversal(root->left);
        printf("%d ", root->data);
        traversal(root->right);
    }
}

// Function to find the in-order predecessor of a node
struct node *inorder_predecessor(struct node *root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to delete a node in the BST
struct node *delete(struct node *root, int val) {
    if (root == NULL) {
        return NULL;  // Node not found
    }

    // If the value to be deleted is smaller than the root's data, go left
    if (val < root->data) {
        root->left = delete(root->left, val);
    }
    // If the value to be deleted is greater than the root's data, go right
    else if (val > root->data) {
        root->right = delete(root->right, val);
    }
    // If root's data is equal to the value to be deleted
    else {
        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children: Get the in-order predecessor (max in the left subtree)
        struct node *ipre = inorder_predecessor(root);
        root->data = ipre->data;  // Copy the in-order predecessor's data
        root->left = delete(root->left, ipre->data);  // Delete the in-order predecessor
    }
    return root;
}

int main() {
    struct node *root = create(8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);

    printf("Initial tree (in-order traversal): \n");
    traversal(root);
    printf("\n");

    root = delete(root, 6);  // Deleting node 6
    root = delete(root, 14); // Deleting node 14

    printf("After deletion of 6 and 14 (in-order traversal): \n");
    traversal(root);
    printf("\n");

    return 0;
}
