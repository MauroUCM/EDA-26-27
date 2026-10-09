// Mauro Martinez Montes
// EDA33
// Coste: no c jaja salu2

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool elemento_situado(const vector<int>& datos, int ini, int fin)
{
    if (fin - ini <= 1) {
        if (datos.size() == 0) {
            return false;
        }

        if (datos[ini] == ini) return true;
        else return false;
    }

    int mid = (fin + ini) / 2;

    if (datos[mid] > mid) return elemento_situado(datos, ini, mid);
    else return elemento_situado(datos, mid, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int num, aux;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    if (elemento_situado(datos, 0, datos.size())) cout << "SI\n";
    else cout << "NO\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 2/Ej6/1.in");
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