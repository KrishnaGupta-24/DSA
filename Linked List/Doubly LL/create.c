#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * prev;
};
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

    return 0;
}