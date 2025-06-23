#include<bits/stdc++.h>
using namespace std;
string postfix_prefix(string s){
    int i=0;
    int n=s.size();
    stack<string> st;
    string str;
    string con;
    while(i<n){
        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9'){
            str=s[i];
            st.push(str);
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            con=s[i]+t2+t1;
            st.push(con);
        }
        i++;
    }
    return st.top();
}
int main(){
    string s="AB-DE+F*/";
    string ans=postfix_prefix(s);
    cout<<ans;
}