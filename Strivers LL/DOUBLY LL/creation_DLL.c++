#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node * next;
    node * prev;
    node(int data1,node * next1,node * prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
    node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};
node * convert(vector<int> arr){
    node * head=new node(arr[0]);
    node * ptr=head;
    for(int i=1;i<arr.size();i++){
        node * temp=new node(arr[i]);
        ptr->next=temp;
        temp->prev=ptr;
        ptr=ptr->next;
    }
    return head;
}
void printing(node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){ 
    vector<int> arr={1,2,3,4,5};
    node * head=convert(arr);
    printing(head);
}