// Caio Alvarenga Geraidine - 2173953
// Carolina de Souza Freitas - 2118784
// Vinicius vicari - 

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Função recursiva para realizar a busca em profundidade (DFS)
// vertice: vértice atual sendo visitado
// listaAdjacencia: representação do grafo (lista de adjacência)
// visitados: conjunto de vértices já visitados
// ordemVisita: ordem em que os vértices são visitados

void buscaProfundidade(const string &vertice, const unordered_map<string, vector<string>> &listaAdjacencia, unordered_set<string> &visitados, vector<string> &ordemVisita)
{
    visitados.insert(vertice);      // Marca o vértice como visitado
    ordemVisita.push_back(vertice); // Adiciona o vértice à ordem de visitação
    auto it = listaAdjacencia.find(vertice);
    if (it != listaAdjacencia.end())
    {
        // Percorre todos os filhos (vizinhos) do vértice atual
        for (const auto &filho : it->second)
        {
            // Se o filho ainda não foi visitado, faz chamada recursiva
            if (visitados.find(filho) == visitados.end())
            {
                buscaProfundidade(filho, listaAdjacencia, visitados, ordemVisita);
            }
        }
    }
}

// Função principal para executar a DFS a partir de um arquivo de grafo
void executarDFS()
{
    // Defina aqui o arquivo e o vértice inicial
    const string nomeArquivo = "Grafos/g2.txt";
    const string verticeInicial = "a";

    unordered_map<string, vector<string>> listaAdjacencia; // Lista de adjacência do grafo
    ifstream arquivo(nomeArquivo);                         // Abre o arquivo do grafo
    if (!arquivo.is_open())
    {
        cerr << "Erro: não foi possível abrir o arquivo '" << nomeArquivo << "'." << endl;
        return;
    }
    string linha;
    int linhaNum = 0;

    // Lê o arquivo linha por linha
    while (getline(arquivo, linha))
    {
        linhaNum++;
        if (linha.empty())
            continue;
        stringstream ss(linha);
        string origem, destino;
        // Espera que cada linha tenha o formato "origem;destino"
        if (!getline(ss, origem, ';') || !getline(ss, destino, ';'))
        {
            cerr << "Aviso: linha " << linhaNum << " mal formatada. Ignorando." << endl;
            continue;
        }
        listaAdjacencia[origem].push_back(destino); // Adiciona a aresta ao grafo
        listaAdjacencia[destino];                   // Garante que o destino também exista na lista
    }

    // Verifica se o vértice inicial existe no grafo
    if (listaAdjacencia.find(verticeInicial) == listaAdjacencia.end())
    {
        cerr << "Erro: vértice inicial '" << verticeInicial << "' não encontrado no grafo." << endl;
        return;
    }

    // Ordena os vizinhos de cada vértice para garantir ordem determinística na DFS
    for (auto &par : listaAdjacencia)
    {
        sort(par.second.begin(), par.second.end());
    }

    unordered_set<string> visitados; // Conjunto de vértices visitados
    vector<string> ordemVisita;      // Ordem de visitação dos vértices
    buscaProfundidade(verticeInicial, listaAdjacencia, visitados, ordemVisita);

    // Exibe a ordem de visitação
    cout << "\nOrdem de visitação (DFS a partir de '" << verticeInicial << "'):" << endl;
    for (size_t i = 0; i < ordemVisita.size(); ++i)
    {
        cout << ordemVisita[i];
        if (i != ordemVisita.size() - 1)
            cout << ",";
    }
    cout << endl;
}

// Função principal do programa
int main()
{
    executarDFS();
    return 0;
}