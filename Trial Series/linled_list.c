#include<stdio.h>
struct node{
    int data;
    struct node * next;

};
int create(){
}
int insert_str(struct node * head,int val){
    struct node * temp=(struct node * )malloc (sizeof(struct node ));
    temp->next=head;
    temp->data=val;
    head=temp;
    return head;
}
void traversal(struct node * head){
    struct node *ptr=head;
    while(ptr->next!=NULL){
        printf("%d\n",ptr->data);
    }
}
int main(){
    struct node n1;
    
}