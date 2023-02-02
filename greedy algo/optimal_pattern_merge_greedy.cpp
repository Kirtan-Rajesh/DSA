/*You are given n files with their computation times in an array.
n: Choose/take any two files, add their computation
times and append it to the list of computation times. 
{Cost Sum of computation time} 
Do this until we are left with only one file in the array.
We have to do this operation such that we get minimum cost finally.*/

#include<iostream>
#include<queue>
#include<map>
#include<unordered_map>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

int main(){
    int n;
    cin>>n;

    vi a(n);
    priority_queue<int,vector<int>,greater<int>> pq;
    rep(i,0,n){
        cin>>a[i];
        pq.push(a[i]);
    }
    int ans=0;
    while(pq.size()>1){
        int op1=pq.top();
        pq.pop();
        int op2=pq.top();
        pq.pop();
        ans+=op1+op2;
        pq.push(op1+op2);
    }
    cout<<ans<<endl;
    

    return 0;
}