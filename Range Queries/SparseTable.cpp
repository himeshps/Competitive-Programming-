#include<bits/stdc++.h>
using namespace std;

const int MAX_N=1e5;
const int LOG=17;
int a[MAX_N];      // the input array
int m[MAX_N][LOG]; // the data structure implemented for the sparse table

int query(int l,int r){
	int length=r-l+1;
	int k=31-__builtin_clz(length); // using bitwise operation to make finding the log an O(1) operation for each query
	return min(m[l][k],m[r-(1<<k)+1][k]); // Remember that RMQ allows for an overlap
}

int main(){

  //PRE-PROCESSING AT THIS STAGE
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
    	cin>>a[i];
    	m[i][0]=a[i];
    }

    for(int k=1;k<LOG;++k){
    	for(int i=0;i+(1<<k)-1<n;++i){
    		m[i][k]=min(m[i][k-1],m[i+(1<<(k-1))][k-1]);   // The recursive formula at the heart of a sparse table.
    	}
    }

  //DEALING WITH THE QUERIES NOW
  
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
    	int l,r;
    	cin>>l>>r;
    	cout<<query(l,r)<<"\n"; // Query function is kinda cool, innit?
    }
}
