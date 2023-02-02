#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i:a) cin>>i;
    sort(a.begin(),a.end());
    long long mn=0,mx=0;
    for(int i=0;i<n/2;i++){
        mx += (a[n/2 + i]-a[i]);
        mn += (a[2*i+1]-a[2*i]);
    }
    cout<<mn<<" "<<mx<<endl;
    return 0;
}