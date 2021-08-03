// Unlike an edge in Kruskal's, we add vertex to the growing spanning tree in Prim's

#include<bits/stdc++.h>

using namespace std;

const int N=1e5 ;
int dist[N], parent[N];
bool vis[N];
vector<pair<int, int>> g[N], tree[N];

int primMST(int source)
{
    for(int i=0 ; i<N ; i++)
        dist[i]=1e9 ;
    set<pair<int,int>> s ;
    s.insert({0,source}) ;
    int mincost=0 ;
    dist[source]=0 ;
    parent[source]=-1 ;
    while(!s.empty()){
        auto x = *s.begin() ;
        s.erase(x) ;
        if (vis[x]) continue ;
        vis[x.second]=1 ;
        mincost+=(x.first) ;
        for(auto it : g[x.second]){
            if (vis[it.first])
                continue ;
            if (dist[it.first]>it.second)
            {
                s.erase({dist[it.first],it.first}) ;
                dist[it.first]=it.second ;
                parent[it.first]=x.second ;
                s.insert({dist[it.first],it.first}) ;
            }
        }
    }
    return mincost ;
}

int main(){
    int n,m ;  // nodes & edges
    cin>>n>>m ;
    for(int i=0 ; i<m ; i++){
        int u,v,w ;
        cin>>u>>v>>w ;
        g[u].push_back({v,w}) ;
        g[v].push_back({u,w}) ;
    }
    
    int minimumCost = primMST(1);   // Selecting 1 as the starting node (source)
    cout << minimumCost << endl;

    for(int i=1 ; i<=n ; i++)
        cout<<parent[i]<<" \n"[i==n] ;

    return 0;
}

// 5 7
// 1 2 1
// 1 3 7
// 2 3 5
// 2 4 4
// 3 5 6
// 4 5 2
// 2 5 3
// ANS : 11