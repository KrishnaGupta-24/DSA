#include<bits/stdc++.h>
using namespace std;
class sta{
    public:
    int top=-1;
    int st[10];
    void push(int x){
        if(top>=10){
            cout<<"stack overflow\n";
            return;
        }
        top=top+1;
        st[top]=x;
    }

    int get_top(){
        if(top==-1){
            cout<<"stack is empty\n";
            return -1;
        }
        return st[top];
    }
    void pop(){
        if(top==-1){
            cout<<"stack underflow\n";
            return;
        }
        top=top-1;
    }
    int size(){
        return top+1;
    }
};
int main(){
    sta st;
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
            cout<<st.size();
        }
        i++;
    }
}