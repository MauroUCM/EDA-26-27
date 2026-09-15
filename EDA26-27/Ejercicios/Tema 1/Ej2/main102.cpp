// Mauro Martinez Montes
// EDA33
// Coste: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<int>& datos, int& picos, int& valles) {
    for (int i = 1; i < datos.size() - 1; i++) {
        if (datos[i] > datos[i - 1] && datos[i] > datos[i + 1]) {   // pico
            picos++;
        }
        else if (datos[i] < datos[i - 1] && datos[i] < datos[i + 1]) {  // valle
            valles++;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int picos = 0,
        valles = 0,
        num,
        aux;

    cin >> num;
    for (int c = 0; c < num; c++) {
        cin >> aux;
        datos.push_back(aux);
    }

    resolver(datos, picos, valles);

    // escribir sol
    std::cout << picos << " " << valles << "\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 1/Ej1/1.in");
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