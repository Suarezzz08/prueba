#include "graph.hpp"
#include "algos.hpp"
#include <vector>
#include <queue>
#include <limits>
#include <functional>

DijkstraResult dijkstra_sssp(const Graph &G, int s) {
    int n = G.n;
    const long long INF = std::numeric_limits<long long>::max();
    DijkstraResult R;
    R.dist.assign(n+1, INF);
    R.prev.assign(n+1, -1);
    using pli = std::pair<long long,int>;
    std::priority_queue<pli, std::vector<pli>, std::greater<pli>> pq;
    R.dist[s]=0;
    pq.push({0,s});
    while(!pq.empty()) {
        auto [d,u]=pq.top(); pq.pop();
        if (d>R.dist[u]) continue;
        for (auto &e: G.adj[u]) {
            int v=e.to; long long w=e.w;
            if (R.dist[v] > R.dist[u] + w) {
                R.dist[v] = R.dist[u] + w;
                R.prev[v] = u;
                pq.push({R.dist[v], v});
            }
        }
    }
    return R;
}
