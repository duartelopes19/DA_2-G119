#include "input.cpp"

using namespace std;

int main() {
    int i;
    cout << "Escolha um teste: \n";
    cout << "1 - in01_b.txt\n";
    cout << "2 - in02_b.txt\n";
    cout << "3 - in03_b.txt\n";
    cout << "4 - in04_b.txt\n";
    cout << "5 - in05_b.txt\n";
    cout << "6 - in06_b.txt\n";
    cout << "7 - in07_b.txt\n";
    cout << "8 - in08_b.txt\n";
    cout << "9 - in09_b.txt\n";
    cout << "10 - in10_b.txt\n";
    cout << "Opcão: \n";
    cin >> i;

    switch(i) {
        case 1: {
            addgraph("../Tests_B/in01_b.txt");
            break;
        }
        case 2: {
            addgraph("../Tests_B/in02_b.txt");
            break;
        }
        case 3: {
            addgraph("../Tests_B/in03_b.txt");
            break;
        }
        case 4: {
            addgraph("../Tests_B/in04_b.txt");
            break;
        }
        case 5: {
            addgraph("../Tests_B/in05_b.txt");
            break;
        }
        case 6: {
            addgraph("../Tests_B/in06_b.txt");
            break;
        }
        case 7: {
            addgraph("../Tests_B/in07_b.txt");
            break;
        }
        case 8: {
            addgraph("../Tests_B/in08_b.txt");
            break;
        }
        case 9: {
            addgraph("../Tests_B/in09_b.txt");
            break;
        }
        case 10: {
            addgraph("../Tests_B/in10_b.txt");
            break;
        }
    }
    return 0;
}
