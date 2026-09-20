// Mauro Martinez Montes
// EDA33
// Coste: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int>& datos) {
    int latest;

    latest = datos[0];

    if (latest < datos[1]) {    // orden ascendente
        for (int c = 1; c < datos.size(); c++) {
            if (latest >= datos[c]) {
                return false;
            }
            latest = datos[c];
        }
    }
    else if (latest > datos[1]) {  // orden descendente
        for (int c = 1; c < datos.size(); c++) {
            if (latest <= datos[c]) {
                return false;
            }
            latest = datos[c];
        }
    }
    else return false;

    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int siz, aux;

    cin >> siz;
    for (int i = 0; i < siz; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    if (siz == 0)
        return false;

    // escribir sol
    if (resolver(datos)) cout << "DALTON\n";
    else cout << "DESCONOCIDOS\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 1/Ej1/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
