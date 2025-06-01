#include "grafo.h"

Grafo lerGrafoSemPeso(const std::string& nomeArquivo) {
    Grafo grafo;
    std::ifstream arquivo(nomeArquivo);
    std::string linha;

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return grafo;
    }

    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;
        std::istringstream iss(linha);
        std::string origem, destino;

        std::getline(iss, origem, ';');
        std::getline(iss, destino, ';');

        grafo[origem].push_back(destino);
        grafo[destino].push_back(origem); // Grafo não direcionado
    }

    arquivo.close();
    return grafo;
}

void imprimirGrafo(const Grafo& grafo) {
    for (const auto& par : grafo) {
        std::cout << par.first << " -> ";
        for (const auto& vizinho : par.second) {
            std::cout << vizinho << " ";
        }
        std::cout << std::endl;
    }
}

GrafoPonderado lerGrafoComPeso(const std::string& nomeArquivo) {
    GrafoPonderado grafo;
    std::ifstream arquivo(nomeArquivo);
    std::string linha;

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return grafo;
    }

    while (std::getline(arquivo, linha)) {
        if (linha.empty()) continue;
        std::istringstream iss(linha);
        std::string origem, destino, pesoStr;
        int peso;

        std::getline(iss, origem, ';');
        std::getline(iss, destino, ';');
        std::getline(iss, pesoStr, ';');

        peso = std::stoi(pesoStr);

        grafo[origem].push_back({destino, peso});
        grafo[destino].push_back({origem, peso}); // Grafo não direcionado
    }

    arquivo.close();
    return grafo;
}

void imprimirGrafoPonderado(const GrafoPonderado& grafo) {
    for (const auto& par : grafo) {
        std::cout << par.first << " -> ";
        for (const auto& vizinho : par.second) {
            std::cout << "(" << vizinho.first << ", peso: " << vizinho.second << ") ";
        }
        std::cout << std::endl;
    }
}