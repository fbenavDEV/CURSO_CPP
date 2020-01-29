#include <iostream>
#include <string>
#include "loteria.h"
#include "chances.h"


int main(int n_args, char** args)
{
	unsigned int n = atoi(args[1]);
	std::cout << "Simulando sorteos" << std::endl;
	for (unsigned int k = 0; k < n; ++k)
	{
		std::string lf = "loto";
		std::string chf = "chances";
		Loteria loto;
		Chances ch;
		loto.Ejecutar();
		ch.Ejecutar();
		lf = lf + std::to_string(k+1) + ".csv";
		chf = chf + std::to_string(k+1) + ".csv";
		if ((k+1) % 10000 == 0)
		{
			//loto.Guardar(lf);
			//ch.Guardar(chf);
		}
		std::cout << ".";
	}
}