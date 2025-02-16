
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

#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

#define endl '\n'
#define ll long long
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(i=a;i<=b;i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define inp(a,n) vector <long long> a(n); for(int i=0;i<n;i++) cin >> a[i];
#define int long long 
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef map<long long , long long> mll;

const long long mod=1e9 + 7;
const long long INF = 1e18;

vector<vector<ll>> dp;

void shortest_distance(int n) {
    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k] < INF && dp[k][j] < INF) // Check to avoid integer overflow
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    // Handling negative cycles (if necessary)
    for (int i = 0; i < n; i++) {
        if (dp[i][i] < 0) {  // Negative cycle detected
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dp[j][i] < INF && dp[i][k] < INF)
                        dp[j][k] = -INF; // Mark as negative cycle
                }
            }
        }
    }

    // Convert unreachable distances back to -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == INF) {
                dp[i][j] = -1;
            }
        }
    }
}

void solve() {
    ll n, m, q;
    cin >> n >> m >> q;

    dp.assign(n, vector<ll>(n, INF));

    for (int i = 0; i < n; i++) dp[i][i] = 0;
    for (int i = 0; i < m; i++) {
        ll x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        dp[x][y] = min(dp[x][y], w);
        dp[y][x] = min(dp[y][x], w); 
    }

    shortest_distance(n);

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--; 
        cout << dp[x][y] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}


/* Time Complexity  :  O( N ^ 3)*/
