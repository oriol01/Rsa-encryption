#include "intermidiateFunctions.h"
using namespace std;

void encrypt(key myKey)
{
	//esta función encrypta un mensaje.

	//primeramente computamos n
	myKey.n = myKey.p * myKey.q;

	//creamos un espacio de 99 (el último ha de ser \0) characteres para el mensaje
	char message[100];
	//pedimos el mensaje

	cout << "introduzca el mensaje a encryptar" << endl;
	cin >> message;

	//calculamos la longitud del mismo que sera usada en los loops de mas adelante
	int sSize = strlen(message);

	//creamos un array de 100 espacios donde guardaremos los characteres en ascii-97 asi solo usamos minusculas
	int uniMessage[100] = { 0 };

	for (int i = 0; i < sSize; i++)
	{
		uniMessage[i] = ((int)message[i] - 97);
	}
	int test = (int)message[0];

	//creamos un vector donde guardaremos el mensaje encryptado.
	vector<long long> encryptedMessage;
	//reservamos tanta memoria como longitud del mensaje
	encryptedMessage.reserve(sSize);

	printf("su mensaje encriptado es: ");
	for (int i = 0; i < sSize; i++)
	{
		encryptedMessage.push_back(0);
		encryptedMessage[i] = binExponentiation(uniMessage[i], myKey.e, myKey.n);

		//para evitar confusion si el entero tiene solo un dígito añadimos un 0 delante
		if (encryptedMessage[i] % 10 == encryptedMessage[i])
			printf("0");
		printf("%d", encryptedMessage[i]);
	}
	printf("\n");
}

void decrypt(key myKey)
{
	//computamos n
	myKey.n = myKey.p * myKey.q;

	//pedimos el mensaje a decryptar y lo guardamos en un array de char
	char messageToDecrypt[100];
	cout << "introduce el mensaje a desencriptar" << endl;
	cin >> messageToDecrypt;

	//creamos un array de ints donde guardaremos el mensaje como int
	vector<int> messageToDecryptAsIntArray;

	int sSize = (strlen(messageToDecrypt));

	//reservamos la mitad de memoria que ocupa el char ya que cada 2 cifras equivalen a un caracter encriptado
	messageToDecryptAsIntArray.reserve(sSize / 2);

	//rellenamos el array de 0, aqui seria mejor utilizar insert, un miembro de la libreria vector,
	//pero no acabo de comprender
	for (int i = 0; i < sSize / 2; i++)
		messageToDecryptAsIntArray.push_back(0);

	//tomando ventaja de que solo se introdicen números sabiendo que 0 es 48 en la tabla ascii restamos 48
	//al character pasado a ascii
	//generamos el número sabiendo que por ejemplo 58 = 5*10^1 + 8*10^0
	for (int i = 0, j = 0; i < sSize - 1; i += 2, j++)
	{
		messageToDecryptAsIntArray[j] = ((int)messageToDecrypt[i] - 48) * 10 + ((int)messageToDecrypt[i + 1] - 48);
	}

	//utilizamos las propiedades de la funcion de euler para legar a la siguiente expresión
	int euler = (myKey.p - 1) * (myKey.q - 1);
	//calculamos d aislandola de la expresión siguiente d*e = 1 (m euler) -> d*e-1 | euler
	int d = (1 + euler) / myKey.e;

	//creamos un vector para guardar el mensaje y reservamos la memoria adecuada
	vector<char> decryptedMessage;
	decryptedMessage.reserve(sSize / 2);

	//creamos esta variable para que durante el for-loop no tenga que hacer el calculo.
	int sSizeHalved = sSize / 2;

	for (int i = 0; i < sSizeHalved; i++)
	{
		//llenamos el array de 0
		//decryptamos elevando el mensaje que queremos decriptar a d
		decryptedMessage.push_back('0');
		decryptedMessage[i] = (char)(binExponentiation(messageToDecryptAsIntArray[i], d, myKey.n) + 97);
		printf("%c", decryptedMessage[i]);
	}

	printf("\n");
}