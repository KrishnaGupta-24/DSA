#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node * left;
    int data;
    struct node * right;
};
struct node * create(int data){
    struct node * n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
struct node * search(struct node * root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
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

    struct node *n=search(p1,10);
    if(n!=NULL){
        printf("element found");
    }
    else{
        printf("not found");
    }
}   