#ifndef HORA_H
#define HORA_H

#include <iostream>
#include <algorithm>

using namespace std;

class  Hora
{
public:
	 Hora();
	~Hora();

	bool isValid();

	// sobrecarga de operadores
	friend istream& operator>>(istream& in, Hora& s);
	friend ostream& operator<<(ostream& out, const Hora& s);
	friend bool operator<(const Hora& min, const Hora& may);
	friend bool operator<=(const Hora& min, const Hora& may);

private:
	int hora, minuto, segundo;

	static void escribirDigito(const int& digit);
};

 Hora::Hora()
{
}

 Hora::~Hora()
{
}

 bool Hora::isValid() {
	 if (0 > hora || hora > 23 || 0 > minuto || minuto > 59 || 0 > segundo || segundo > 59) return false;
	 else return true;
 }

 void Hora::escribirDigito(const int& digit) {
	 if (digit < 10) cout << "0" << digit;
	 else cout << digit;
 }

istream& operator>>(istream& in, Hora& set) {
	char aux;
	in >> set.hora >> aux >> set.minuto >> aux >> set.segundo;

	return in;
}

ostream& operator<<(ostream& out, const Hora& set) {
	set.escribirDigito(set.hora);
	out << ":";
	set.escribirDigito(set.minuto);
	out << ":";
	set.escribirDigito(set.segundo);

	return out;
}

bool operator<(const Hora& min, const Hora& may) {
	if (min.hora < may.hora) return true;
	else if (min.hora == may.hora && min.minuto < may.minuto) return true;
	else if (min.hora == may.hora && min.minuto == may.minuto && min.segundo < may.segundo) return true;
	else return false;
}

bool operator<=(const Hora& min, const Hora& may) {
	if (min.hora > may.hora) return false;
	else if (min.hora == may.hora && min.minuto > may.minuto) return false;
	else if (min.hora == may.hora && min.minuto == may.minuto && min.segundo > may.segundo) return false;
	else return true;
}

#endif //SET_H
