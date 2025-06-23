#include<bits/stdc++.h>
using namespace std;
struct  Node{
    int data;
    Node * next;
    Node(int d,Node *n){
        data=d;
        next=n;
    }
    Node (int d){
        data=d;
        next=nullptr;
    }
};
Node * convert(vector<int> arr){
    Node * head=new Node (arr[0]);
    Node * ptr=head;
    for(int i=0;i<arr.size();i++){
        Node * temp=new Node(arr[i]);
        ptr->next=temp;
        ptr=temp;
    }
    return head;
}
void printing(Node * head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node * delete_head(Node * head){
    if(head==NULL){
       return head; 
    }
    Node * temp=head;
    head=temp->next;
    free(temp);
    return head;
}
Node * delete_tail(Node * head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node * temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}
Node * delete_k(Node * head,int k){
    if(head==NULL){
        return head;
    }
    if(k==1){
        Node * temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node * temp=head;
    Node * ptr=head->next;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            temp->next=ptr->next;
            free(ptr);
        }
        temp=temp->next;
        ptr=ptr->next;
    }
    return head;
}
Node * delete_ele(Node * head,int ele){
    if(head==NULL){
        return head;
    }
    if(head->data==ele){
        Node * temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node * temp=head;
    Node * ptr=head->next;
    while(temp!=NULL){
        if(ptr->data==ele){
            temp->next=ptr->next;
            free(ptr);
            break;
        }
        ptr=ptr->next;
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    Node * head=convert(arr);
    printing(head);
    head=delete_head(head);
    cout<<endl;
    printing(head);
    head=delete_tail(head);
    cout<<endl;
    printing(head);
    head=delete_k(head,4);
    cout<<endl;
    printing(head);
    head=delete_ele(head,6);
    cout<<endl;
    printing(head);
}