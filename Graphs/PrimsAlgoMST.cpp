
#include<bits/stdc++.h>
using namespace std; 

int spanningTree(int v , vector<vector<int>>& adj){
    int sum = 0; 
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq; 
    vector<int> vis(v , 0 ); 
    pq.push({0 , 0}); 
    while(!pq.empty()){                        // this segment is the main check of adding to the MST. 
        int node = pq.top().second;
        int wt  = pq.top().first; 
        pq.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        sum += wt;                            // added to the MST only at this point. 
        
        // this following part only pushes new elements into the priority queue. 
        for( auto it : adj[node]){
            int edw = it[1] ; 
            int adjNode = it[0]; 
            if(!vis[adjNode]){
                pq.push({edw , adjNode});
            }
        }
        // segment ends here ;) .
    }
    return sum; 
}
