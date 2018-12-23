#include "functions.h"
using namespace std;

int main()
{
	char c;
	key myKey;

	do
	{
		//pedimos al usuario el modo a usar.
		cout << "Para entrar en modo encriptación introduzca e, para entrar en modo decriptación introduzca d, para salir introduzca *" <<endl;
		cin >> c;
		//como necesitamos pedir p, q, e en ambos casos lo podemos poner aqui para no repetir el código, similar
		//al factor común.
		cout << "introduzca p, q, e separados por espacios" << endl;
		cin >> myKey.p >> myKey.q >> myKey.e;

		switch (c)
		{
		case 'e':
			encrypt(myKey);
		break;

		case 'd':
			decrypt(myKey);
		break;	
		case '*':
			return 0;
		/*default:
			cout << "Error" << endl;	
		break;*/
		}

	} while (true);
}