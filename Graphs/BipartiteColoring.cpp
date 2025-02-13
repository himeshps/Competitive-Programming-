bool isBipartite(int V) {     // V is the size of the adj or in simpler words , V IS THE NUMBER OF TOTAL VERTICES !!!!!!!!!
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(color[i] == -1) {
            color[i] = 1;
            q.push(i);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(auto &v : adj[u]) {
                    if(color[v] == -1) {
                        color[v] = 3 - color[u];
                        q.push(v);
                    }
                    else if(color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
