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
struct node *insert_begin(struct node * head,int val){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=head;
    head=temp;
    return head;
}
void insert_end(struct node * head,int val){
    struct node * temp=(struct node *)malloc(sizeof(struct node ));
    temp->data=val;
    struct node * ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->next=NULL;
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
    head=insert_begin(head,0);
    printf("\nAfter inserting at begin \n");
    traversing(head);
    insert_end(head,4);
    printf("\n After inserting at the end of the list\n");
    traversing(head);

    return 0;
}