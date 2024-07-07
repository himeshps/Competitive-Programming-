#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &vis, stack<int> &st, vector<vector<int>> &adjList){
	vis[node]=true;
	for(int neighbor : adjList[node]){
		if(!vis[neighbor]){
			dfs(neighbor,vis,st,adjList);
		}
	}
	st.push(node);//pushing into the stack once the DFS calls are over.
}

vector<int> topsort(vector<vector<int>> &adjList, vector<bool> &vis, int vertices){
	stack<int> s;
	for(int i=0;i<vertices;++i){
		if(!vis[i]){
			dfs(i,vis,s,adjList);   //call DFS for every unvisited node and push it into the stack as soon as it DFS calls are over.
		}
	}
	vector<int> ans;
	while(!s.empty()){
		ans.push_back(s.top());
		s.pop();
	}
	return ans;// returns the topsort arranged vector of integers.
}

int main(){
	int vertices,edges;
	cin>>vertices>>edges;
	vector<vector<int>> adjList(vertices);
	vector<bool> visited(vertices,false);
	for(int i=0;i<edges;++i){
		int x,y;
		cin>>x>>y;
		adjList[x-1].push_back(y-1);
	}

	// This code assumes the 1-indexing of the input. Stick to that.
    
    vector<int> ans;
    ans=topsort(adjList,visited,vertices);
    for(int i=0;i<ans.size();++i){cout<<ans[i]+1<<" ";}
}
