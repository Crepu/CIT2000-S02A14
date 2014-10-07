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

	int encolarPedido(int tema, int dinero)
	{
		Tema t;
		if(estaVacia())
		{
			if(dinero == 100 || dinero == 200 || dinero == 400 || dinero == 800)
			{
				t = new Tema(tema);
				p = t;
				u = t;
				if(dinero == 200 || dinero == 800)
				{
					t = new Tema(tema);
					t->next = p;
					p = t;
				}
			}
			else
			{
				cout<<"coperó"<<endl;
			}
		}
		else
		{
			if(dinero == 100 || dinero == 200)
			{
				t = new Tema(tema);
				u->next = t;
				u = t;
				if(dinero == 200)
				{
					t = new Tema(tema);
					u->next = t;
					u = t;

				}
			}
			else if(dinero == 400 || dinero == 800)
			{
				t = new Tema(tema);
				t->next = p;
				p = t;
				if(dinero == 800)
				{
					t = new Tema(tema);
					t->next = p;
					p = t;
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
