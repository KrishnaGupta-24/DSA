#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void traversing(struct node *head){
    struct node * ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;

    }
}
int main(){
    struct node * head; 
    struct node * second;
    struct node * third;

    //allocating memory for all the nodes created;
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));

    //linking and giving the data value
    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    traversing(head);

    return 0;
}