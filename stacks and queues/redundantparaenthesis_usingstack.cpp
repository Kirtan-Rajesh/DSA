#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<char> st;
    bool check=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.top()=='(') check=true;
            while(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/'){
                st.pop();
            }
            st.pop();
        }
    }
    if(check) cout<<"Redundant brackets"<<endl;
    else cout<<"no Redundant brackets"<<endl;
    return 0;
}