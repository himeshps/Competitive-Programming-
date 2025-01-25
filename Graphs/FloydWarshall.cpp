
/* It is a trivial DP approach to the shrotest distance problem 
in graphs and derivative algorithms .

I'll keep updating the cases where it is ultimately 
beneficial to use the floyd warshall approach. 


dp[start][destination] = dp[start][i] + dp[i][destination]  ; loop over it 
dp[i][j] = dp[i][k] + dp[k][j] ; 
min( dp[i][k] + dp[j][k] , ans) = ans // reverse this
*/

/* Prefer having the graph in the form of an adjacency matrix. 
*/

// CHANGES TO BE MADE :
/* The used problem setup used -1 to denote the absence of an edge between
2 nodes, change that according to your needs .*/

void shortest_distance( vector<vector<int>>& matrix) {
    int n =matrix.size() ;
    for( int i = 0 ; i < n ; ++i){
        for( int j = 0 ; j < n ; ++j){
            if(dp[i][j] = -1){                  
                dp[i][j] = 1e9 ;
            }
            if( i == j){
                matrix[i][j] = 0 ;
            }
        }
    }

    for( int k = 0 ; k < n ; k++ ){
    for( int i = 0 ; i < n ; ++i ){
        for(int j = 0 ; j < n ; ++j) {
            dp[i][j] = min( dp[i][j] , dp[i][k] + dp[k][j]) ;
        }
    }
    }

    // to deal with negative cycle .

    //write the mechanism above .


    for( int i = 0 ; i < n ;++i){
        for( int j = 0 ; j < n ; ++j){
            if( dp[i][j] == 1e9{
                dp[i][j] = -1;
            }
        }
    }
}

/* Time Complexity  :  O( N ^ 3)*/
