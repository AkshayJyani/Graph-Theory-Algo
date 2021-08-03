// Distance stores levels, and ways stores the number of ways to get from kth vertex to any other vertex with the shortest path taken

int vis[N],dist[N],ways[N] ;
vector<int> g[N] ;        // stores all edges (adjency list)

void BFS(int k){
    queue<int> q ;
    q.push(k) ;
    ways[k]=1 ;
    vis[k]=1 ;
    while(!q.empty){
        int node=q.front() ;
        q.pop() ;
        for(auto i : g[node]){
            if (!vis[i]){
                dist[i]=dist[node]+1 ;
                vis[i]=1 ;
                ways[i]+=ways[node] ;
                q.push(i) ;
            }
            else{
                if (dist[node]+1==dist[i])
                    ways[i]+=ways[node] ;
            }
        }
    }
}