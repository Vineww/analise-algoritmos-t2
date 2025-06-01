// Caio Alvarenga Geraidine - 2173953
// Carolina de Souza Freitas - 2118784
// Vinicius vicari - 2124925

#include "grafo.h"
#include <set>
#include <map>
#include <limits> 

void dijkstra(const GrafoPonderado& grafo, const std::string& origem, const std::string& destino) {
    std::map<std::string, int> distancia;
    std::map<std::string, std::string> anterior;
    std::set<std::string> visitados;

    const int infinito = std::numeric_limits<int>::max();

    for (const auto& par : grafo.adj) {
        distancia[par.first] = infinito;
    }

    distancia[origem] = 0;

    while (visitados.size() < grafo.adj.size()) {
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

        for (const auto& vizinho : grafo.adj.at(menorVertice)) {
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

int main() {
    GrafoPonderado grafo;
    grafo.ler("Grafos/g3.txt");

    std::cout << "Grafo lido:\n";
    grafo.imprimir();

    dijkstra(grafo, "x", "t");

    return 0;
}