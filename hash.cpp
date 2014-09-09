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
};
