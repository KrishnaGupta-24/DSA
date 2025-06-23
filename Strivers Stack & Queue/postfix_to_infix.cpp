#include<bits/stdc++.h>
using namespace std;
string postfix_infix(string s){
    int i=0;
    int n=s.size();
    string con;
    stack<string> st;
    while(i<n){
        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9'){
            st.push(string(1, s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            con='('+t2+s[i]+t1+')';
            st.push(con);
        }
        i++;
    }
    return st.top();
}
int main(){
    string s="AB-DE+F*/";
    string ans=postfix_infix(s);
    cout<<ans;
}