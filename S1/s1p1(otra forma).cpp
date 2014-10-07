#include <iostream>

using namespace std;

class Tema
{
	int tema;
	Tema *next;

	Tema(int tema)
	{
		this->tema = tema;
	}
};

class ColaMusikito
{
	Tema *p;
	Tema *u;

	ColaMusikito()
	{
		p = null;
		u = null;
	}

	bool estaVacia()
	{
		return P == null;
	}

	int desencolar()
	{
		Tema *t;
		if(!estaVacia())
		{
			Tema *aux = p;
			p = p->next;
			int x = aux->tema;
			delete(aux);
			return x;
		}
		return null;
	}

	//estaVacia y desencolar quedan igual.

	int encolarInicio(int tema)
	{
		Tema t = new Tema(tema);
		if(estaVacia())
		{		
			p = t;
			u = t;
		}
		else
		{
			t->next = p;
			p = t;
		}
	}

	int encolarFinal(int tema)
	{
		Tema t = new Tema(tema);
		if(estaVacia())
		{		
			p = t;
			u = t;
		}
		else
		{
			u->next = t;
			u = t;
		}
	}

	int encolarPedido(int tema, int dinero)
	{
		if(dinero == 100 || dinero == 200 || dinero == 400 || dinero == 800)
		{
			if(dinero == 100 || dinero == 200)
			{
				encolarFinal(tema);
				if(dinero == 200)
				{
					encolarFinal(tema);

				}
			}
			else if(dinero == 400 || dinero == 800)
			{
				encolarInicio(tema);
				if(dinero == 800)
				{
					encolarInicio(tema);
				}
			}
			else if(dinero== 900)
			{
				t = p;
				if(p->tema = tema)
				{
					p=p->next;
					delete(t);
				}
				else
				{
					while(t != null)
					{
						if(t->next != null && t->next->tema == tema)
						{
							Tema *d = t->next;
							t->next = t->next->next;
							delete(d);
						}
						t = t->next;
					}
				}
			}
		}	
	}
};