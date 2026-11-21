// Mauro Martinez Montes
// EDA33
// Coste: O(n), siendo n el tamaño del string

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

// función que resuelve el problema
bool resolver(const string& datos) {
    stack<char> parentes;

    for (char i : datos) {
        if (i == '(' || i == '[' || i == '{') parentes.push(i);
        else if (i == ')' || i == ']' || i == '}') {
            if (parentes.empty()) return false;
            switch (i)
            {
            case ')':
                if (parentes.top() == '(') parentes.pop();
                else return false;
                break;
            case ']':
                if (parentes.top() == '[') parentes.pop();
                else return false;
                break;
            case '}':
                if (parentes.top() == '{') parentes.pop();
                else return false;
                break;
            default:
                return false;
                break;
            }
        }
    }

    return parentes.empty();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string datos;
    getline(cin, datos);

    if (!std::cin)
        return false;

    // escribir sol
    if (resolver(datos)) cout << "SI\n";
    else cout << "NO\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("Ejercicios/Tema 5/Ej1/1.in");
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