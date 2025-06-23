#include<bits/stdc++.h>
using namespace std;
class Q{
    int s=4;
    int q[4];
    int cur_size=0;
    int start=-1;
    int end=-1;
    public:
    void push(int x){
        if(cur_size==s){
            return;
        }
        if(cur_size==0){
            start++;
            end++;
        }
        else{
            end=(end+1)%s;
        }
        q[end]=x;
        cur_size++;
    }
    int pop(){
        if(cur_size==0){
            cout<<"queue underflow";
        }
        int ele=q[start];
        if(cur_size==1){
            start=end=-1;
        }
        else{
            start=(start+1)%s;
        }
        cur_size--;
        return ele;
    }

    int get_top(){
        if(cur_size==0){
            return 0;
        }
        return q[start];
    }
    int get_size(){
        return cur_size;
    }
};
int main(){
    Q q;
    int n;
    cout<<"enter no. of operations";
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