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
#define inp(a,n) vector <int> a(n); for(int i=0;i<n;i++) cin >> a[i];
#define ff first
#define ss second

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;

const long long int mod=1e9 + 7;

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
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
