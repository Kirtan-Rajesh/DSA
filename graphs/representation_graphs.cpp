#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

int main()
{
    int n,m;
    cin>>n>>m;

    //adjacency matrix representation
    vvi adjm(n+1,vi(m+1,0));
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        //since undirected edges, therefore two way edges
        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    cout<<"adjacency matrix of above graph is given by: "<<endl;
    rep(i,1,n+1){
        rep(j,1,n+1){
            cout<<adjm[i][j]<<" ";
        }
        cout<<endl;
    }
// if we want to check if there is an edge or not in graph
    if(adjm[3][7] == 1){
        cout<<"it is present in the graph"<<endl;
    }
    cout<<endl<<endl;

    // adjacency list representation
    cin>>n>>m;
    vi adj[n];
    rep(i,0,m){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"Adjacency list of above graph is given by: "<<endl;
    rep(i,1,n+1){
        cout<<i<<"-> ";
        for(int x: adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
