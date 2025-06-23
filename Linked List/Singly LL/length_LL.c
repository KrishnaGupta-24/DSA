#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
int count(struct node * head){
    struct node *ptr=head;
    int count=1;
    while(ptr->next!=NULL){
        count++;
        ptr=ptr->next;
    }
    return count;
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

    printf("%d",count(head));
}