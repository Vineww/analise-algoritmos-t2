// Caio Alvarenga Geraidine - 2173953
// Carolina de Souza Freitas - 2118784
// Vinicius vicari - 2124925

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include "grafo.h"
using namespace std;

// Função principal do programa
int main()
{
    Grafo g;
    g.ler("Grafos/g2.txt");
    std::vector<std::string> ordem = g.dfs("a");
    std::cout << "\nOrdem de visitação (DFS a partir de 'a'):" << std::endl;
    for (size_t i = 0; i < ordem.size(); ++i) {
        std::cout << ordem[i];
        if (i != ordem.size() - 1) std::cout << ",";
    }
    std::cout << std::endl;
    return 0;
}