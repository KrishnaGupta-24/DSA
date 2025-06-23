#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node * left;
    int data;
    struct node * right;
};
struct node *create(int data){
    struct node* n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int is_BST(struct node * root){
    struct node * prev=NULL;
    if(root!=NULL){
        if(!is_BST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return is_BST(root->right);
    }
    else{
        return 1;
    }
}
void display(struct node * root){
    if(root!=NULL){
        display(root->left);
        printf("%d ",root->data);
        display(root->right);
    }
}
int main(){
    struct node * p1=create(9);
    struct node * p2=create(4);
    struct node * p3=create(11);
    struct node * p4=create(2);
    struct node * p5=create(7);
    struct node * p6=create(15);
    struct node * p7=create(5);
    struct node * p8=create(8);
    struct node * p9=create(14);

    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    p3->right=p6;
    p6->left=p9;
    p5->left=p7;
    p5->right=p8;

    display(p1);
    int is_bst=is_BST(p1);
    if(is_bst==0){
        printf("not a Binary Search Tree");
    }
    else{
        printf("Binary Search Tree");
    }
}