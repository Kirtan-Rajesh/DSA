#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

int main()
{
    int n,k;
    cin>>n>>k;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int ct=0;
    map<int,int> m;
    rep(i,0,n){
        int sz = m.size();
        if(m[a[i]]==0 && sz==k) break;
        m[a[i]]++;
    }
    map<int,int>::iterator it;
    vii ans;
    for(it=m.begin();it!=m.end();it++){
        if((it->ss)==0) continue;
        pii p;
        p.ff = it->ff;
        p.ss = it->ss;
        ans.push_back(p);
    }
    sort(ans.begin(),ans.end(),greater<pii>());
    vii ::iterator it2;
    for(it2 = ans.begin();it2!=ans.end();it2++){
        cout<<it2->ff<<" "<<it2->ss<<endl;
    }
    return 0;
}