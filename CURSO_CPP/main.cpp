#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <fstream>
#include <set>

int main(int n_args, char** args)
{
	std::string filename = args[1];
	unsigned int n_iteraciones = atoi(args[2]);
	std::random_device rd;
	std::mt19937 gen(rd());
	unsigned int n_bolas = 50;
	unsigned int n_premios = 10;

	double* w = new double[n_bolas];
	bool* sacada = new bool[n_bolas];
	unsigned int* empirica = new unsigned int[n_bolas];
	double wt = 0;
	for (unsigned int k = 0; k < n_bolas; ++k)
	{
		w[k] = 1+(double)k*k;
		sacada[k] = false;
		wt = wt + w[k];
		empirica[k] = 0;
	}

	std::ofstream file(filename);
	std::discrete_distribution<> dd(w, w + n_bolas);
	file << "Probabilidades: " << std::endl;
	for (unsigned int k = 0; k < n_bolas; ++k)
	{
		file << w[k] / wt << "  ";
	}
	file << std::endl;
	file << std::endl;

	for (unsigned int k = 0; k < n_iteraciones; ++k)
	{
		file << std::endl;
		file << std::endl;
		file << "Numeros de salida. Sorte numero: " << k << std::endl;
		for (unsigned int k = 0; k < n_bolas; ++k)
		{
			sacada[k] = false;
		}

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
					file << "x";
				}
			}
			file << std::endl;
			file << bola << std::endl;
			empirica[bola] = empirica[bola] + 1;
		}
	}
	file << std::endl;
	file << std::endl;
	file << "Distribucion de bolas: " << std::endl;
	for (unsigned int k = 0; k < n_bolas; ++k)
	{
		file << std::setw(2) << std::setfill('0') << k << " ";
		for (unsigned int s = 0; s < empirica[k]; ++s)
		{
			file << "*";
		}
		file << std::endl;
	}
	file.close();
	delete []w;
	delete []sacada;
	delete []empirica;
	return(0);
}