#pragma once
#include<vector>
#include <algorithm>

using namespace std;

class  Polinomio
{
public:
	 Polinomio();
	 ~Polinomio() {};

	bool AddMonomio(int coeficiente, int exponente);

private:
	vector<pair<int, int>> elems;

};

Polinomio:: Polinomio()
{

}

bool Polinomio::AddMonomio(int coef, int expo) {
	auto locF = std::lower_bound(elems[0].second, elems[elems.size()].second, expo);

	if (coef != 0) {

	}
	else return false;
}