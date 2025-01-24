
// Trajan's algorithm for Bridge detection in a graph.


int timer = 1 ;
void dfs ( int node , int parent , vector<int>& vis , vector<vector<int>>& adj , vector<int>& tin , vector<int>& low , vector<vector<int>>& bridges ){
    vis[node] = 1; 
    tin[node] = low[node] = timer ; 
    timer++ ; 
    
    for ( auto it : adj[node] ){
        if( it==parent ){ continue; }
        if( vis[it] == 0){
            dfs( it, node , vis , adj , tin , low , bridges);
            low[node] = min(low[node] , low[it] );
            // check for a bridge at this point . 
            // the point is node -- it 
            if( low[it] > tin[node] ){
                bridges.push_back({it , node}); 
            }
        }
        else{
            low[node] = min( low[node] , low[it] ) ;
        }
    }
}

// Space Complexity : O ( V + 2E + 3N)
// Time Complexity : O ( V + 2E)
