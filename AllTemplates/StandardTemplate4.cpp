#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

#define endl '\n'
#define ll long long
#define lb lower_bound
#define ub upper_bound
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define inp(a,n) vector <int> a(n); for(int i=0;i<n;i++) cin >> a[i];
#define give(a,n) rep(i,n)cout<<a[i]<<" "

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef map< long long , long long > mll;
typedef vector< vector< long long >> vvl;

vector<pair<int , int>> moves = { { 1 , 0 } , { -1 , 0 } , { 0 , -1 } , { 0 , 1 } } ;   

const long long mod=1e9 + 7;

void yesno(bool flag) {
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

string base_rep(ll n, ll b){  
    if(n==0) return "0";
    string res="";
    while(n>0){
        res+=char('0'+n%b);
        n=n/b;
    }
    reverse(all(res));
    return res;
}
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
int gcdExtended(int a, int b, int *x, int *y) { 
    if (a == 0){ 
        *x = 0; 
        *y = 1; 
        return b;} 
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
} 

bool isValid( ll i , ll j){
  if( i >= 0 && j >= 0 && i < n && j < m ) return true ;
  return false;
}

void solve(){
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin>>test;
    for(int i=0;i<test;i++){
    solve();
    }
}
