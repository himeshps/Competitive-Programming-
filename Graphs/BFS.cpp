#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adjList, vector<bool>& visited, int node){
	visited[node]=true;
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		int currentNode=q.front();
		cout<<currentNode<<" ";   //Directly printing the traversal order can be substituted by storing it in a data structure for a better use case.
		q.pop();
		for(auto neighbor : adjList[currentNode]){
			if(!visited[neighbor]){
				visited[neighbor]=true;
				q.push(neighbor);     //BFS goes level wise instead of the recursive calls of DFS.
			}
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
    
    
    	bfs(adjList,visited,1); // Calling the BFS function with a starting node that you can tune later.
        
        // Understand that BFS derivative applications are more significant than normal traversals.
}
