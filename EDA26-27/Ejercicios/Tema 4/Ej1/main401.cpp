// Mauro Martinez Montes
// EDA33
// Coste: O(n*log(n)): n -> número de de veces que hay que aplicar la operacion antes de llegar a '1' o repetir un número 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Set.h"

using namespace std;

// función que resuelve el problema
bool isFeliz(Set<int>& set, int& num) {
    cout << num << " ";
    
    int numFel = 0;

    if (num == 1) return true;
    else if (set.contains(num)) return false;
    else {
        set.add(num);

        // calculo de la suma de los cuadrados de los digitos
        int aux;
        while (num != 0) {
            aux = num % 10;
            num = num / 10;
            numFel += aux * aux;
        }

        return isFeliz(set, numFel);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;

    if (!std::cin)
        return false;

    Set<int> set;
    //set.add(num);

    //cout << num << " ";
    if (isFeliz(set, num)) cout << "1\n";
    else cout << "0\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 4/Ej1/1.in");
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