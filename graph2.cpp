// Pedro Ribeiro - DCC/FCUP

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// Classe que representa um grafo
class Graph2 {
public:
    int n;                    // Numero de nos do grafo
    vector<vector<int>> adj; // Lista de adjacencias
    vector<vector<int>> cap; // Matriz de capacidades
    vector<vector<int>> dur; // Matriz de duracao

    Graph2(int n) {
        this->n = n;
        adj.resize(n + 1); // +1 se os nos comecam em 1 ao inves de 0
        cap.resize(n + 1);
        dur.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cap[i].resize(n + 1);
            dur[i].resize(n + 1);
        }
    }

    void addLink(int a, int b, int c, int d) {
        // adjacencias do grafo nao dirigido, porque podemos ter de andar no sentido
        // contrario ao procurarmos caminhos de aumento
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] = c;
        dur[a][b] = d;
    }

    // BFS para encontrar caminho de aumento
    // devolve valor do fluxo de capacidades nesse caminho
    int bfs_capacity(int s, int t, vector<int> &parent) {
        for (int i = 1; i <= n; i++) parent[i] = -1;

        parent[s] = -2;
        queue<pair<int, int>> q; // fila do BFS com pares (no, capacidade)
        q.push({s, INT_MAX});    // inicializar com no origem e capacidade infinita

        while (!q.empty()) {
            // returnar primeiro no da fila
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            // percorrer nos adjacentes ao no atual (cur)
            for (int next: adj[cur]) {
                // se o vizinho ainda nao foi visitado (parent==-1)
                // e a aresta respetiva ainda tem capacidade para passar fluxo
                if (parent[next] == -1 && cap[cur][next] > 0) {
                    parent[next] = cur;                        // atualizar pai
                    int new_flow = min(flow, cap[cur][next]);  // atualizar fluxo
                    if (next == t) return new_flow;            // chegamos ao final?
                    q.push({next, new_flow});                  // adicionar a fila
                }
            }
        }

        return 0;
    }

    // Algoritmo de Edmonds-Karp para fluxo maximo para capacidades entre s e t
    int maxFlow_Capacity(int s, int t, int i = 0, int j = 0) {
        int flow = 0;             // fluxo a calcular
        vector<int> parent(n + 1); // vetor de pais (permite reconstruir caminho)
        set<int> path;


        while (true) {
            int new_flow = bfs_capacity(s, t, parent);// fluxo de um caminho de aumento
            if (new_flow == 0) break;         // se nao existir, terminar
            // imprimir fluxo e caminho de aumento
            flow += new_flow;  // aumentar fluxo total com fluxo deste caminho
            int cur = t;
            while (cur != s) { // percorrer caminho de aumento e alterar arestas
                int prev = parent[cur];
                cap[prev][cur] -= new_flow;
                cap[cur][prev] += new_flow;
                cur = prev;
                path.insert(cur);
            }
        }

        if (flow < i + j) return 0;
        cout << "Encaminhamento: ";
        for (int i: path)
            cout << i << "->";
        cout << t << endl;

        return flow;
    }


};