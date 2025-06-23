#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node * left;
    int data;
    struct node * right;
};
struct node *create(int data){
    struct node * n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
struct node *insert(struct node *root,int data){
    if(root==NULL){
        return create(data);
    }
    if(data<root->data){
        root->left= insert(root->left,data);
    }
    if(data>root->data){
        root->right= insert(root->right,data);
    }
    return root;
}
void travesal(struct node * root){
    if(root!=NULL){
        travesal(root->left);
        printf("%d ",root->data);
        travesal(root->right);
    }
}
struct node * inorder_predecessor(struct node * root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return  root;
}
struct node * delete(struct node * root,int val){
    struct node * ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left!=NULL){
        free(root);
        return NULL;
    }
    if(val<root->data){
        root->left=delete(root->left,val);
    }
    else if(val>root->data){
        delete(root->right,val);
    }
    else{
        ipre=inorder_predecessor(root);
        root->data=ipre->data;
        root->left=delete(root->left,ipre->data);
    }
    return root;
    
}
int main(){
    struct node * root=create(8);
    root=insert(root,3);
    root=insert(root,10);
    root=insert(root,1);
    root=insert(root,6);
    root=insert(root,14);
    root=insert(root,4);
    root=insert(root,7);
    root=insert(root,13);

    travesal(root);

    root=delete(root,6);

    printf("\nafter deletion of 6 and 14 \n");
    travesal(root);
}