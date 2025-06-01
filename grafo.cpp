// Caio Alvarenga Geraidine - 2173953
// Carolina de Souza Freitas - 2118784
// Vinicius vicari - 2124925

#include "grafo.h"
#include <queue>
#include <map>
#include <set>
#include <limits>

bool Grafo::ler(const std::string& nomeArquivo) {
    adj.clear();
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) return false;
    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;
        std::istringstream iss(linha);
        std::string origem, destino;
        std::getline(iss, origem, ';');
        std::getline(iss, destino, ';');
        adj[origem].push_back(destino);
        adj[destino].push_back(origem);
    }
    return true;
}

void Grafo::imprimir() const {
    for (const auto& par : adj) {
        std::cout << par.first << " -> ";
        for (const auto& vizinho : par.second) {
            std::cout << vizinho << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::string> Grafo::bfs(const std::string& start) const {
    std::vector<std::string> res;
    std::unordered_map<std::string, bool> visited;
    std::queue<std::string> q;

    if (adj.find(start) == adj.end()) return res;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        std::string curr = q.front();
        q.pop();
        res.push_back(curr);
        for (const auto& neighbor : adj.at(curr)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return res;
}

void dfsUtil(const std::string& v, const std::unordered_map<std::string, std::vector<std::string>>& adj,
             std::unordered_map<std::string, bool>& visited, std::vector<std::string>& res) {
    visited[v] = true;
    res.push_back(v);
    auto it = adj.find(v);
    if (it != adj.end()) {
        for (const auto& u : it->second) {
            if (!visited[u]) {
                dfsUtil(u, adj, visited, res);
            }
        }
    }
}

std::vector<std::string> Grafo::dfs(const std::string& start) const {
    std::vector<std::string> res;
    std::unordered_map<std::string, bool> visited;
    if (adj.find(start) == adj.end()) return res;
    dfsUtil(start, adj, visited, res);
    return res;
}

bool GrafoPonderado::ler(const std::string& nomeArquivo) {
    adj.clear();
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) return false;
    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;
        std::istringstream iss(linha);
        std::string origem, destino, pesoStr;
        std::getline(iss, origem, ';');
        std::getline(iss, destino, ';');
        std::getline(iss, pesoStr, ';');
        int peso = std::stoi(pesoStr);
        adj[origem].push_back({destino, peso});
        adj[destino].push_back({origem, peso});
    }
    return true;
}

void GrafoPonderado::imprimir() const {
    for (const auto& par : adj) {
        std::cout << par.first << " -> ";
        for (const auto& vizinho : par.second) {
            std::cout << "(" << vizinho.first << ", peso: " << vizinho.second << ") ";
        }
        std::cout << std::endl;
    }
}

void GrafoPonderado::dijkstra(const std::string& origem, const std::string& destino) const {
    std::map<std::string, int> distancia;
    std::map<std::string, std::string> anterior;
    std::set<std::string> visitados;

    const int infinito = std::numeric_limits<int>::max();

    for (const auto& par : adj) {
        distancia[par.first] = infinito;
    }

    distancia[origem] = 0;

    while (visitados.size() < adj.size()) {
        std::string menorVertice;
        int menorDistancia = infinito;

        for (const auto& par : distancia) {
            if (visitados.find(par.first) == visitados.end() && par.second <= menorDistancia) {
                menorDistancia = par.second;
                menorVertice = par.first;
            }
        }

        if (menorVertice.empty()) {
            break;
        }

        visitados.insert(menorVertice);

        for (const auto& vizinho : adj.at(menorVertice)) {
            int novaDistancia = distancia[menorVertice] + vizinho.second;
            if (novaDistancia < distancia[vizinho.first]) {
                distancia[vizinho.first] = novaDistancia;
                anterior[vizinho.first] = menorVertice;
            }
        }
    }

    if (distancia[destino] == infinito) {
        std::cout << "Não existe caminho de " << origem << " até " << destino << std::endl;
    } else {
        std::cout << "Menor distancia de " << origem << " até " << destino << ": " << distancia[destino] << std::endl;
        std::cout << "Caminho: ";

        std::vector<std::string> caminho;
        for (std::string v = destino; v != origem; v = anterior[v]) {
            caminho.push_back(v);
        }
        caminho.push_back(origem);

        for (auto it = caminho.rbegin(); it != caminho.rend(); ++it) {
            std::cout << *it;
            if (it + 1 != caminho.rend()) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    }
}