#include <iostream>

int main()
{
	int n = 50;
	int numero[n];
	int serie[n];
	for (int k = 0; k < n; ++k)
	{
		numero[k] = k;
		serie[k] = k * 10;
	}
	char msj[] = "Esto es una prueba con punteros y vectores";
	std::cout << msj << std::endl;
	for (int k = 0; k < 50; k=k+1)
	{
		std::cout << numero[k] << " :: " << serie[k] << std::endl;
		std::cout << "----------------- " << std::endl;
	}
	std::getchar();
}