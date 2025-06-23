#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node * next;
    node * prev;
    node(int d,node * n,node * p){
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
    node * ptr=head;
    for(int i=1;i<arr.size();i++){
        node * temp=new node(arr[i]);
        ptr->next=temp;
        temp->prev=ptr;
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
node * delete_head(node * head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    node * ptr=head;
    head=ptr->next;
    head->prev=NULL;
    free(ptr);
    return head;
}
node * delete_tail(node * head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    node * ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    node * temp=ptr->next;
    ptr->next=NULL;
    free(temp);
    return head;
}
node * delete_k(node * head,int k){
    if(head==NULL){
        return NULL;
    }
    int cnt=0;
    node * k_node=head;
    while(k_node!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        k_node=k_node->next;
    }
    node * ptr=k_node->prev;
    node * front=k_node->next;
    if(ptr==NULL || front==NULL){
        return NULL;
    }
    else if(ptr==NULL){
        return delete_head(head);
    }
    else if( front==NULL){
        return delete_tail(head);
    }

    ptr->next=front;
    front->prev=ptr;
    k_node->next=nullptr;
    k_node->prev=nullptr;
    free(k_node);
    return head;
}
node * delete_node(node * head,int val){
    node * temp=head;
    while(temp->data!=val){
        temp=temp->next;
    }
    node * front =temp->next;
    node * back=temp->prev;
    if(front==NULL){
        back->next=NULL;
        free(temp);
        return head;
    }
    back->next=front;
    front->prev=back;
    free(temp);
    return head;
}
int main(){
    vector<int> arr={0,1,2,3,4,5};
    node * head=convert(arr);
    printing(head);
    head=delete_head(head);
    cout<<endl;
    printing(head);

    head=delete_tail(head);
    cout<<endl;
    printing(head);

    head=delete_k(head,3);
    cout<<endl;
    printing(head);
    
    head=delete_node(head,4);
    cout<<endl;
    printing(head);
}