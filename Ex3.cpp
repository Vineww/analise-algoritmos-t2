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
    visitados.insert(vertice);                            // Marca o vértice como visitado
    ordemVisita.push_back(vertice);                       // Adiciona o vértice à ordem de visitação
    for (const auto &filho : listaAdjacencia.at(vertice)) // Percorre os filhos do vértice
    {
        if (visitados.find(filho) == visitados.end())
        {
            buscaProfundidade(filho, listaAdjacencia, visitados, ordemVisita);
        }
    }
}

void executarDFS()
{
    // Defina aqui o arquivo e o vértice inicial
    const string nomeArquivo = "Grafos/g2.txt";
    const string verticeInicial = "a";

    map<string, vector<string>> listaAdjacencia;
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open())
    {
        cerr << "Erro: não foi possível abrir o arquivo '" << nomeArquivo << "'." << endl;
        return;
    }
    string linha;
    int linhaNum = 0;

    while (getline(arquivo, linha))
    {
        linhaNum++;
        if (linha.empty())
            continue;
        stringstream ss(linha);
        string origem, destino;
        if (!getline(ss, origem, ';') || !getline(ss, destino, ';'))
        {
            cerr << "Aviso: linha " << linhaNum << " mal formatada. Ignorando." << endl;
            continue;
        }
        listaAdjacencia[origem].push_back(destino);
        listaAdjacencia[destino];
    }

    if (listaAdjacencia.find(verticeInicial) == listaAdjacencia.end())
    {
        cerr << "Erro: vértice inicial '" << verticeInicial << "' não encontrado no grafo." << endl;
        return;
    }

    for (auto &par : listaAdjacencia)
    {
        sort(par.second.begin(), par.second.end());
    }

    set<string> visitados;
    vector<string> ordemVisita;
    buscaProfundidade(verticeInicial, listaAdjacencia, visitados, ordemVisita);

    cout << "\nOrdem de visitação (DFS a partir de '" << verticeInicial << "'):" << endl;
    for (size_t i = 0; i < ordemVisita.size(); ++i)
    {
        cout << ordemVisita[i];
        if (i != ordemVisita.size() - 1)
            cout << ",";
    }
    cout << endl;
}

int main()
{
    executarDFS();
    return 0;
}