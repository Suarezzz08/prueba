#include "graph.hpp"
#include "algos.hpp"
#include <vector>
#include <queue>
#include <limits>

BFSResult bfs_sssp(const Graph &G, int s) {
    int n = G.n;
    BFSResult R;
    R.dist.assign(n+1, -1);
    R.prev.assign(n+1, -1);
    std::queue<int> q;
    R.dist[s]=0;
    q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &e: G.adj[u]) {
            int v = e.to;
            if (R.dist[v]==-1) {
                R.dist[v]=R.dist[u]+1;
                R.prev[v]=u;
                q.push(v);
            }
        }
    }
    return R;
}
