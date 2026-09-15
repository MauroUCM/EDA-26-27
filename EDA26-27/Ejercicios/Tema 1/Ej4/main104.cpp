// Mauro Martinez Montes
// EDA33
// Coste: lineal O(n)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<int>& datos) {
    int delAccumulator = 0,
        datSize = datos.size();

    for (int o = 0; o < datSize; o++) {
        if (datos[o] % 2 != 0) {
            delAccumulator++;
        }
        else(datos[o - delAccumulator] = datos[o]);
    }

    datos.resize(datSize - delAccumulator);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int siz, aux;

    cin >> siz;
    for (int i = 0; i < siz; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    resolver(datos);

    // escribir sol
    for (int sol : datos) {
        cout << sol << " ";
    }
    cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 1/Ej4/1.in");
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