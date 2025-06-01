// Caio Alvarenga Geraidine - 2173953
// Carolina de Souza Freitas - 2118784
// Vinicius vicari - 2124925

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

class Grafo {
public:
    std::unordered_map<std::string, std::vector<std::string>> adj;
    bool ler(const std::string& nomeArquivo);
    void imprimir() const;
    std::vector<std::string> bfs(const std::string& start) const;
    std::vector<std::string> dfs(const std::string &start) const;
};

class GrafoPonderado {
public:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adj;
    bool ler(const std::string& nomeArquivo);
    void imprimir() const;
    void dijkstra(const std::string& origem, const std::string& destino) const; 
};