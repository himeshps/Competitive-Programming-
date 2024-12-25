#include<bits\stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for ( int i=0 ; i<n ; ++i ){
        cin >> arr[i];
    }
    
    int sum;
    cin >> sum;

    bool dp[n+1][sum + 1];
    for(int i = 0 ; i <= n; ++i){
        dp[i][0] = true ;
    }
    for(int j = 1 ; j <= sum; ++j){
        dp[0][j] = false ;
    }

    for( int i = 1 ; i <= n ; ++i ){
        for ( int j = 1 ; j <=sum ; ++j) {
            if ( j<arr[i-1] ){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]] ;
            }
        }
    }

    cout << dp[n][sum] << endl;
}
