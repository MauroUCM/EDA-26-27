/*
Nombre completo: Mauro Martinez Montes
DNI: 05942835A
Usuario del juez: EDA33
Qué has conseguido hacer y qué no: Algoritmo logaritmico O(n*logn) siendo n el tamaño de los vectores
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema y justificación del coste
pair<bool, int> resolver(const vector<int>& vAsc, const vector<int>& vDes, int ini, int fin) {
    if (fin - ini <= 1) {   // caso base
        if (vAsc[ini] == vDes[ini]) {
            return pair<bool, int>(true, ini);
        }
        else {
            if (vAsc[ini] > vDes[ini]) return pair<bool, int>(false, -1);
            else return pair<bool, int>(false, ini);
        }
    }
    int mid = (ini + fin) / 2;

    if(vAsc[mid] > vDes[mid]) return resolver(vAsc, vDes, ini, mid);
    else return resolver(vAsc, vDes, mid, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0) return false;
    vector<int> secAsc(n), secDesc(n);
    for (int& e : secAsc) cin >> e;
    for (int& e : secDesc) cin >> e;

    // Escritura del resultado
    pair<bool, int> sol = resolver(secAsc, secDesc, 0, n);

    if (sol.first) cout << "SI " << sol.second << "\n";
    else cout << "NO " << sol.second << " " << sol.second + 1 << "\n";

    return true;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 2/Ej16/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}