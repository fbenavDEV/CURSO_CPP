#ifndef TOMBOLA_H
#define TOMBOLA_H

#include <string>
#include <random>

using std::string;

typedef void (*Etiquetador)(const unsigned int bola_id, unsigned int& etiqueta, double& peso); 

class Tombola
{
private:
	static std::mt19937 _generador;
	unsigned int _tam;
	unsigned int* _bolas;
	double* _distribucion;
	bool* _afuera;
	std::discrete_distribution<unsigned int>* _gen;
	Etiquetador _etiquetador;
public:
	Tombola(unsigned int bola_max, unsigned int bola_min = 0);
	void Iniciar();
	unsigned int ExtraerBolaConRepo();
	unsigned int ExtraerBolaSinRepo();
	void EstablecerEtiquetador(Etiquetador etiquetador);
	bool Vacia();
	~Tombola();
};


#endif

