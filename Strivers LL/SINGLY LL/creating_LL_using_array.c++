#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(int d,Node * n){
        data=d;
        next=n;
    }
    Node(int d){
        data=d;
        next=nullptr;
    }
};
Node * convert(vector<int>&arr,int n){
    Node * head=new Node(arr[0]);
    Node * ptr=head;
    for(int i=1;i<n;i++){
        Node * temp=new Node(arr[i]);
        ptr->next=temp;
        ptr=temp;
    }
    return head;
}
void printing(Node * head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    int n;
    cout<<"enter the no. elements";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements of the array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node * head=convert(arr,n);
    printing(head);
}