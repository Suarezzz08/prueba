#include "graph.hpp"

Graph::Graph(int n): n(n), adj(n+1) {}

void Graph::add_edge(int u, int v, long long w) {
    if (u<1 || u>n || v<1 || v>n) return;
    adj[u].push_back({v,w});
}
