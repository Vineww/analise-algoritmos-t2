// Caio Alvarenga Geraidine - 2173953
// Carolina de Souza Freitas - 2118784
// Vinicius vicari - 2124925

#include "grafo.h"
#include <set>
#include <map>
#include <limits> 

int main() {
    GrafoPonderado grafo;
    grafo.ler("Grafos/g3.txt");

    std::cout << "Grafo lido:\n";
    grafo.imprimir();

    grafo.dijkstra("x", "t");

    return 0;
}