#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <utility>
#include <cstdint>

struct Edge {
    int to;
    long long w;
};

class Graph {
public:
    int n;
    std::vector<std::vector<Edge>> adj; // 1-based
    Graph(int n=0);
    void add_edge(int u, int v, long long w);
};

#endif // GRAPH_HPP
