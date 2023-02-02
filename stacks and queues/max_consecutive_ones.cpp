#include<iostream>
#include<vector>
using namespace std;
int main(){
    //idea - find longest subarray with at most k zeros 
    // for each A[j] , try to find the longest subarray
    // if A[i]~A[j] has zeors<=k, we doo j++
    // if zero>k, we do i++, j++

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i:a){
        cin>>i;
    }
    int zerocnt=0,i=0,ans=0;
    for(int j=0;j<n;j++){
        if(a[j]==0){
            zerocnt++;
        }
        while(zerocnt>k){
            if(a[i]==0){
                zerocnt--;
            }
            i++;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans<<endl;
    return 0;
}