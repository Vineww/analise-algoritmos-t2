#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <limits>

// Tipos para grafos
typedef std::map<std::string, std::vector<std::string>> Grafo;
typedef std::map<std::string, std::vector<std::pair<std::string, int>>> GrafoPonderado;

// Funções para grafos sem peso
Grafo lerGrafoSemPeso(const std::string& nomeArquivo);
void imprimirGrafo(const Grafo& grafo);

// Funções para grafos com peso
GrafoPonderado lerGrafoComPeso(const std::string& nomeArquivo);
void imprimirGrafoPonderado(const GrafoPonderado& grafo);

#endif