#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <fstream>
#include <set>

int main(int n_args, char** args)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	unsigned int n_bolas = 100;
	unsigned int n_premios = 100;

	double* w = new double[n_bolas];
	bool* sacada = new bool[n_bolas];
	double wt = 0;
	for (unsigned int k = 0; k < n_bolas; ++k)
	{
		w[k] = 1+0.1*(double)k;
		sacada[k] = false;
		wt = wt + w[k];
	}
	for (unsigned int k = 0; k < n_bolas; ++k)
	{
		std::cout << w[k] / wt << "  ";
	}

	std::discrete_distribution<> dd(w, w + n_bolas);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Numeros de salida: " << std::endl;
	for (unsigned int y = 0; y < n_premios; ++y)
	{
		bool bola_out = true;
		unsigned int bola = 0;
		while (bola_out)
		{
			int s = dd(gen);
			bola_out = sacada[s];
			if (!bola_out)
			{
				sacada[s] = true;
				bola = s;
			}		
			else
			{
				std::cout << "x";
			}
		}
		std::cout << std::endl;
		std::cout << bola << std::endl;	
	}
	std::getchar();
	return(0);
	delete []w;
	delete []sacada;
}