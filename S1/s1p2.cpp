#include <iostream>

using namespace std;

class Paciente
{
	int rut;
	int gravedad;
};

class SalaUrgencia
{
	TDACola *GG;
	TDACola *LL;

	SalaUrgencia()
	{
		GG = new TDACola();
		LL = new TDACola();
	}

	void ingresarPacienteUrgencia(Paciente p)
	{
		if(p.gravedad == 2)
		{
			GG->encolar(p);
		}
		else if(p.gravedad == 1)
		{
			LL->encolar(p);
		}
	}

	void llamaPacienteUrgencia(Paciente p)
	{
		if(!(GG->estaVacia()))
		{
			GG->desencolar();
		}
		else if(!(LL->estaVacia()))
		{
			LL->desencolar();
		}
	}

	bool estaVaciaUrgencia()
	{
		return GG->estaVacia() && LL->estaVacia();
	}
}