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

class Lista
{
	Nodo *head;

	Lista()
	{
		head = null;
	}

	void enlistar(int x)
	{
		Nodo *nuevo = new Nodo(x);
		nuevo->sig = head;
		head = nuevo;
	}

	int desenlistar()
	{
		int r = head->cantidad;
		Nodo *aux = head;
		head = aux->sig;
		delete(aux);
		return r;
	}

	int estaVacia()
	{
		return head == null;
	}
};
class ColaUrgencia
{
	Lista *graves;
	Lista *leves;

	ColaUrgencia()
	{
		graves = new Lista();
		leves = new Lista();
	}

	void encolarUrgencia(int nivel)
	{
		if(nivel==0 || nivel==3) return;
		if(nivel == 1)
		{
			leves->enlistar(nivel);
		}
		else
			graves->enlistar(nivel);
	}

	int desencolarUrgencia()
	{
		if(!(graves->estaVacia()))
		{
			return graves->desenlistar();
		}
		if(!(leves->estaVacia()))
		{
			return leves->desenlistar();
		}
		return null;
	}

	bool estaVaciaUrgencia()
	{
		return (graves->estaVacia() && leves->estaVacia());
	}
};
