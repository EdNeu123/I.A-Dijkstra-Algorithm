# Implementação do Algoritmo de Dijkstra em C++

Este projeto contém uma implementação simples e didática do Algoritmo de Dijkstra em C++. O código foi desenvolvido como parte de uma atividade acadêmica para a disciplina de Análise e Desenvolvimento de Sistemas, com o objetivo de encontrar o caminho mais curto entre dois pontos em um grafo ponderado.

## Sobre o Projeto

O algoritmo calcula a rota de menor custo (seja distância, tempo ou qualquer outra métrica) de um nó de partida para todos os outros nós em um grafo. Esta implementação utiliza:

* `std::map` para representar o grafo.
* `std::priority_queue` para selecionar eficientemente o próximo nó a ser visitado.
* Uma abordagem clara e comentada, ideal para fins de estudo.

## Como Compilar e Executar

Você precisará de um compilador C++ (como G++ ou Clang) para executar o código.

1.  **Salve o código** em um arquivo chamado `dijkstra.cpp`.
2.  **Abra o terminal** ou prompt de comando e navegue até a pasta onde você salvou o arquivo.
3.  **Compile o código** com o seguinte comando:
    ```bash
    g++ dijkstra.cpp -o dijkstra
    ```
4.  **Execute o programa compilado**:
    ```bash
    ./dijkstra
    ```

A saída do programa mostrará as distâncias mais curtas do ponto de origem para todos os outros, o caminho mais curto para o destino especificado e o custo total desse caminho.

## Modificando o Grafo

Para testar com um mapa diferente, você pode facilmente editar o grafo dentro da função `main()`:

```cpp
int main() {
    // Crie seu grafo aqui
    Grafo meu_grafo;
    meu_grafo['A'] = {{'B', 10}, {'C', 3}};
    meu_grafo['B'] = {{'C', 1}, {'D', 2}};
    // ... adicione outros nós e arestas

    // Defina a nova origem e destino
    char origem = 'A';
    char destino = 'D';

    dijkstra(meu_grafo, origem, destino);

    return 0;
}
```

## Exemplo Padrão

O exemplo incluído no código representa um pequeno mapa de um bairro:

* **Nós:** A (Casa), B (Padaria), C (Escola), D (Mercado), E (Parque), F (Farmácia).
* **Arestas:** As ruas, com pesos que representam o tempo de viagem.
* **Objetivo:** Encontrar o caminho mais rápido da **Casa (A)** até a **Farmácia (F)**.

---
*Este projeto foi desenvolvido por Eduardo J. P. Neumann & Iago Tramontin.*
