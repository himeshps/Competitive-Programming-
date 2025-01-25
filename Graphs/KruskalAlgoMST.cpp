
// Kruskal's algo uses the DSU / Union Find data strcuture to solve the minimum spanning tree problem . 

/* The Steps are as follows : 
1. Sort all the edges as per their weights
2.Start the DSU comparisons, if the node does not belong to the component then perform union otherwise leave that node .
3. The reason for 2 is that given we have sorted , we have alreay done the traversal for that.
*/

/* this code snippet assumes that you have already copied the DSU / Union Set Find class from another folder of this repo .
  (GitHub : himeshps)
*/

 int SpanningTree( int n , vector<vector<long long int>>& adjList ){              // n is the number of verticies as always . 

    vector<pair<int, pair<int , int>>> edges;   // wt , node1 , node2
    for( int i = 0; i < n ; ++i){               // 0 - indexed graph.
        for ( auto it : adjList[i]){
            int adjNode = it[0];
            int wt = it[1] ;
            int node = i ;

            edges.push_back ( wt , {node , adjNode}) ;
        }
    }
    DisjointSet ds(n) ;
    sort( all(edges) );   // will work only with my template mind it !
    int mstWt = 0; 
    for( auto it : edges){
        int wt = it.first ; 
        int node1 = it.second.first ;k
        int node2 = it.second.second ;

        if(ds.findUPar(u) != ds.findUPar(v)){         // if their ultimate ancestors match then nice 
            mstWt += wt ;
            ds.UnionBySize( u , v ) ;                // union in the component being made by us ,  the component in this case is the formation of the minimum spanning tree .
        }
    }
    return mstWt ;
 }


 // match the function names from the dsu template before using it .
