#include <iostream>

int main()
{
	int numero[50];
	int serie[50];
	for (int k = 0; k < 50; ++k)
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