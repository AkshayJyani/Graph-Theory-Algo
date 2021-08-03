// 0 -> Vertex is not processed yet
// 1 -> Vertex is being processed (or vertex is in the function call stack).
// 2 -> Vertex and all its descendants are processed.

bool findloop(int v){
    if (vis[v]==1) 
        return 1 ;
    if (vis[v]==2) 
        return 0 ;
    vis[v]=1 ;
    for(auto &it : g[v]){
        if (findloop(it))
            return 1 ;
    }
    vis[v]=2 ;
    return 0 ;
}

bool checkloop()
{
    fill(vis,vis+n,0) ;
    for(int i=0 ; i<n ; i++){
        if (!vis[i] && findloop(i))
            return 1 ;
    }
}