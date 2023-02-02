#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int rain_water(vector<int> a){
    stack<int> st;
    int n=a.size();
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<a[i]){
            int cur=st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff = i - st.top() - 1;
            ans+=diff*(min(a[st.top(),a[i]])-a[cur]);
        }

    }
}

int main(){
    vector<int> a={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rain_water(a);
    return 0;
}