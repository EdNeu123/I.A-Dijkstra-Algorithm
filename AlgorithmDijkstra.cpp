#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo
{
private:
	int V; // número de vértices
	list<pair<int, int> > * adj;

public:
	Grafo(int V)
	{
		this->V = V;
		adj = new list<pair<int, int> >[V];
	}

	void addAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
	}

	int dijkstra(int orig, int dest)
	{
		int dist[V];
		int visitados[V];
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		dist[orig] = 0;
		pq.push(make_pair(dist[orig], orig));

		while(!pq.empty())
		{
			pair<int, int> p = pq.top();
			int u = p.second;
			pq.pop();

			if(visitados[u] == false)
			{
				visitados[u] = true;
				list<pair<int, int> >::iterator it;

				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					int v = it->first;
					int custo_aresta = it->second;

					if(dist[v] > (dist[u] + custo_aresta))
					{
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}
		return dist[dest];
	}
};

int main(int argc, char *argv[])
{
	Grafo g(5);

	g.addAresta(0, 1, 4);
	g.addAresta(0, 2, 2);
	g.addAresta(0, 3, 5);
	g.addAresta(1, 4, 1);
	g.addAresta(2, 1, 1);
	g.addAresta(2, 3, 2);
	g.addAresta(2, 4, 1);
	g.addAresta(3, 4, 1);

	cout << g.dijkstra(0, 4) << endl;

	return 0;
}
