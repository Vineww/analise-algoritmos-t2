#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <limits>

typedef std::map<std::string, std::vector<std::pair<std::string, int>>> GrafoPonderado;

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
        grafo[destino].push_back({origem, peso}); 
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

void dijkstra(const GrafoPonderado& grafo, const std::string& origem, const std::string& destino) {
    std::map<std::string, int> distancia;
    std::map<std::string, std::string> anterior;
    std::set<std::string> visitados;

    const int infinito = std::numeric_limits<int>::max();

    for (const auto& par : grafo) {
        distancia[par.first] = infinito;
        for (const auto& vizinho : par.second) {
            if (distancia.find(vizinho.first) == distancia.end())
                distancia[vizinho.first] = infinito;
        }
    }

    distancia[origem] = 0;

    while (visitados.size() < distancia.size()) {
        std::string menorVertice;
        int menorDistancia = infinito;

        for (const auto& par : distancia) {
            if (visitados.find(par.first) == visitados.end() && par.second < menorDistancia) {
                menorDistancia = par.second;
                menorVertice = par.first;
            }
        }

        if (menorVertice.empty()) {
            break;
        }

        visitados.insert(menorVertice);

        if (grafo.find(menorVertice) != grafo.end()) {
            for (const auto& vizinho : grafo.at(menorVertice)) {
                int novaDistancia = distancia[menorVertice] + vizinho.second;
                if (novaDistancia < distancia[vizinho.first]) {
                    distancia[vizinho.first] = novaDistancia;
                    anterior[vizinho.first] = menorVertice;
                }
            }
        }
    }

    if (distancia[destino] == infinito) {
        std::cout << "Não existe caminho de " << origem << " até " << destino << std::endl;
    } else {
        std::cout << "Menor distancia de " << origem << " até " << destino << ": " << distancia[destino] << std::endl;
        std::cout << "Caminho: ";

        std::vector<std::string> caminho;
        for (std::string v = destino; v != origem && anterior.find(v) != anterior.end(); v = anterior[v]) {
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

int main() {
    GrafoPonderado grafo = lerGrafoComPeso("Grafos/g3.txt");

    std::cout << "Grafo lido:\n";
    imprimirGrafoPonderado(grafo);

    dijkstra(grafo, "x", "t");

    return 0;
}