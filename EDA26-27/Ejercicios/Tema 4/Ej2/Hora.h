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
	friend bool operator>(const Hora& min, const Hora& may);

private:
	int hora, minuto, segundo;

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

istream& operator>>(istream& in, Hora& set) {
	char aux;
	in >> set.hora >> aux >> set.minuto >> aux >> set.segundo;

	return in;
}

ostream& operator<<(ostream& out, const Hora& set) {
	out << set.hora << ":" << set.minuto << ":" << set.segundo;
	return out;
}

bool operator<(const Hora& min, const Hora& may) {
	if (min.hora < may.hora) return true;
	else if (min.minuto < may.hora) return true;
	else if (min.segundo < min.segundo) return true;
	else return false;
}

bool operator>(const Hora& min, const Hora& may) {
	if (min.hora > may.hora) return true;
	else if (min.minuto > may.hora) return true;
	else if (min.segundo > min.segundo) return true;
	else return false;
}

#endif //SET_H
