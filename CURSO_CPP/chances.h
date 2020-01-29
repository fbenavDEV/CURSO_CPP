#ifndef CHANCES_H
#define CHANCES_H

#include <string>
#include "tombola.h"
#include "ganador.h"

class Chances
{
private:
	Tombola _numeros;
	Tombola _series;	
	Ganador* _resultado;
public:
	Chances();
	void Ejecutar();
	void Guardar(const string& filename);
	~Chances();
};

#endif

