// Caio Alvarenga Geraidine - 2173953
// Carolina de Souza Freitas - 2118784
// Vinicius vicari - 2124925

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include "grafo.h"
using namespace std;

int main() {
    std::cout << "\nGrafo 1:" << std::endl;
    Grafo g1;
    g1.ler("Grafos/g1.txt");
    g1.imprimir();

    std::cout << "\nGrafo 2:" << std::endl;
    Grafo g2;
    g2.ler("Grafos/g2.txt");
    g2.imprimir();

    std::cout << "\nGrafo 3:" << std::endl;
    GrafoPonderado g3;
    g3.ler("Grafos/g3.txt");
    g3.imprimir();

    return 0;
}