#include<bits/stdc++.h>
using namespace std;
string prefix_postfix(string s){
    int i=s.size()-1;
    string con;
    stack<string>st;
    while(i>=0){
        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9'){
            st.push(string (1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            con=t1+t2+s[i];
            st.push(con);
        }
        i--;
    }
    return st.top();
}
int main(){
    string s="/-AB*+DEF";
    string ans=prefix_postfix(s);
    cout<<ans;
}