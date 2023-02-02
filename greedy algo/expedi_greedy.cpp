/* A group of cows grabbed a truck and ventured on an
expedition deep into the jungle. The truck leaks one unit of fuel in
every unit of distance it travels.
To repair the truck, the cows need to drive to the nearest town (no more than 10^6 units distance)
On this road, between the town and the current location, there are
N(1<=N<=10^5) fuel stops where the cows can stop to acquire
additional fuel (1......100 units at each stops)
The cows want to make the minimum possible number of stops for fuel
on the way to town.
Capacity of the tank is sufficiently large to hold any amount of fuel
Initial units of fuel: P(1<=P<=10^6)
Initial distance from town: L
Determine the minimum number of stops to reach the town
*/

/* optimal solution ->
1) Create a maxHeap, which stores the fuels available at the stops that
we have traversed
2) Sort the stops on the basis of distance of stops from
initial position of truck
3) Keep iterating on the stops, and whenever fuel in the 
tank of truck becomes empty, take the fuel from the maxHeap and add it
to the truck (greedy step)
4) Maintain the count of stops from which we have taken fuel 
*/
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first>>a[i].second;
        }
        int l,p;
        cin>>l>>p;

        for(int i=0;i<n;i++){
            a[i].first = l - a[i].first;
        }
        sort(a.begin(),a.end());

        int ans = 0;
        int curr = p;
        priority_queue<int,vector<int>> pq;
        bool flag = 0;
        for(int i=0;i<n;i++){
            if(curr >= l){
                break;
            }
            while(curr < a[i].first){
                if(pq.empty()){
                    flag=1;
                    break;
                }
                ans++;
                curr += pq.top();
                pq.pop();
            }
            if(flag) break;
            pq.push(a[i].second);
        }
        if(flag){
            cout<<"-1"<<endl;
            continue;
        }
        while(!pq.empty() && curr < l){
            curr += pq.top();
            pq.pop();
            ans++;
        }
        if(curr<l){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}