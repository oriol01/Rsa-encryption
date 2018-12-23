#include "intermidiateFunctions.h"
using namespace std;

int binExponentiation(int base, long long exponent, int mod)
{
	//declaramos result como 1 ya que es el elemento neutro de la multiplicación
	int result = 1;
	//ya que sabemos que siempre tendremos que añadir la base^2^0 -> base
	int previous = base;

	//en este vector guardaremos el exponente en binario girado en orden ya que es mas facil de implementar en código
	vector<long long> exponentInBaseTwo;

	//en este vector guardaremos los pasos al ir elvenado a la 2 tambien invetido ya que así podemos usar el mismo
	//indice para acceder a exponentInBaseTwo y baseSquaredSeries
	vector<long long> baseSquaredSeries;

	copyVect(decimalToBinary(exponent), exponentInBaseTwo);

	//como sabemos que siempre empezaremos por la base la añadimos directamente antes de hacer el loop
	int vectorSize = exponentInBaseTwo.size();
	baseSquaredSeries.reserve(vectorSize);
	baseSquaredSeries.push_back(previous);

	//rellenamos el baseSquaredSeries
	for (int i = 0; i < vectorSize - 1; i++)
	{
		previous = previous * previous;
		previous %= mod;
		baseSquaredSeries.push_back(previous);
	}

	//aqui computamos el resultado final
	for (int i = 0; i < vectorSize; i++)
	{
		if (exponentInBaseTwo[i] != 0)
		{
			result *= (exponentInBaseTwo[i] * baseSquaredSeries[i]);
			result %= mod;
		}

	}
	return result;
}

vector<long long> decimalToBinary(long long decNumber)
{
	vector<long long> binArr;
	//al estar usando un long long al computar 1/2 returna 0 ya que trunca en el decimal
	while (decNumber != 0)
	{
		binArr.push_back(decNumber % 2);
		decNumber /= 2;
	}

	return binArr;
}

void copyVect(const vector<long long> old, vector<long long> &nuevo)
{
	int aSize = old.size();
	nuevo.reserve(aSize);
	int checkSize = nuevo.capacity();

	for (int i = 0; i < aSize; i++)
		nuevo.push_back(old[i]);
}