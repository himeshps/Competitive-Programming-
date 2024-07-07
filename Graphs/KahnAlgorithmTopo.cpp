# This algorithm relies on calculating the In-Degree of the nodes as in how many incoming nodes are there for that specific one.
# Has a queue as we usually do keep for a BFS traversal. 

# SHORTER THAN DFS TOPOSORT LMAO !!

#include<bits/stdc++.h>
using namespace std;

vector<int> kahn(vector<vector<int>> &adjList, int vertices,vector<int> &InDex){
	queue<int> q;
	for(int i=0;i<vertices;++i){if(InDex[i]==0){q.push(i);}}
    vector<int> ans;
    while(!q.empty()){
    	int node=q.front();
    	q.pop();
    	ans.push_back(node);  // Keep pushing nodes with InDex=0 into the queue. 
    	for(auto it : adjList[node]){
    		InDex[it]--;
    		if(InDex[it]==0){
    			q.push(it);
    		}
    	}
    }
    return ans;
}

int main(){
	int vertices,edges;
	cin>>vertices>>edges;
	vector<vector<int>> adjList(vertices);
	vector<bool> visited(vertices,false);
	vector<int> InDex(vertices,0);
	for(int i=0;i<edges;++i){
		int x,y;
		cin>>x>>y;
		adjList[x-1].push_back(y-1);
		InDex[y-1]++;
	}

	// This code assumes the 1-indexing of the input. Stick to that.
    
    vector<int> ans;
    ans=kahn(adjList,vertices,InDex); 
    for(int i=0;i<ans.size();++i){cout<<ans[i]+1<<" ";}cout<<endl;
	
   /* if(ans.size()!=vertices){cout<<"cycle detected"<<endl;}
    else {cout<<"no cycle"<<endl;}   This piece of code can be altered in the form of a counter variable in the BFS and may be used in the 
	cycle detection use-case*/
	
}
