#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node * next;
    node * prev;
    node(int d,node * n, node * p){
        data=d;
        next=n;
        prev=p;
    }
    node(int d){
        data=d;
        next=nullptr;
        prev=nullptr;
    }
};
node * convert(vector<int> arr){
    node * head=new node(arr[0]);
    node * temp=head;
    for(int i=1;i<arr.size();i++){
        node * ptr=new node(arr[i]);
        temp->next=ptr;
        ptr->prev=temp;
        temp=ptr;
    }
    return head;
}
void printing(node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
node * insert_head(node * head,int val){
    node * temp=new node(val,head,nullptr);
    head->prev=temp;
    return temp;
}
void insert_tail(node * head,int val){
    node * ptr=new node(val);
    node * temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    ptr->prev=temp->prev;
    temp->prev->next=ptr;
    temp->prev=ptr;
    ptr->next=temp;
}
int main(){
    vector<int> arr={2,3,4,6};
    node * head=convert(arr);
    printing(head);

    head=insert_head(head,1);
    cout<<endl;
    printing(head);

    insert_tail(head,5 );
    cout<<endl;
    printing(head);
}