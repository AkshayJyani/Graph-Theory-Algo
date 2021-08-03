// Topological sorting of vertices of a Directed Acyclic Graph (DAG) is an ordering of the vertices  in such a way, 
// that if there is an edge directed towards vertex Vj from vertex Vi, then Vi comes before Vj .
// There are multiple topological sorting possible for a graph.
// order : start with element containing zero indegree , ends with zero outdegree .

// STEPS :
// 1 -> Find Indegree of all vertices.
// 2 -> Push all nodes with Indegree = 0  into a queue.
// 3 -> Process the queue from front & pop element(Element push into output) & reduce Indegree & repeat step 2.

const int MAX=1e5 ;
vector<int> order; //Stores the Topological Order
vector<int> g[MAX] ;

bool toposort(int n) //Returns 1 if there exists a toposort, 0 if there is a cycle
{
    queue<int> q;
	vector<int> indeg(n + 1, 0);
	for(int i = 1; i <= n; i++)
		for(auto &it:g[i])
			indeg[it]++;

    for(int i = 1; i <= n; i++)
	{
		if(!indeg[i])
			q.push(i);
	}
    while(!q.empty())
	{
		int u = q.front();
		q.pop();
		order.push_back(u);
		for(auto &v:g[u])
		{
			indeg[v]--;
			if(!indeg[v])
				q.push(v);
		}
	}
    return (order.size() == n) ;
}