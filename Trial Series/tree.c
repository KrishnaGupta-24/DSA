#include<stdio.h>
#include<stdlib.h>
struct tree{
    struct tree * root;
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree * create(struct node * root){
    
}
int main(){
    struct tree * root =(struct tree*)malloc(sizeof(struct tree));
    root->data=1; 
    
}