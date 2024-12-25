
#include<bits\stdc++.h>
using namespace std;

int main(){
    int n,W;
    cin>>n>>W;                                                                         // W is the capacity
    vector<int> weights(n);
    for(int i=0;i<n;++i){
        cin>>weights[i];
    }
    vector<int> value(n);
    for(int i=0;i<n;++i){
        cin>>value[i];
    }
    int dp[n+1][W+1];                                                                   // dp definition
    for(int i=0;i<=n;++i){
        for(int w=0;w<=W;++w){
            if(i==0 || w==0){                                                           // base case
                dp[i][w]=0;
            }
            else if(w-weights[i-1]>=0){
                dp[i][w]= max( dp[i-1][w - weights[i-1]] + value[i-1] , dp[i-1][w]);   // dp transition
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    cout<<dp[n][W];                                                                    // final answer
}
