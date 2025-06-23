#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node( int x,Node * next){
        this->data=x;
        this->next=next;
    }
    Node (int x){
        data=x;
        this->next=nullptr;
    }
};
class Q{
    public:
    Node * start=NULL;
    Node * end=NULL;
    int s=0;
    void push(int x){
        Node * temp=new Node (x);
        if(start==NULL){
            start=temp;
            end=temp;
        }
        else{
            end->next=temp;
            end=temp;
        }
        s++;
    } 
    void pop(){
        if(start==NULL){
            cout<<"underflow";
            return ;
        }
        Node * temp=start;
        start=start->next;
        delete temp;
        s--;

    }
    int get_top(){
        if(start==NULL){
            return 0;
        }
        return start->data;
    }
    int get_size(){
        return s;
    }
};
int main(){
    Q q;
    int n;
    cout<<"enter the no. of operations";
    cin>>n;
    int i=0;
    int ch;
    while(i<n){
        cout<<"select the given options: \n 1: for push \n 2: for pop \n 3: for top \n 4: for size\n";
        cin>>ch;
        if(ch==1){
            int val;
            cout<<"enter the value\n";
            cin>>val;
            q.push(val);
        }
        if(ch==2){
            q.pop();
        }
        if(ch==3){
            int val=q.get_top();
            cout<<val<<endl;
        }
        if(ch==4){
            cout<<q.get_size();
        }
        i++;
    }
}