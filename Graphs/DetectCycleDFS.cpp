bool detectByDFS(int node, int parent, vector<vector<int>>& adjList, vector<bool>& visited){
	visited[node]=true;
	for(auto adjNode : adjList[node]){
		if(!visited[adjNode]){
			if(dfs(adjNode, node, adjList, visited)){
				return true;
			}
			else if(adjNode!=parent){
				return true;
			}
		}
	}
	return false;
}

//use for loop to iterate over all vertices for a complete detection across all connected components of the give graph.
