// Floyd Warshall's Algorithm is used to find the shortest paths between between all pairs of vertices in a graph, 
// where each edge in the graph has a weight which is positive or negative.

// Time Complexity of Floyd Warshall's Algorithm is O(V^3).
// Filling matrix one by one 

// For any  vertices  , one should actually minimize the distances between this pair using the first  nodes, 
// so the shortest path will be: min( dist[i][j], dist[i][k] + dist[k][j] )

for(int k=1 ; k<=n ; k++){
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            dist[i][j] = min( dist[i][j], dist[i][k]+dist[k][j] ) ;         
        }
    }
}