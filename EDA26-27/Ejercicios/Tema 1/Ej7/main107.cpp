// Mauro Martinez Montes
// EDA33
// Coste: Lineal O(n+m)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
void comparaListados(vector<char> const& eda, vector<char> const& tpv,
    vector<char>& comunes, vector<char>& soloEda, vector<char>& soloTpv) {
    vector<int> diccionario;

    diccionario.resize('z' - 'a' + 1, 0);

    for (char edadita : eda) {
        diccionario[edadita - 'a'] += 1;
    }
    for (char tpvita : tpv) {
        diccionario[tpvita - 'a'] += 2;
    }

    for (int h = 0; h < diccionario.size(); h++) {
        if (diccionario[h] == 1) {
            soloEda.push_back(h + 'a');
        }
        else if (diccionario[h] == 2) {
            soloTpv.push_back(h + 'a');
        }
        else if (diccionario[h] == 3) {
            comunes.push_back(h + 'a');
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<char> eda(n);
    vector<char> comunes;
    vector<char> soloEda;
    vector<char> soloTpv;
    for (char& e : eda) cin >> e;
    cin >> n;
    vector<char> tpv(n);
    for (char& e : tpv) cin >> e;
    comparaListados(eda, tpv, comunes, soloEda, soloTpv);
    for (char& e : comunes) cout << e << " ";
    cout << endl;
    for (char& e : soloEda) cout << e << " ";
    cout << endl;
    for (char& e : soloTpv) cout << e << " ";
    cout << endl;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 1/Ej7/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
