#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * prev;
};
void traversing(struct node * head){
    struct node * ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
struct node * insert_begin(struct node * head,int val){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->prev=NULL;
    
    head->prev=temp;
    temp->next=head;
    head=temp;
    return head;
}
int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    
    head->data=1;
    second->data=2;
    third->data=3;
    fourth->data=4;

    head->next=second;
    head->prev=NULL;

    second->next=third;
    second->prev=head;

    third->next=fourth;
    third->prev=second;

    fourth->next=NULL;
    fourth->prev=third;

    traversing(head);
    head=insert_begin(head,0);
    printf("\n After inserting at the begin\n");
    traversing(head);
    return 0;
}