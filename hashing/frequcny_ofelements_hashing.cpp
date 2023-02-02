#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

int main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n) cin>>a[i];
    map<int,int> freq;
    rep(i,0,n){
        freq[a[i]]++;
    }
    map<int,int>::iterator it;
    for(it = freq.begin();it!=freq.end();it++){
        cout<<it->ff<<" "<<it->ss<<endl;
    }
    return 0;
}