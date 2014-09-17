class Nodo
{
public:
	int cantidad;
	Nodo *sig;

	Nodo(int n)
	{
		cantidad = n;
		sig = null;
	}
};

class ColaUrgencia
{
	Nodo *ini;
	Nodo *fin;

	ColaUrgencia()
	{
		ini = null;
		fin = null;
	}

	void encolarUrgencia(int nivel)
	{
		if(nivel==0 || nivel==3) return;
		Nodo *nuevo = new Nodo(nivel);
		if(ini == null)
		{
			ini = nuevo;
		} 
		else
		{
			fin->sig = nuevo;
		}

		fin = nuevo;

	}

	Nodo desencolarUrgencia(int disp)
	{
		//Buscar gravedad 2
		Nodo *aux = ini;
		Nodo ant_aux;
		while(aux != null)
		{
			if(aux->cantidad == 1)
			{
				ant_aux = aux;
				aux = aux->sig;
			}
			else
			{
				//El elegido esta al inicio
				if(ini == aux)
				{
					ini = aux->sig;
					aux->sig = null;
					return aux;
				}

				//El elegido esta al final
				if(fin == aux)
				{
					fin = ant_aux;
					fin->sig = null;
					return aux;
				}
				//El elegido esta al medio 
				ant_aux->sig = aux->sig;
				aux->sig = null;
				return aux;
			}
		}
		//No hay ningún 2
		Nodo *aux = ini;
		ini = aux->sig;
		aux->sig = null;
		return aux;
	}

	bool estaVaciaUrgencia()
	{
		return ini == null;
	}
};
