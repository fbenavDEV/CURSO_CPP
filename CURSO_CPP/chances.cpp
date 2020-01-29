#include <fstream>
#include <iomanip>
#include "chances.h"

Chances::Chances() : _numeros(99,0),_series(999,100)
{
	this->_resultado = new Ganador[3];
}

Chances::~Chances()
{
	delete []this->_resultado;
}

void Chances::Ejecutar()
{
	this->_numeros.Iniciar();
	this->_series.Iniciar();
	for (unsigned int k = 0; k < 3; ++k)
	{
		Ganador p;
		p.numero = this->_numeros.ExtraerBolaConRepo();
		p.serie = this->_series.ExtraerBolaSinRepo();
		p.premio = k + 1;
		this->_resultado[k] = p;
	}
}

void Chances::Guardar(const string& filename)
{
	std::ofstream file(filename);
	file << "Resultados de loteria" << std::endl;
	file << "Número," << std::setw(50) << "Serie," << std::setw(50) << "Premio" << std::endl;
	for (unsigned int j = 0; j < 3; ++j)
	{
		Ganador g = this->_resultado[j];
		file << std::setw(2) << std::setfill('0') << g.numero;
		file << std::setw(50) << std::setfill(' ') << ',';
		file << std::setw(2) << std::setfill('0') << g.serie;
		file << std::setw(50) << std::setfill(' ') << ',' << g.premio << std::endl;
	}
	file.close();
}
