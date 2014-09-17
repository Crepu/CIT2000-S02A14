class Grupo
{
public:
	int cantidad;
	Grupo *sig;

	Grupo(int n)
	{
		cantidad = n;
		sig = null;
	}
};

class Fila
{
	Grupo *ini;
	Grupo *fin;

	Fila()
	{
		ini = null;
		fin = null;
	}

	void llegada(int cantidad)
	{
		if(cantidad==1) return;
		Grupo *nuevo = new Grupo(cantidad);
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

	Grupo salida(int disp)
	{
		Grupo *aux = ini;
		Grupo ant_aux;
		while(aux != null)
		{
			if(aux->cantidad > disp)
			{
				ant_aux = aux;
				aux = aux->sig;
			}
			else
				break;
		}

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
};
