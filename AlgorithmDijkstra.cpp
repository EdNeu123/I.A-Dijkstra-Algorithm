#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <limits>
#include <algorithm>

// Usando o namespace std para simplificar o código, como um estudante faria.
using namespace std;

const int INF = numeric_limits<int>::max(); // Representa o infinito

// Estrutura para representar o grafo
// Usamos um mapa onde a chave é o nó (char) e o valor é um vetor de pares.
// Cada par contém o nó vizinho e o peso da aresta.
using Grafo = map<char, vector<pair<char, int>>>;

// Função para reconstruir o caminho mais curto
vector<char> reconstruirCaminho(map<char, char>& predecessores, char inicio, char fim) {
    vector<char> caminho;
    char atual = fim;
    while (predecessores.count(atual)) {
        caminho.push_back(atual);
        if (atual == inicio) break;
        atual = predecessores[atual];
    }
    // O caminho é construído de trás para frente, então precisamos invertê-lo.
    reverse(caminho.begin(), caminho.end());
    
    if (caminho.empty() || caminho[0] != inicio) {
        return {}; // Retorna um vetor vazio se não houver caminho
    }
    return caminho;
}

// Função principal do Algoritmo de Dijkstra
void dijkstra(const Grafo& grafo, char inicio, char fim) {
    // Mapa para armazenar as menores distâncias encontradas
    map<char, int> distancias;
    // Mapa para reconstruir o caminho
    map<char, char> predecessores;
    
    // Fila de prioridade para determinar qual nó visitar em seguida (min-heap)
    // Armazena pares de {distância, nó}
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

    // 1. Inicialização
    for (auto const& [no, vizinhos] : grafo) {
        distancias[no] = INF;
    }
    distancias[inicio] = 0;
    pq.push({0, inicio});

    // 2. Loop principal do algoritmo
    while (!pq.empty()) {
        int distAtual = pq.top().first;
        char noAtual = pq.top().second;
        pq.pop();

        // Otimização: se já encontramos um caminho mais curto, pulamos
        if (distAtual > distancias[noAtual]) {
            continue;
        }
        
        // Se chegamos ao destino, podemos parar (otimização)
        if (noAtual == fim) {
            break;
        }

        // Para cada vizinho do nó atual...
        if (grafo.count(noAtual)) {
            for (auto const& vizinho : grafo.at(noAtual)) {
                char proximoNo = vizinho.first;
                int pesoAresta = vizinho.second;

                // Se um caminho mais curto for encontrado...
                if (distancias[noAtual] + pesoAresta < distancias[proximoNo]) {
                    // ...atualizamos a distância e o predecessor.
                    distancias[proximoNo] = distancias[noAtual] + pesoAresta;
                    predecessores[proximoNo] = noAtual;
                    pq.push({distancias[proximoNo], proximoNo});
                }
            }
        }
    }

    // 3. Impressão dos resultados
    cout << "Analise de Rota de '" << inicio << "' para '" << fim << "':\n\n";
    cout << "Distancias mais curtas a partir de '" << inicio << "':\n";
    for (auto const& [no, dist] : distancias) {
        if (dist == INF) {
            cout << "  - Para o no " << no << ": infinito\n";
        } else {
            cout << "  - Para o no " << no << ": " << dist << "\n";
        }
    }

    // Reconstrói e exibe o caminho
    vector<char> caminhoFinal = reconstruirCaminho(predecessores, inicio, fim);

    if (!caminhoFinal.empty()) {
        cout << "\nO caminho mais curto para '" << fim << "' e:\n";
        for (size_t i = 0; i < caminhoFinal.size(); ++i) {
            cout << caminhoFinal[i] << (i == caminhoFinal.size() - 1 ? "" : " -> ");
        }
        cout << "\nCusto total do caminho: " << distancias[fim] << endl;
    } else {
        cout << "\nNao ha caminho de '" << inicio << "' para '" << fim << "'." << endl;
    }
}

int main() {
    // --- Exemplo de Uso ---
    // Representação do grafo do nosso exemplo (mapa do bairro)
    Grafo meu_grafo;
    meu_grafo['A'] = {{'B', 4}, {'C', 2}};
    meu_grafo['B'] = {{'D', 5}};
    meu_grafo['C'] = {{'B', 1}, {'D', 8}, {'E', 10}};
    meu_grafo['D'] = {{'E', 2}, {'F', 6}};
    meu_grafo['E'] = {{'F', 3}};
    meu_grafo['F'] = {}; // Nó final, sem saídas

    // Ponto de partida e chegada
    char origem = 'A';
    char destino = 'F';

    // Executa o algoritmo
    dijkstra(meu_grafo, origem, destino);

    return 0;
}
