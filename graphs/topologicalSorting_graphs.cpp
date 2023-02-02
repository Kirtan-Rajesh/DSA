/* A Topological Ordering is an ordering of the nodes in a 
directed graph where for each directed edge from node A 
to node B, node A appears before node B in the ordering.
*/

// NOTE -> topological ordering is not unique
// NOTE -> not every graph has a topological sort

// NOTE -> only directed acyclic graph has topological order

/* ALGORITHM 
While(All the nodes are not visited)
Nodes with zero Indegree can be added to the output 
All the nodes which are adjacent to terminal nodes, gets
their Indegree subtracted.*/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int cnt = 0;
    vector<vector<int>> adj(n);
    vector<int> indeg(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> pq;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        cnt++;
        int x = pq.front();
        pq.pop();
        cout<<x<<" ";
        for(auto it: adj[x]){
            indeg[it]--;
            if(indeg[it]==0){
                pq.push(it);
            }
        } 
    }
    return 0;
}