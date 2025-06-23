#include<bits/stdc++.h>
using namespace std;
int prior(char ch){
    if(ch=='^'){
        return 3;
    }
    if(ch=='*'||ch=='/'){
        return 2;
    }
    if(ch=='+'||ch=='-'){
        return 1;
    }
    return -1;
}
string infix_to_postfix(string s){
    int i=0;
    stack<char>st;
    int n=s.size();
    string ans="";
    while(i<n){
        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<'z' || s[i]>='0' && s[i]<='9'){
            ans=ans+s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(st.top()!='('){
                ans=ans+st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prior(s[i])<=prior(st.top())){
                ans=ans+st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans=ans+st.top();
        st.pop();
    }
    return ans;
}
int main(){
    string s="a+b*(c^d-e)";
    string ans=infix_to_postfix(s);
    cout<<ans;
}