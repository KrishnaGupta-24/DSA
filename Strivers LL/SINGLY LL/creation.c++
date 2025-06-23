#include<bits/stdc++.h>
using namespace std;
struct Node{
    public :
    int data;
    Node * next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};
int main(){
    Node y=Node(4,nullptr);
    cout<< y.data;
}