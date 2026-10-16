#pragma once
#include<vector>

using namespace std;

class  Polinomio
{
public:
	 Polinomio();
	~Polinomio();

	bool AddMonomio(int coeficiente, int exponente);

private:
	vector<pair<int, int>> elems;

};

 Polinomio:: Polinomio()
{
}

 Polinomio::~ Polinomio()
{
}

 bool Polinomio::AddMonomio(int coef, int expo) {
	 if (coef != 0) {

	 }
	 else return false;
 }