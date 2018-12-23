#pragma once
//usamos vector para implementar los arrays dinámicos o listas ya presentes en snap
#include <vector>
//incluimos string para usar principalmente strlen para calcular la longitud de un array de chars
#include <string>
//iostream es usada ya que cin y cout es mas simple en algunos casos que printf y scanf
#include <iostream>
//incluye printf para imprimir
#include <stdio.h>

using namespace std;

struct key
{
	int p;
	int q;
	int n;
	int e;
	int d;
};

int binExponentiation(int base, long long exponent, int mod);
vector<long long> decimalToBinary(long long decNumber);
void copyVect(const vector<long long> old, vector<long long> &nuevo);