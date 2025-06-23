#include<bits/stdc++.h>
using namespace std;
string postfix_infix(string s){
    int n=s.size();
    int i=n-1;
    stack<string> st;
    string con;
    while(i>=0){
        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9'){
            st.push(string (1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            con='('+t1+s[i]+t2+')';
            st.push(con);
        }
        i--;
    }
    return st.top();
}
int main(){
    string s="*+PQ-MN";
    string ans=postfix_infix(s);
    cout<<ans;

}