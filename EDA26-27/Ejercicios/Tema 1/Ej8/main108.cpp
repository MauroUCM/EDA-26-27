// Mauro Martinez Montes
// EDA33

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
// el coste de esta funcion es lineal O(n), ya que recorre el vector entero una 
// sola vez comparando cada elemento una unica vez cada uno
void resolver(vector<string>& datos) {
    int accu = 0;    
    string lastCompared = "";

    for (int p = 0; p < datos.size(); p++) {
        if (lastCompared == datos[p]) {
            accu++;
        }
        else datos[p - accu] = datos[p];

        lastCompared = datos[p];
    }

    datos.resize(datos.size() - accu);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<string> datos;
    string aux;
    int num;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> aux;
        datos.push_back(aux);
    }

    resolver(datos);
    // escribir sol
    for (string sol : datos) {
        cout << sol << " ";
    }

    cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 1/Ej8/1.in");
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