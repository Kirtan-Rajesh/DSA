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
    int n,k;
    cin>>n>>k;
    vi a(n);
    int sm=0;
    rep(i,0,n){
        cin>>a[i];
        if(i<k) sm+=a[i];
    }
    int mn_sum = sm;
    for(int i=k;i<n;i++){
        sm = sm - a[i-k] + a[i];
        if(sm < mn_sum) mn_sum = sm;
    }
    cout<<mn_sum<<endl;
    return 0;
}
