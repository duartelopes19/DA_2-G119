#include <iostream>
#include <climits>
#include <list>
#include <set>

using namespace std;

// Classe que representa um no
class Node {
public:
    list<pair<int, int>> adj;  // Lista de adjacencias
    bool visited;              // No ja foi visitado?
    int distance;              // Distancia ao no origem da pesquisa
};

// Classe que representa um grafo
class Graph3 {
public:
    int n;          // Numero de nos do grafo
    Node *nodes;    // Array para conter os nos

    Graph3(int n) {
        this->n = n;
        nodes = new Node[n + 1];  // +1 se os nos comecam em 1 ao inves de 0
    }

    void addLink(int a, int b, int c) {
        nodes[a].adj.push_back({b, c});
    }

    // Algoritmo de Dijkstra
    void dijkstra(int s) {
        //Inicializar nos como nao visitados e com distancia infinita
        for (int i = 1; i <= n; i++) {
            nodes[i].distance = INT_MAX;
            nodes[i].visited = false;
        }

        // Inicializar "fila" com no origem
        nodes[s].distance = 0;
        set<pair<int, int>> q; // By "default" um par e comparado pelo primeiro elemento
        q.insert({0, s});      // Criar um par (dist=0, no=s)

        // Ciclo principal do Dijkstra
        while (!q.empty()) {

            // Retirar no com menor distancia (o "primeiro" do set, que e uma BST)
            int u = q.begin()->second;
            q.erase(q.begin());
            nodes[u].visited = true;
            cout << "Se o destino for " << u << " a distãncia minima é = " << nodes[u].distance << endl;

            // Relaxar arestas do no retirado
            for (auto edge: nodes[u].adj) {
                int v = edge.first;
                int cost = edge.second;
                if (!nodes[v].visited && nodes[u].distance + cost < nodes[v].distance) {
                    q.erase({nodes[v].distance, v});  // Apagar do set
                    nodes[v].distance = nodes[u].distance + cost;
                    q.insert({nodes[v].distance, v}); // Inserir com nova (e menor) distancia
                }
            }
        }
    }

    void dijkstra2(int s) {
        int temp[n];
        //Inicializar nos como nao visitados e com distancia infinita
        for (int i = 1; i <= n; i++) {
            nodes[i].distance = INT_MAX;
            nodes[i].visited = false;
            temp[i] = 0;
        }
        int i = 0;
        // Inicializar "fila" com no origem
        nodes[s].distance = 0;
        set<pair<int, int>> q; // By "default" um par e comparado pelo primeiro elemento
        q.insert({0, s});      // Criar um par (dist=0, no=s)

        // Ciclo principal do Dijkstra
        while (!q.empty()) {

            // Retirar no com menor distancia (o "primeiro" do set, que e uma BST)
            int u = q.begin()->second;
            q.erase(q.begin());
            nodes[u].visited = true;

            // Relaxar arestas do no retirado
            for (auto edge: nodes[u].adj) {
                int v = edge.first;
                int cost = edge.second;
                if (!nodes[v].visited && nodes[u].distance + cost < nodes[v].distance) {
                    if(nodes[v].distance != INT_MAX) {
                        cout << u << " : " << (nodes[v].distance - (nodes[u].distance + cost)) << endl;
                    }
                    q.erase({nodes[v].distance, v});  // Apagar do set
                    nodes[v].distance = nodes[u].distance + cost;
                    q.insert({nodes[v].distance, v}); // Inserir com nova (e menor) distancia
                }
            }
        }
    }
}
;