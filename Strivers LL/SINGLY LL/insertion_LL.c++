#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
    node(int d,node* n){
        data=d;
        next=n;
    }
    node(int d){
        data=d;
        next=nullptr;
    }
};
node * convert(vector<int> arr){
    node * head=new node( arr[0]);
    node * ptr=head;
    for(int i=1;i<arr.size();i++){
        node * temp=new node (arr[i]);
        ptr->next=temp;
        ptr=temp;
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
    node * temp=new node(val,head);
    return temp;
}
node * insert_end(node * head,int val){
    node * temp=new node(val);
    node * ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    return head;
}
node * insert_k(node * head,int val,int k){
    if(head==NULL){
        return new node(val);   
    }
    node * temp=new node(val);
    int cnt=1;
    node * ptr=head;
    while(cnt!=k-1){
        ptr=ptr->next;
        cnt++;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    return head;

}
int main(){ 
    vector<int> arr={2,3,4,5,6};
    node * head=convert(arr);
    printing(head);
    head=insert_head(head,1);
    cout<<endl;
    printing(head);
    head=insert_end(head,7);
    cout<<endl;
    printing(head);
    head=insert_k(head,0,2);
    cout<<endl;
    printing(head);
}