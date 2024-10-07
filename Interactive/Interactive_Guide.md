# Thumb Rule for Interactive Submissions : 

Explained using the code below

```cpp
#include<bits\stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

#define ll long long
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(i=a;i<=b;i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define inp(a,n) vector <int> a(n); for(int i=0;i<n;i++) cin >> a[i];

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;

const long long int mod=1e9 + 7;

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

bool ask(string t) {
    cout << "? " << t << endl;
    int res;
    cin >> res;
    return res;
}
 
void result(string s) {
    cout << "! " << s << endl;
}

void solve(){
    int n;
    cin >> n;
    string cur="";
    while (cur.size() < n) {
        if (ask(cur + "0")) {
            cur += "0";
        } else if (ask(cur + "1")) {
            cur += "1";
        } else {
            break;
        }
    }
    while ((int) cur.size() < n) {
        if (ask("0" + cur)) {
            cur = "0" + cur;
        } else{
            cur = "1" + cur;
        }
    }
    result(cur);
}

int main(){
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
    solve();
    }
}
```
This is my submission to the problem statement 2013-C on CF. 
## Things to take care of :
1. Omit the usage of tie function for cin and do not perform the synchronisation which is the part of your template else you would fall into the trap of idleness limit which is a must to avoid in any case.
2. Instead of using the flush(); command for C++ as suggested by the platform, abide by using the endl instruction as it works just as fine.

## The Structure :
### bool ask()
Takes care of your side of the interaction with the online judge. 
### void result()
Prints the result on the output terminal, better to have a seperate function for this.
### void solve()
Implement your logic (usually of the level of (problem rating) - 200 ) in this function by calling the ask function as needed (implementation part).

#### Refer to the code submission above, whenever in doubt.

##### Faster than Fast, Quicker than Quick, I am lightning.
