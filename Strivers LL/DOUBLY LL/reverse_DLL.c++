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
node * convert(vector<int>arr){
    node * head=new node(arr[0]);
    node * ptr=head;
    for(int i=1;i<arr.size();i++){
        node * temp=new node(arr[i]);
        ptr->next=temp;
        temp->prev=ptr;
        ptr=temp;
    }
    return head;
}
void printing (node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
node * reverse(node * head){
    node * tail=head;
    node * temp=head;
    int n=0;
    while(tail->next!=NULL){
        tail=tail->next;
        n++;
    }
    for(int i=0;i<=n/2;i++){
        swap(temp->data,tail->data);
        temp=temp->next;
        tail=tail->prev;
    }
    return head;
}
node * reverse2(node * head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node * prev=NULL;
    node * current=head;
    while(current!=NULL){
        prev=current->prev;
        current->prev=current->next;
        current->next=prev;
        current=current->prev;
    }
    return prev->prev;
}
int main(){
    int n;
    cout<<"enter the no. of elements";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node * head=convert(arr);
    printing(head);
    head=reverse(head);
    cout<<endl;
    printing(head);


    head=reverse2(head);
    cout<<endl;
    printing(head);
}