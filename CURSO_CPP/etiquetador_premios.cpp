#include "etiquetador_premios.h"

void Etiquetador_Premios(const unsigned int bola_id, unsigned int& etiqueta, double& peso)
{
	peso = 1;
	if ((bola_id >= 1) && (bola_id <= 40))
	{
		etiqueta = 700000;
	}
	if ((bola_id >= 41) && (bola_id <= 90))
	{
		etiqueta = 500000;
	}
	if ((bola_id >= 91) && (bola_id <= 100))
	{
		etiqueta = 1000000;
	}
	if ((bola_id == 101))
	{
		etiqueta = 5000000;
	}
	if ((bola_id == 102))
	{
		etiqueta = 15000000;
	}
	if ((bola_id == 103))
	{
		etiqueta = 30000000;
	}
	if ((bola_id == 104))
	{
		etiqueta = 170000000;
	}
}