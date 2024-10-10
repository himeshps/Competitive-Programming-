bool detect(vector<vector<int>>& adjList, vector<bool> visited, int src){
	visited[src]=true;
	queue<pair<int,int>> q;
	q.push({src,-1});

	while(!q.empty()){
		int currentNode=q.front().first;
		int parent=q.front().second;
		q.pop();
		for(auto adjNode : adjList[currentNode]){
			if(!visited[adjNode]){
				q.push({adjNode,currentNode});
				visited[adjNode]=true;
			}
			else{
				if(adjNode!=parent){
					return true;
				}
			}
		}
	}
	return false;
} //src corresponds to the source 
