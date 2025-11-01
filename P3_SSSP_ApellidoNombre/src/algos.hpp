#ifndef ALGOS_HPP
#define ALGOS_HPP
#include <vector>
#include <limits>

struct BFSResult {
    std::vector<int> dist; // -1 -> INF
    std::vector<int> prev;
};

BFSResult bfs_sssp(const class Graph &G, int s);

struct DijkstraResult {
    std::vector<long long> dist; // LLONG_MAX -> INF
    std::vector<int> prev;
};

DijkstraResult dijkstra_sssp(const class Graph &G, int s);

#endif // ALGOS_HPP
