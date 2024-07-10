#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int node){
	visited[node]=true;
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		int currentNode=q.front();
		cout<<currentNode<<" ";
		q.pop();
		for(auto neighbour : adjList[currentNode]){   //Loop to alter for all DFS-styled checks and programs
			if(!visited[neighbour]){
			dfs(adjList,visited,neighbour);}   // It is quite powerful to be inside of this block.
		}
	}
}

int main(){
	int vertices,edges;
	cin>>vertices>>edges;
	vector<vector<int>> adjList(vertices+1);
	vector<bool> visited(vertices+1,false);

	for(int i=0;i<vertices;++i){
		int x,y;
		cin>>x>>y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}
    
    
    	dfs(adjList,visited,1); // Calling the DFS function with a starting node that you can tune later.
        
        // Understand that DFS derivative applications are more significant than normal traversals.
}
