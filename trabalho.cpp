#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

//exercicio 1
void readCreateList(const string& filename) {
    map<string, vector<string>> adjList;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string from, to;
        getline(ss, from, ';');
        getline(ss, to, ';');
        adjList[from].push_back(to);
        adjList[to];
    }

    // Imprime a lista de adjacência
    for (const auto& pair : adjList) {
        cout << pair.first << ": ";
        for (const auto& neighbor : pair.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Exercicio 1" << endl;

    cout << "Grafo 1:" << endl;
    readCreateList("Grafos/g1.txt");
    cout << endl;

    cout << "Grafo 2:" << endl;
    readCreateList("Grafos/g2.txt");
    cout << endl;

    cout << "Grafo 3:" << endl;
    readCreateList("Grafos/g3.txt");
    cout << endl;

    cout << "Exercicio 2" << endl;

    return 0;
}