#include "grafo.h"
#include <set>
#include <map>

void dijkstra(const GrafoPonderado& grafo, const std::string& origem, const std::string& destino) {
    std::map<std::string, int> distancia;
    std::map<std::string, std::string> anterior;
    std::set<std::string> visitados;

    const int infinito = std::numeric_limits<int>::max();

    for (const auto& par : grafo) {
        distancia[par.first] = infinito;
    }

    distancia[origem] = 0;

    while (visitados.size() < grafo.size()) {
        std::string menorVertice;
        int menorDistancia = infinito;

        for (const auto& par : distancia) {
            if (visitados.find(par.first) == visitados.end() && par.second <= menorDistancia) {
                menorDistancia = par.second;
                menorVertice = par.first;
            }
        }

        if (menorVertice.empty()) {
            break; // Não há mais vértices alcançáveis
        }

        visitados.insert(menorVertice);

        for (const auto& vizinho : grafo.at(menorVertice)) {
            int novaDistancia = distancia[menorVertice] + vizinho.second;
            if (novaDistancia < distancia[vizinho.first]) {
                distancia[vizinho.first] = novaDistancia;
                anterior[vizinho.first] = menorVertice;
            }
        }
    }

    // Impressão do caminho
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
    GrafoPonderado grafo = lerGrafoComPeso("Grafos/g3.txt");

    std::cout << "Grafo lido:\n";
    imprimirGrafoPonderado(grafo);

    dijkstra(grafo, "x", "t");

    return 0;
}