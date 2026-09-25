// Mauro Martinez Montes
// EDA33
// Coste: Lineal O(n)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int complementario(int& dato, int digts) {
    if (dato - digts <= 0) {  // caso base
        return digts - dato;
    }
    else return complementario(dato, (digts * 10) + 9);
}

int inverso(int dato, int acu) {
    if (dato <= 9) {    // caso base
        return (acu * 10) + (9 - dato);
    }
    else {
        return inverso(dato / 10, (acu * 10) + (9 - (dato % 10)));
    }
}

// función que resuelve el problema
pair<int, int> resolver(int& dato) {
    pair<int, int> sol;

    sol.first = complementario(dato, 9);
    sol.second = inverso(dato, 0);

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int dato;
    cin >> dato;

    pair<int, int> sol = resolver(dato);
    // escribir sol
    cout << sol.first << " " << sol.second << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 2/Ej2/1.in");
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