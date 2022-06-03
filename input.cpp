#include <iostream>
#include <vector>
#include "edmondskarp.cpp"
#include <string>
#include <fstream>

void addgraph(string file) {
    string temp;

    int n, e, a, b, c, d;
    ifstream ficheiro(file);
    getline(ficheiro, temp, ' ');
     n = stoi(temp);
    Graph *g = new Graph(n);
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
        g->addLink(a, b, c, d);
        i++;
    }

    int option, flow, grupo, s, t;;
    cout << endl << " Agencia de Viagens" << endl << endl;
    cout << "1 - Cenario 1: maximizar dimensão do grupo e indicar UM encaminhamento" << endl;
    cout << "2 - Cenario 2: maximizar dimensão do grupo e minimizar transbordos" << endl;
    cout << "3 - Cenario 3: indicar um encaminhamento dado a dimensão" << endl;
    cout << "4 - Cenario 4: corrigir o encaminhamento para que o grupo possa aumentar" << endl;
    cout << "5 - Cenario 5: dimensão maxima do grupo e um encaminhamento" << endl;
    cout << "6 - Cenario 6: dado um encaminhamento, determinar quando o grupo se reuniria novamente" << endl;
    cout << "7 - Cenario 7: tempo máximo de espera e locais onde esperam esse tempo" << endl;
    cout << "8 - Sair" << endl << endl;
    cout << "Opcao: ";
    cin >> option;
    switch (option) {
        case 1:

            break;
        case 2:

            break;

        case 3:
            cout << "Indique partida, chegada e dimensão do grupo: ";
            cin >> s >> t >> grupo;
            flow = g->maxFlow_Capacity(s, t, grupo);
            break;
        case 4:
            break;
        case 5:
            cout << "Indique partida e chegada: ";
            cin >> s >> t;
            flow = g->maxFlow_Capacity(s, t);
            break;

        case 6:
            break;
        case 7:

            break;
        default:
            return ;
    }

    cout << "dimensão máxima: " << flow;
}
