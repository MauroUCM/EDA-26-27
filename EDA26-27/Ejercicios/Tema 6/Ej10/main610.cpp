// Mauro Martinez Montes
// EDA33
// Coste: Lineal O(n), n = número de nodos totales en el arbol

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

// comprueba si el arbol no tiene hijos. Coste O(1)
bool esHoja(const bintree<string>& nod) {
    return nod.left().empty() && nod.right().empty();
}

// comprueba que el grupo no este muerto. Coste O(1)
bool isDead(const pair<string, int>& nod) {
    return nod.second <= 0;
}

// compara los grupos y devuelve el nombre del nuevo lider
string compareGroup(const pair<string, int>& gr1, const pair<string, int>& gr2) {
    if (!isDead(gr1) && !isDead(gr2)) {
        // comparacion numerica
        if (gr1.second > gr2.second) return gr1.first;
        else if (gr1.second < gr2.second) return gr2.first;

        // comparacion alfabetica
        if (gr1.first < gr2.first) return gr1.first;
        else return gr2.first;
    }
    else if (isDead(gr1)) return gr2.first;
    else if (isDead(gr2)) return gr1.first;
    else return "";
}

// función que resuelve el problema y justificación del coste
pair<string, int> resuelve(const bintree<string>& nod) {
    // caso base
    if (nod.empty()) return { "vacio", 0 };
    else if (esHoja(nod)) return { nod.root(), 1};

    // hijos
    pair<string, int> nodDra = resuelve(nod.right());
    pair<string, int> nodIzq = resuelve(nod.left());

    // resultado en el nodo actual
    pair<string, int> currNod;
    currNod.first = compareGroup(nodDra, nodIzq);
    currNod.second = nodDra.second + nodIzq.second;

    // procesamiento Orcos
    if (nod.root() == "Orcos") {
        currNod.second = currNod.second / 2;
        if (currNod.second <= 0) currNod.first = " ";
    }

    return currNod;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de datos de entrada
    bintree<string> a = leerArbol(string("."));

    // Llamada a la función
    auto sol = resuelve(a);

    // Escritura del resultado
    if (sol.second > 0) cout << sol.first << " " << sol.second << "\n";
    else cout << "Ninguno\n";
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 6/Ej10/1.in");
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