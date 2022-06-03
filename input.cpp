#include <iostream>
#include <vector>
#include "graph.h"
#include "graph.cpp"
#include <string>
#include <fstream>

void addgraph(string file) {
    string temp;

    int n, e, a, b, c, d;
    ifstream ficheiro(file);
    getline(ficheiro, temp, ' ');
     n = stoi(temp);
    Graph *g = new Graph(n,true);
    getline(ficheiro, temp, '\n');
    e = stoi(temp);
    int i =1;
    while (!ficheiro.eof() && i < e) {
        getline(ficheiro, temp, ' ');
        a = stoi(temp);
        getline(ficheiro, temp, ' ');
        b = stoi(temp);
        getline(ficheiro, temp, ' ');
        c = stoi(temp);
        getline(ficheiro, temp, '\n');
        d = stoi(temp);
        g->addEdge(a, b, c, d);
        i++;
    }

    int option, grupo, s, t;
    while(true) {
        cout << endl << " Agencia de Viagens" << endl << endl;
        cout << "1 - Cenario 1.1: maximizar dimensão do grupo e indicar UM encaminhamento" << endl;
        cout << "2 - Cenario 1.2: maximizar dimensão do grupo e minimizar transbordos" << endl;
        cout << "3 - Cenario 2.1: indicar um encaminhamento dado a dimensão" << endl;
        cout << "4 - Cenario 2.2: corrigir o encaminhamento para que o grupo possa aumentar" << endl;
        cout << "5 - Cenario 2.3: dimensão maxima do grupo e um encaminhamento" << endl;
        cout << "6 - Cenario 2.4: dado um encaminhamento, determinar quando o grupo se reuniria novamente" << endl;
        cout << "7 - Cenario 2.5: tempo máximo de espera e locais onde esperam esse tempo" << endl;
        cout << "8 - Sair" << endl << endl;
        cout << "Opcao: ";
        cin >> option;
        switch (option) {
            case 1: {
                cout << "Indique partida e a chegada: ";
                cin >> s >> t;
                pair<vector<int>, int> k = g->dijkstra_maximize_capacity(s, t);

                cout << "Encaminhamento com capacidade = " << k.second << ": (";

                for (int i = 0; i < k.first.size(); i++) {
                    cout << k.first[i];
                    if (i != k.first.size() - 1) { cout << ","; }
                }
                cout << "\n";
                break;
            }
            case 2: {
                pair<vector<int>,int> j = g->dijkstra_minimize_edges(0,e-1);
                pair<vector<int>,int> k = g->dijkstra_maximize_capacity(0, e-1);

                if(std::equal(j.first.begin(),j.first.end(), k.first.begin())) {
                    std::cout << "Path that both maximizes capacity and minimizes edges: (";
                }

                else {
                    std::cout<<"Path that maximizes capacity: (";

                    for(int i=0; i<k.first.size(); i++){
                        std::cout << k.first[i];
                        if(i!=k.first.size()-1){std::cout<<",";}
                    }
                    std::cout<<")\nCapacity: "<<k.second<<" Edges: "<<k.first.size()<< "\n\n";

                    std::cout << "Path that minimizes edges: (";
                }

                for (int i = 0; i < j.first.size(); i++) {
                    std::cout << j.first[i];
                    if (i != j.first.size() - 1) { std::cout << ","; }
                }

                std::cout << ")\nCapacity: " << j.second << " Edges: " << j.first.size()<< "\n\n";

                break;
            }
            case 3:
                cout << "Indique partida, chegada e dimensão do grupo: ";
                cin >> s >> t >> grupo;
                //flow = g->maxFlow_Capacity(s, t, grupo);
                break;
            case 4:
                break;
            case 5:
                cout << "Indique partida e chegada: ";
                cin >> s >> t;
                cout << "Max flow: " << g->edmonds_karp(s,t) << endl;
                break;
            case 6:
                break;
            case 7:

                break;
            default:
                return;
        }
        cout << "\nPress any key to continue\n";
        char c;
        cin >> c;
    }
}
