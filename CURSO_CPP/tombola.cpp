#include "tombola.h"

std::random_device rd;
std::mt19937 Tombola::_generador(rd());

Tombola::Tombola(unsigned int bola_max, unsigned int bola_min)
{
	this->_tam = bola_max - bola_min + 1;
	unsigned int tam = this->_tam;
	this->_bolas = new unsigned int[tam];
	this->_distribucion = new double[tam];
	this->_afuera = new bool[tam];
	unsigned int etiqueta = bola_min;	
	double uniforme_dist = (double)1 / (double)tam;
	for (unsigned int k = 0; k < tam; ++k)
	{
		this->_bolas[k] = etiqueta;
		this->_afuera[k] = false;
		this->_distribucion[k] = uniforme_dist;
		++etiqueta;
	}
	this->_gen = nullptr;
	this->_etiquetador = nullptr;
}

void Tombola::EstablecerEtiquetador(Etiquetador etiquetador)
{
	this->_etiquetador = etiquetador;
}

Tombola::~Tombola()
{
	delete []this->_bolas;
	delete []this->_distribucion;
	delete []this->_afuera;
	if (this->_gen)
	{
		delete this->_gen;
	}
}

void Tombola::Iniciar()
{
	if (this->_etiquetador)
	{
		for (unsigned int k = 0; k < this->_tam; ++k)
		{
			(*this->_etiquetador)(k + 1, this->_bolas[k], this->_distribucion[k]);
		}
	}
	this->_gen = new std::discrete_distribution<unsigned int>(this->_distribucion, this->_distribucion + this->_tam);
}

unsigned int Tombola::ExtraerBolaConRepo()
{
	std::discrete_distribution<unsigned int>& dd = *this->_gen;
	unsigned int bola_id = dd(Tombola::_generador);
	return(this->_bolas[bola_id]);
}

bool Tombola::Vacia()
{
	bool vacia = true;
	for (unsigned int k = 0; k < this->_tam; ++k)
	{
		if (this->_afuera[k] == false)
		{
			vacia = false;
		}
		if (!vacia)	break;
	}
	return(vacia);
}


unsigned int Tombola::ExtraerBolaSinRepo()
{
	std::discrete_distribution<unsigned int>& dd = *this->_gen;
	unsigned int bola_id = dd(Tombola::_generador);
	while (this->_afuera[bola_id] == true)
	{
		bola_id = dd(Tombola::_generador);
	}
	this->_afuera[bola_id] = true;
	return(this->_bolas[bola_id]);
}

