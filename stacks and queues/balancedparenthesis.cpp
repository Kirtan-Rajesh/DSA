#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    int n = s.size();
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st.empty() && st.top()=='('){
                st.pop();
            } else {
                return false;
            }
        }
        else if(s[i]=='}'){
            if(!st.empty() && st.top()=='{'){
                st.pop();
            } else {
                return false;
            }
        }
        else if(s[i]==']'){
            if(!st.empty() && st.top()=='['){
                st.pop();
            } else {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    string s="{([)]}";
    if(isValid(s)){
        cout<<"Valid string"<<endl;
    } else cout<<"Invalid string"<<endl;
    return 0;
}