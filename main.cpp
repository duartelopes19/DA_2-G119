#include <iostream>
#include <vector>
#include "edmondskarp.cpp"

using namespace std;

int main() {
    int n, e, a, b, c, d;

    cin >> n;
    Graph *g = new Graph(n);
    cin >> e;
    for (int i=0; i<e; i++) {
        cin >> a >> b >> c >> d;
        g->addLink(a, b, c, d);
    }

    // Execucao exemplo usando 1 como no orig   em a 4 como o destino
    int flow = g->maxFlow_Capacity(1, 10);
    cout << "Capacidade máxima de transporte do grafo 1 ao 10: " << flow << endl;
    int flow_duration = g->maxFlow_Duration(1, 10);
    cout << "Duração minima de transporte do grafo 1 ao 10:" << flow_duration << endl;

    return 0;
}
