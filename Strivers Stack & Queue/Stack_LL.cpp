#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node * next;
    Node (int x,Node * next){
        data=x;
        this->next=next;
    }
    Node(int x){
        data=x;
        this->next=nullptr;
    }
};
class sta{
    public:
    Node * top=nullptr;
    int s=0;
    void push(int x){
        Node * temp=new Node(x);
        temp->next=top;
        top=temp;
        s++;
    }
    void pop(){
        Node * temp=top;
        top=top->next;
        delete top;
        s--;
    }
    int get_size(){
        return s;
    }
    int get_top(){
        return top->data;
    }
};
int main(){
    sta st;
    int i=0;
    int n;
    cout<<"enter the no. of operations";
    cin>>n;
    int ch;
    while(i<n){
        cout<<"select the given options: \n 1: for push \n 2: for pop \n 3: for top \n 4: for size\n";
        cin>>ch;
        if(ch==1){
            int val;
            cout<<"enter the value\n";
            cin>>val;
            st.push(val);
        }
        if(ch==2){
            st.pop();
        }
        if(ch==3){
            int val=st.get_top();
            cout<<val<<endl;
        }
        if(ch==4){
            cout<<st.get_size();
        }
        i++;
    }
}