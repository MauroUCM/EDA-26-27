// Mauro Martinez Montes
// EDA33
// Coste: Lineal O(n)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>& datos, const int& vDisp, int ini, int fin) {
    if (fin - ini <= 1) {   
        return true;
    }

    int mid = (fin + ini) / 2;
    
    if (resolver(datos, vDisp, ini, mid)
        && resolver(datos, vDisp, mid, fin)
        && vDisp <= abs(datos[ini] - datos[fin - 1]))
    {
        return true;
    }
    else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int siz, disp, aux;

    cin >> siz >> disp;

    if (!std::cin)
        return false;
    
    for (int i = 0; i < siz; i++) {
        cin >> aux;
        datos.push_back(aux);
    }
    
    // escribir sol
    if (resolver(datos, disp, 0, datos.size())) cout << "SI\n";
    else cout << "NO\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 2/Ej4/1.in");
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