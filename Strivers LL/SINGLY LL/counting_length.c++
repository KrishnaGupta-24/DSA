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
Node * convert(vector<int> arr){
    Node * head=new Node (arr[0]);
    Node * ptr=head;
    for(int i=1;i<arr.size();i++){
        Node * temp=new Node (arr[i]);
        ptr->next=temp;
        ptr=temp;
    }
    return head;
}
int count_length(Node * head){
    int cnt=0;
    Node * temp=head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
int main(){
    int n;
    cout<<"enter the size of the array";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements of the array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node * head=convert(arr);
    int len=count_length(head);
    cout<<"length: "<<len;
}