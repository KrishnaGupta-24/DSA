#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node * left;
    int data;
    struct node * right;
};
struct node *create(int data){
    struct node * n=(struct node *)malloc(sizeof(struct node));
    n->left=NULL;
    n->data=data;
    n->right=NULL;
    return n;
}
struct node * insert(struct node * root,int data){
    if(root==NULL){
        return create(data);
    }
    if(data>root->data){
        root->right = insert(root->right, data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    return root;
}
void traversal(struct node * root){
    if(root!=NULL){
        traversal(root->left);
        printf("%d ",root->data);
        traversal(root->right);
    }
}
int main(){
    struct node * root=create(10);
    root=insert(root,7);
    root=insert(root,2);
    root=insert(root,5);
    root=insert(root,4);
    root=insert(root,12);
    root=insert(root,9);
    root=insert(root,3);

    traversal(root);
}