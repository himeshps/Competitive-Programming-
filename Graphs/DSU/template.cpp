#include<bits/stdc++.h>
using namespace std;

// The class of disjoint set to be used in the template.

class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){                                  //Constructor Definition.
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;++i){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int node){                             // Ultimate Parent Functionality.
        if(node==parent[node]){
            return node;
        }
        return parent[node]= findUPar(parent[node]); 
    }

    void unionByRank(int u,int v){                       // Union By Rank Functionality.
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_v==ulp_u){ return;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

void unionBySize(int u, int v){                           // Union By Size Functionality.
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_v==ulp_u) return;
        else if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

bool checkSet(int u, int v){                                 // made the inbuilt check for same set check in the class definition itself. 
        if(findUPar(u)==findUPar(v)) return true;

        return false;
    }

};

// the following part would go inside the main function.

DisjointSet ds(Structure_size); // defining the structure along with the size and its name
// ds.unionByRank(node1,node2); for combining node 1 and node 2 into the same set based on rank.
// ds.unionBySize(node1,node2); for combining node 1 and node 2 into the same set based on size.

// to check if 2 nodes belong to the same set 
bool val=ds.checkSet(node1 , node2);
