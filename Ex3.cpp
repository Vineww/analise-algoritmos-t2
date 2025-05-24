#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Função recursiva para realizar a busca em profundidade (DFS)
void buscaProfundidade(const string &vertice, const map<string, vector<string>> &listaAdjacencia, set<string> &visitados, vector<string> &ordemVisita)
{
    visitados.insert(vertice); // Marca o vértice como visitado
    ordemVisita.push_back(vertice); // Adiciona o vértice à ordem de visitação
    for (const auto &filho : listaAdjacencia.at(vertice)) // Percorre os filhos do vértice
    {
        if (visitados.find(filho) == visitados.end())
        {
            buscaProfundidade(filho, listaAdjacencia, visitados, ordemVisita);
        }
    }
}

int main()
{
    map<string, vector<string>> listaAdjacencia; // Estrutura para armazenar a lista de adjacência
    ifstream arquivo("Grafos/g2.txt"); // Abre o arquivo g2.txt
    string linha;

    // Lê cada linha do arquivo e monta a lista de adjacência
    while (getline(arquivo, linha))
    {
        if (linha.empty())
            continue;
        stringstream ss(linha);
        string origem, destino;
        getline(ss, origem, ';'); // Lê o vértice de origem
        getline(ss, destino, ';'); // Lê o vértice de destino
        listaAdjacencia[origem].push_back(destino); // Adiciona a aresta
        listaAdjacencia[destino]; // Garante que o destino aparece na lista, mesmo sem filhos
    }

    // Ordena os filhos de cada vértice em ordem alfabética
    for (auto &par : listaAdjacencia)
    {
        sort(par.second.begin(), par.second.end());
    }

    // Executa a busca em profundidade a partir do vértice "a"
    set<string> visitados;
    vector<string> ordemVisita;
    buscaProfundidade("a", listaAdjacencia, visitados, ordemVisita);

    // Exibe a ordem de visitação dos vértices
    cout << "\nOrdem de visitação (DFS a partir de 'a'):" << endl;
    for (size_t i = 0; i < ordemVisita.size(); ++i)
    {
        cout << ordemVisita[i];
        if (i != ordemVisita.size() - 1)
            cout << ",";
    }
    cout << endl;

    return 0;
}