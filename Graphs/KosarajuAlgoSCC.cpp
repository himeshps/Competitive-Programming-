
// Implementation of the Kosaraju's Algorithm :
// This is for Strongly Connected Components . 

/* 1. Sort all edges acc to finishing time . The finishing time based on an initial DFS traversal
2. Reverse the graph.
3. DFS !!!
*/

void dfs(int node , vector<int>& vis , vector<vector<int>>& adj , stack<int>& st){   // the dfs traversal to find the order of finishing . 

    vis[node] = 1 ;
    for( auto it : adj[node]){
        if(!vis[it]){
            dfs(it , vis , adj , st) ;
        }
    }
    st.push(node) ;
}

void dfs3(int node , vector<int>& vis , vector<vector<int>>& adj){          // Normal dfs traversal without the stack usage .
    vis[node] = 1 ;
    for( auto it : adj[node]){
        if(!vis[it]){
            dfs3(it , vis , adj) ;
        }
    }
}

int kosaraju( int V , vector<int>& adj) {
    vector<int> vis(V,0);
    stack<int> st;

    for(int i = 0 ; i < V ; ++i ){
        if(!vis[i]){
            dfs(i , vis , adj ,st);
        }
    }

    vector<int> adjT[V] ;
    for( int i = 0 ; i < V ; ++i ){
        vis[i] = 0 ;                   // reusing the same visited vector to mark the nodes visited .
        for( auto it : adj[i] ){
            adjT[it].push_back(i) ;    // reversing the edges . 
        }
    }

    int scc = 0;                       // a counter to find the number of strongly connected components .
     
    while(!st.empty()){
        int node = st.top(); 
        st.pop() ;
        if(!vis[node]){
            scc++ ;                     // dfs traversal would happen only once per SCC .
            dfs3(node , vis , adj) ;
        }
    }
}
