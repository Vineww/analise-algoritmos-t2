// Caio Alvarenga Geraidine - 2173953
// Carolina de Souza Freitas - 2118784
// Vinicius vicari - 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include "grafo.h"
using namespace std;

//exercicio 1
void readCreateList(const string& filename) {
    map<string, vector<pair<string, string>>> adjListWeighted;
    map<string, vector<string>> adjListUnweighted;
    bool hasWeight = false;

    ifstream file(filename);
    string line;

    // Primeira leitura para detectar se há peso
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string from, to, weight;
        getline(ss, from, ';');
        getline(ss, to, ';');
        if (getline(ss, weight, ';')) {
            hasWeight = true;
            break;
        }
    }
    file.clear();
    file.seekg(0);

    if (hasWeight) {
        while (getline(file, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string from, to, weight;
            getline(ss, from, ';');
            getline(ss, to, ';');
            getline(ss, weight, ';');
            adjListWeighted[from].push_back(make_pair(to, weight));
            adjListWeighted[to];
        }

        for (map<string, vector<pair<string, string>>>::const_iterator i = adjListWeighted.begin(); i != adjListWeighted.end(); ++i) {
            cout << i->first << ": ";
            for (vector<pair<string, string>>::const_iterator j = i->second.begin(); j != i->second.end(); ++j) {
                cout << j->first << "(" << j->second << ") ";
            }
            cout << endl;
        }
    } else {
        while (getline(file, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string from, to;
            getline(ss, from, ';');
            getline(ss, to, ';');
            adjListUnweighted[from].push_back(to);
            adjListUnweighted[to];
        }
        for (map<string, vector<string>>::const_iterator i = adjListUnweighted.begin(); i != adjListUnweighted.end(); ++i) {
            cout << i->first << ": ";
            for (vector<string>::const_iterator j = i->second.begin(); j != i->second.end(); ++j) {
                cout << *j << " ";
            }
            cout << endl;
        }
    }
}

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