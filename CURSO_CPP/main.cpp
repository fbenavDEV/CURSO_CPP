#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <fstream>

int main(int n_args, char** args)
{
	int n = atoi(args[2]);
	std::string filename(args[1]);
	std::random_device dev;
	std::mt19937 rnd(dev());
	std::uniform_int_distribution<> gen_numero(0,99);
	std::uniform_int_distribution<> gen_serie(0, 999);
	unsigned int* numero = new unsigned int[n];
	unsigned int* serie = new unsigned int[n];
	for (int k = 0; k < n; ++k)
	{
		numero[k] = gen_numero(rnd);
		serie[k] = gen_serie(rnd);
	}
	std::ofstream file(filename);
	std::string msj = "Sorteo de loteria con Mersenne-Twister";
	file << msj << std::endl;
	file << "Numero , Serie" << std::endl;
	for (int k = 0; k < n; ++k)
	{
		file << std::setw(2) << std::setfill('0') << numero[k] << ",";
		file << std::setw(3) << std::setfill('0') << serie[k];
		file << std::endl;
	}
	file.close();
	return(0);
}