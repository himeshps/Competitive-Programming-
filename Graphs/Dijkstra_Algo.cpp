
/* Crazy OP highly used memed - about algorithm
Time Complexity : O( E log V)
use of data structures  : Priority Queue ( mostly faster ) or a set . 

*/

vector<int> dijkstra( int n , vector<vector<int>>& adjList , int source) {
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n , 1e9);

    dist[source] = 0 ;
    pq.push({ 0 ,source }) ;

    while( !pq.empty() ){
        int dis = pq.top().first ;
        int node = pq.top().second ;
        pq.pop(); 

        for( auto it : adj[node]) {
            int edgeW = it[i] ;
            int adjN = it[0] ;

            if( dis + edgeW < dist[adjNode]){
                dist[adjNode] = dis + edgeW;
                pq.push( {dist[adjN] , adjN} ) ;
            }
        }
    }
    return dist ;
}
