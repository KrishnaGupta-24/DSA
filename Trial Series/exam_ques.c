#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * prev;
};
int sumi(struct node * head){
    struct node * ptr=head;
    struct node *p=head;
    int cnt=1;
    while(p->next!=NULL){
        cnt++;
        p=p->next;
    }
    int i=1;
    int s=0;
    int max=0;
    do{
        s=(ptr->data)+(p->data);
        ptr=ptr->next;
        p=p->prev;
        if(s>max){
            max=s;
        }
        else{
            continue;
        }
        i++;
    }while(i!=(cnt/2)+1);
    return max;
}
int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    struct node *fourth=(struct node*)malloc(sizeof(struct node));
    struct node *fifth=(struct node*)malloc(sizeof(struct node));
    struct node *sixth=(struct node*)malloc(sizeof(struct node));

    head->data=23;
    second->data=12;
    third->data=6;
    fourth->data=34;
    fifth->data=18;
    sixth->data=5;

    head->next=second;
    head->prev=NULL;
    second->next=third;
    second->prev=head;
    third->next=fourth;
    third->prev=second;
    fourth->next=fifth;
    fourth->prev=third;
    fifth->next=sixth;
    fifth->prev=fourth;
    sixth->next=NULL;
    sixth->prev=fifth;

    int ans=sumi(head);
    printf("the maximum sum of the nodes of the doubly linked list %d",ans);
}