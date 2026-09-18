// Mauro Martinez Montes
// EDA33

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
// El coste es exponencial O(n^2) ya que recorre el vector comparando cada elemento
// con todos los elementos de otro vector que almacena los valores ya usados
void resolver(vector<string>& datos) {
    vector<string> alrPresent;
    //vector<pair<string, int>> auxDatos;

    //for (int q = 0; q < datos.size(); q++) {
    //    auxDatos.push_back(pair<string, int>(datos[q], q));
    //}

    for (int o = 0; o < datos.size(); o++) {
        bool isDupli = false;
        for (int p = 0; p < alrPresent.size(); p++) {
            if (datos[o] == alrPresent[p]) {
                isDupli = true;
                break;
            }
        }
        if (!isDupli) {
            alrPresent.push_back(datos[o]);
            
        }
    }



    datos = alrPresent;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    vector<string> datos;
    string aux;
    int num;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    resolver(datos);
    // escribir sol
    for (string sol : datos) {
        cout << sol << " ";
    }

    cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 1/Ej10/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}