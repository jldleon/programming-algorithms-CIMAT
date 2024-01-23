/* Tarea 2. Programación y Algoritmos.
    Parte 2. Lenguaje C++.

                José Luis de León Carmona.

Ejercicio 8. Al­go­rit­mo de Dijkstra:

- Im­ple­men­ta el al­go­rit­mo de Dijks­tra para en­con­trar el ca­mino más cor­to
en­tre dos no­dos en un gra­fo in­gre­sa­do por el usua­rio.
************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

vector<int> dijkstra(const Graph &graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cout << "Ingrese el número de nodos y el número de aristas: ";
    cin >> n >> m;

    Graph graph(n);

    cout << "Ingrese las aristas en el formato 'nodo_inicio nodo_fin peso':" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    int source, target;
    cout << "Ingrese el nodo de origen y el nodo de destino: ";
    cin >> source >> target;

    vector<int> distances = dijkstra(graph, source);

    if (distances[target] == INF) {
        cout << "No hay camino posible desde el nodo fuente al nodo destino." << endl;
    } else {
        cout << "La distancia más corta desde el nodo fuente al nodo destino es: " << distances[target] << endl;
    }

    return 0;
}
