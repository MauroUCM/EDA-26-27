// Mauro Martinez Montes
// EDA33
// Coste: Lineal O(n)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(string& word1, string& word2) {
    vector<int>acumulador('z' - 'a', 0);

    for (char letter : word1) {
        acumulador[letter - 'a']++;
    }
    for (char letter : word2) {
        acumulador[letter - 'a']--;
    }
    for (int cont : acumulador) {
        if (cont != 0) return false;
    }

    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    string word1, word2;
    cin >> word1 >> word2;
    
    // escribir sol
    if (resolver(word1, word2)) cout << "SI\n";
    else cout << "NO\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 1/Ej5/1.in");
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