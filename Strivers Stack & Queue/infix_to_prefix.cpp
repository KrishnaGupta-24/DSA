#include<bits/stdc++.h>
using namespace std;
string rev(string s){
    int i=0;
    int n=s.size();
    int j=n-1;
    while(i<j){
        swap(s[i],s[j]);
        i++;
        j--;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='(')s[i]=')';
        else if(s[i]==')')s[i]='(';
    }
    return s;
}
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
string infix_to_prefix(string s){
    s=rev(s);
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
    return rev(ans);
}

int main(){
    string s="(A+B)*C-D+F";
    string ans=infix_to_prefix(s);
    cout<<ans;
}