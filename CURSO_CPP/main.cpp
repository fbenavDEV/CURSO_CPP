#include <iostream>
#include <string>
#include <iomanip>
#include <random>

int main()
{
	const int n = 45;
	std::mt19937 rnd;
	std::uniform_int_distribution<int> gen_numero(0,99);
	std::uniform_int_distribution<int> gen_serie(0, 999);

	unsigned int numero[n];
	unsigned int serie[n];
	for (int k = 0; k < n; ++k)
	{
		numero[k] = gen_numero(rnd);
		serie[k] = gen_serie(rnd);
	}
	std::string msj = "Sorteo de loteria, con Mersenn-Twister";
	std::cout << msj << std::endl;
	for (int k = 0; k < n; ++k)
	{
		std::cout << "Numero: " << std::setw(2) << std::setfill('0') << numero[k];
		std::cout << "   Serie: " << std::setw(3) << std::setfill('0') << serie[k];
		std::cout << std::endl;
		//printf("Numero: %02d, Serie: %03d ", numero[k], serie[k]);
	}
	std::getchar();
}