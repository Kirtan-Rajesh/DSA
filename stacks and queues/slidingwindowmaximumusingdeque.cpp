#include<iostream>
#include<deque>
#include<vector>
#include<set>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i: a) cin>>i;

    deque<int> q;
    vector<int> ans;
    for(int i=0;i<k;i++){
        while(!q.empty() && a[q.back()]<a[i]){
            q.pop_back();
        }
        q.push_back();
    }
    ans.push_back(a[q.front()]);
    for(int i=k;i<n;i++){
        if(q.front()==i-k){
            q.pop_front();
        }
        while(!q.empty() && a[q.back()]<a[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }
    // nlogn time complexity
    // multiset<int,greater<int>> s;
    // vector<int> ans;
    // for(int i=0;i<k;i++){
    //     s.insert(a[i]);
    // }
    // ans.push_back(*s.begin());
    // for(int i=k;i<n;i++){
    //     s.erase(s.lower_bound(a[i-k]));
    //     s.insert(a[i]);
    //     ans.push_back(*s.begin());
    // }
    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}