#include <fstream>
#include <iomanip>
#include "loteria.h"

Loteria::Loteria() : _numero(99, 0), _serie(999, 100), _premios(104, 1)
{
	this->_resultado = new Ganador[104];
	this->_premios.EstablecerEtiquetador(&Etiquetador_Premios);
}

Loteria::~Loteria()
{
	delete []this->_resultado;
}

void Loteria::Ejecutar()
{
	unsigned int i = 0;
	this->_numero.Iniciar();
	this->_serie.Iniciar();
	this->_premios.Iniciar();
	while (!this->_premios.Vacia())
	{
		Ganador r;
		r.numero = this->_numero.ExtraerBolaConRepo();
		r.serie = this->_serie.ExtraerBolaSinRepo();
		r.premio = this->_premios.ExtraerBolaSinRepo();
		this->_resultado[i] = r;
		++i;
	}
}


void Loteria::Guardar(const string& filename)
{
	std::ofstream file(filename);
	file << "Resultados de loteria" << std::endl;
	file << "Número," << std::setw(50) << "Serie," << std::setw(50) << "Premio" << std::endl;
	for (unsigned int j = 0; j < 104; ++j)
	{
		Ganador g = this->_resultado[j];
		file << std::setw(2) << std::setfill('0') << g.numero; 
		file << std::setw(50) << std::setfill(' ') << ','; 
		file << std::setw(2) << std::setfill('0') << g.serie; 
		file << std::setw(50) << std::setfill(' ') << ',' << g.premio << std::endl;
	}
	file.close();
}
