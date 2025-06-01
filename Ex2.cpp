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

int main() {
    Grafo g;
    g.ler("Grafos/g1.txt");
    std::vector<std::string> ordem = g.bfs("b");
    std::cout << "\nOrdem de visitação (BFS a partir de 'b'):" << std::endl;
    for (const auto& v : ordem) std::cout << v << " ";
    std::cout << std::endl;
    return 0;
}