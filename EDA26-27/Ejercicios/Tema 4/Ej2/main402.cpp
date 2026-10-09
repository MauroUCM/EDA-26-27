// Mauro Martinez Montes
// EDA33
// Coste: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Hora.h"

using namespace std;

const int& buscarMinima(const vector<Hora>& trenes, const Hora& consulta, int ini, int fin) {

    return 0;
}

// función que resuelve el problema
void consultar(const vector<Hora>& trenes, Hora& consulta) {
    if (consulta.isValid()) {
        int sol = buscarMinima(trenes, consulta, 0, trenes.size());
        if (sol == -1) cout << "NO\n";
        else cout << trenes[sol] << "\n";
    }
    else cout << "ERROR\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numTren, numCons;
    cin >> numTren >> numCons;

    if (numTren == 0 && numCons == 0)
        return false;
    
    vector<Hora> trenes(numTren), consultas(numCons);
    for (Hora& t : trenes) cin >> t; 
    for (Hora& c : consultas) cin >> c;

    // escribir sol
    for (Hora& cons : consultas) consultar(trenes, cons);
    cout << "---\n";
            
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 4/Ej2/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
