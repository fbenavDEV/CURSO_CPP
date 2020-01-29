#ifndef LOTERIA_H
#define LOTERIA_H

#include <string>
#include "tombola.h"
#include "etiquetador_premios.h"
#include "ganador.h"

using std::string;

class Loteria
{
private:
	Tombola _numero;
	Tombola _serie;
	Tombola _premios;
	Ganador* _resultado;
public:
	Loteria();
	void Ejecutar();
	void Guardar(const string& filename);
	~Loteria();
};

#endif



