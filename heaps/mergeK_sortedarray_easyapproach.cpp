#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> mergeKSortedArray(vector<vector>&arr,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        for(int elem: arr[i]){
            pq.push(elem);
        }
    }
    vector<int> ans;
    while(!pq.empty()){
        int num = pq.top();
        pq.pop();
        ans.push_back(num);
    }
    return ans;
}
int main()
{
    return 0;
}