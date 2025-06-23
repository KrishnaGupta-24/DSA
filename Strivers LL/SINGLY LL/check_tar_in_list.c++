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
int check(Node * head,int tar){
    Node * temp=head;
    while(temp){
        if(temp->data==tar){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
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
    int tar;
    cout<<"enter the targeted value";
    cin>> tar;
    int ans=check(head,tar);
    if(ans){
        cout<<"present";
    }
    else{
        cout<<"not present";
    }
}