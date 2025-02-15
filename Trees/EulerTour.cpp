/*
  Euler tour is a way of traversing all the nodes of the tree such that each node is reached twice. 
*/


const int N = 1e5 + 5; // Maximum number of nodes
vector<int> tree[N];   // adjList rep. for the given tree. 
int entry[N], exitT[N], timer = 0; // Entry and exit time arrays, and a global timer

void eulerTour(int node, int parent) {
    entry[node] = ++timer;                                // assigns the entry time at this point
    for (int child : tree[node]) {
        if (child != parent) { // Avoid revisiting the parent
            eulerTour(child, node);                          // this part of the code taught me that function calls the whole function and not just a part of it lol !!
        }
    }
    exitT[node] = ++timer; // assign exit time so we are technically done each time. 
}

// I dont know but I have a lowkey intuition that having a pair of entry exit time for each node would be great but who cares for now !
