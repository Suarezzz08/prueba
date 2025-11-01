#include <bits/stdc++.h>
#include "graph.hpp"
#include "algos.hpp"
using namespace std;

string reconstruct_int_path(const vector<int> &prev, int s, int v) {
    if (v==s) return to_string(s);
    if (prev[v]==-1) return string("-"); 
    vector<int> path;
    int cur=v;
    while(cur!=-1) { path.push_back(cur); if (cur==s) break; cur = prev[cur]; }
    if (path.empty() || path.back()!=s) return string("-"); 
    reverse(path.begin(), path.end());
    string out = to_string(path[0]);
    for(size_t i=1;i<path.size();++i) { out += " -> " + to_string(path[i]); }
    return out;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (argc<4) {
        cerr << "Uso: ./main <input.txt> <output_dist.txt> <tiempos.csv>\n";
        return 1;
    }
    string input = argv[1];
    string output = argv[2];
    string tiempos_csv = argv[3];

    ifstream fin(input);
    if (!fin) { cerr << "No se pudo abrir "<<input<<"\n"; return 1; }

    int n,m,s,tipo;
    fin >> n >> m >> s >> tipo;
    Graph G(n);
    bool has_negative = false;
    for (int i=0;i<m;i++) {
        int u,v; long long w;
        fin >> u >> v >> w;
        G.add_edge(u,v,w);
        if (w<0) has_negative = true;
    }
    ofstream fout(output);
    if (!fout) { cerr << "No se pudo abrir salida: "<<output<<"\n"; return 1; }

    using clk = chrono::high_resolution_clock;
    auto t0 = clk::now();
    if (tipo==0) {
        auto R = bfs_sssp(G, s);
        auto t1 = clk::now();
        long long ms = chrono::duration_cast<chrono::milliseconds>(t1-t0).count();
        for (int v=1; v<=n; ++v) {
            string dist_s = (R.dist[v]==-1? string("INF") : to_string(R.dist[v]));
            string path = (R.dist[v]==-1? string("-") : reconstruct_int_path(R.prev, s, v));
            fout << v << ": distancia = " << dist_s << " ; camino = " << path << "\n";
        }
        ofstream ft(tiempos_csv, ios::app);
        if (ft) ft << n << "," << m << "," << tipo << "," << ms << "\n";
    } else if (tipo==1) {
        if (has_negative) {
            fout << "no soportado (pesos negativos)\n";
            fout << "Dijkstra requiere pesos no negativos porque asume que un camino ya evaluado no mejorará al explorar aristas adicionales.\n";
            auto t1 = clk::now(); long long ms = chrono::duration_cast<chrono::milliseconds>(t1-t0).count();
            ofstream ft(tiempos_csv, ios::app);
            if (ft) ft << n << "," << m << "," << tipo << "," << ms << "\n";
        } else {
            auto R = dijkstra_sssp(G, s);
            auto t1 = clk::now();
            long long ms = chrono::duration_cast<chrono::milliseconds>(t1-t0).count();
            const long long INFLL = numeric_limits<long long>::max();
            for (int v=1; v<=n; ++v) {
                string dist_s = (R.dist[v]==INFLL? string("INF") : to_string(R.dist[v]));
                string path = (R.dist[v]==INFLL? string("-") : reconstruct_int_path(R.prev, s, v));
                fout << v << ": distancia = " << dist_s << " ; camino = " << path << "\n";
            }
            ofstream ft(tiempos_csv, ios::app);
            if (ft) ft << n << "," << m << "," << tipo << "," << ms << "\n";
        }
    } else {
        fout << "tipo no reconocido. Use 0 (BFS) o 1 (Dijkstra)\n";
    }

    return 0;
}
