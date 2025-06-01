// Caio Alvarenga Geraidine - 2173953
// Carolina de Souza Freitas - 2118784
// Vinicius vicari - 2124925

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include "grafo.h"
using namespace std;

vector<string> bfs(const vector<vector<int>>& adj, int start, const vector<string>& idxToName) {
    int V = adj.size();
    vector<string> res;
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(idxToName[curr]);
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return res;
}

void readGraphAndBFS(const string& filename) {
    ifstream file(filename);
    string line;
    set<string> vertices;
    vector<pair<string, string>> edges;

    // Descobrir todos os vértices e arestas
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string from, to, dummy;
        getline(ss, from, ';');
        getline(ss, to, ';');
        edges.push_back({from, to});
        vertices.insert(from);
        vertices.insert(to);
    }

    // Mapear nomes para índices
    map<string, int> nameToIdx;
    vector<string> idxToName;
    int idx = 0;
    for (const auto& v : vertices) {
        nameToIdx[v] = idx++;
        idxToName.push_back(v);
    }

    // Construir lista de adjacência
    vector<vector<int>> adj(vertices.size());
    for (const auto& e : edges) {
        int u = nameToIdx[e.first];
        int v = nameToIdx[e.second];
        adj[u].push_back(v);
        adj[v].push_back(u); // Grafo não direcionado
    }

    cout << "\nArquivo: " << filename << endl;
    cout << "\nOrdem de visitação (BFS a partir de 'b'):" << endl;
    if (nameToIdx.count("b") == 0) {
        cout << "Vértice 'b' inexistente." << endl;
        return;
    }
    int start = nameToIdx["b"];
    vector<string> bfsOrder = bfs(adj, start, idxToName);
    for (const auto& name : bfsOrder) {
        cout << name << " ";
    }
    cout << endl << endl;
}

int main() {
    Grafo g;
    g.ler("Grafos/g1.txt");
    std::vector<std::string> ordem = g.bfs("b");
    std::cout << "\nOrdem de visitação (BFS a partir de 'b'):" << std::endl;
    for (const auto& v : ordem) std::cout << v << " ";
    std::cout << std::endl;
    return 0;
}