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
void insert_middle(struct node * head,int val){
    //for accesing the middle element
    struct node *ptr=head;
    struct node *p=head;//middle element pointer
    while(ptr->next->next!=NULL){
        ptr=ptr->next->next;
        p=p->next;
    }
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=p->next;
    p->next=temp;
}
void insert_pos(struct node * head,int pos,int val){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    struct node *ptr=head;
    int k=1;
    while(k!=pos-1){
        ptr=ptr->next;
        k++;
    }
    temp->data=val;
    temp->next=ptr->next;
    ptr->next=temp;
}
int main(){
    struct node * head; 
    struct node * second;
    struct node * third;
    struct node * fourth;

    //allocating memory for all the nodes created;
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    //linking and giving the data value
    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=NULL;

    insert_middle(head,0);
    printf("\n inserting at the middle \n");
    traversing(head); 

    printf("\n inserting using position 2\n");
    insert_pos(head,2,7);  
    traversing(head);

    return 0;
}