#include<stdio.h>
#include<malloc.h>
struct node{
    struct node * left;
    int data;
    struct node * right;
};
struct node *create_node(int data){
    struct node *n=(struct node *)malloc(sizeof(struct node ));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void pre_order(struct node * root){
    if(root !=NULL){
        printf("%d ",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }

}
int main(){
    struct node *p1 = create_node(1);
    struct node *p2 = create_node(2);
    struct node *p3 = create_node(3);
    struct node *p4 = create_node(4);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4; 

    pre_order(p1);
}