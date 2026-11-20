// Mauro Martinez Montes
// EDA33
// Coste: O(n^2) siendo n el número de peliculas por el número de actores en cada una

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;


using Pelicula = string;
using Actor = string;

using Reparto = unordered_map<Actor, int>;
using RepartosPeliculas = unordered_map<Pelicula, Reparto>;

void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas) {
    Pelicula peli; int numActores;
    Actor actor; int minutos;
    for (int i = 0; i < numPeliculas; ++i) {
        cin >> peli; cin >> numActores;
        Reparto repPel;
            for (int j = 0; j < numActores; ++j) {
                cin >> actor >> minutos;
                repPel.insert({ actor, minutos });
            }
        peliculas.insert({peli, repPel});
    }
}


void procesarEmisiones(RepartosPeliculas const& repartos, vector<string> const& secEmisiones) {
    unordered_map<Pelicula, int> auxEmi;
    Pelicula mostPeli = *secEmisiones.begin();
    map<Actor, int> minutosPorActor;
    int auxHighest = 0;

    for (string emision : secEmisiones) {
        if (!auxEmi.contains(emision)) auxEmi.insert({ emision, 1 });
        else auxEmi.at(emision)++;

        if (auxEmi.at(emision) >= auxEmi.at(mostPeli)) {
            mostPeli = emision;
        }

        for (auto a = repartos.at(emision).begin(); a != repartos.at(emision).end(); a++) {
            if (minutosPorActor.contains(a->first)) {
                minutosPorActor.at(a->first) += a->second;
            }
            else minutosPorActor.insert_or_assign(a->first, a->second);

            if (minutosPorActor.at(a->first) > auxHighest) auxHighest = minutosPorActor.at(a->first);
        }
    }

    // salida
    cout << auxEmi.at(mostPeli) << " " << mostPeli << "\n";
    cout << auxHighest << " ";
    for (auto b = minutosPorActor.begin(); b != minutosPorActor.end(); b++) {
        if (b->second == auxHighest) cout << b->first << " ";
    }

    cout << "\n";
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPelis, numEmisiones;
    cin >> numPelis;
    if (numPelis == 0)
        return false;

    // Lectura de los repartos de las peliculas
    RepartosPeliculas repartos;
    leerRepartos(numPelis, repartos);

    // Lectura de la secuencia de peliculas emitidas en vector<string>
    cin >> numEmisiones;
    vector<string> secEmisiones(numEmisiones);
    for (string& s : secEmisiones) cin >> s;

    procesarEmisiones(repartos, secEmisiones);

    return true;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 7/Ej6/1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}