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
struct node * delete_begin(struct node * head){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
void delete_end(struct node * head){
    struct node *ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=NULL;
    
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

    head=delete_begin(head);
    printf("\n after deletion of the first node\n");
    traversing(head);
    delete_end(head);
    printf("\n deleting the last node\n");
    traversing(head);

    return 0;
}