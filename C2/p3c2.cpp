class Persona
{
	string nombre;
	Persona *padre;
	Persona *primer_hijo;
	Persona *sgte_hermano;
  
Persona(string nombre)
{
	this->nombre = nombre;
	padre = null;
	primer_hijo = null;
	sgte_hermano = null;
}
  
Persona(string nombre, Persona *padre)
{
	this->nombre = nombre;
	this->padre = padre;
	primer_hijo = null;
	sgte_hermano = null;
}
  
void nuevo_hijo(Persona *p, string nombre)
{
	//Hijos estarán ordenados de menor a mayor.
	if(p == null) return;
	Persona *hijo = new Persona(nombre, p);
	if(p->primer_hijo == null)
	{
		p->primer_hijo = hijo;
	}
	else
	{
		Persona *hermanos = p->primer_hijo->sgte_hermano;
		p->primer_hijo = hijo;
		hijo->sgte_hermano = hermanos;
	}
}

void nuevo_hijo_desc(Persona *p, string nombre)
{
  	//Hijos ordenados de mayor a menor.
	if(p == null) return;
	Persona *hijo = new Persona(nombre, p);
	Persona *hermanos = p->primer_hijo;
	while(hermanos != null)
	{
		if(hermanos->sgte_herano == null) break;
		hermanos = hermanos->sgte_hermano;
	}
	hermanos->sgte_hermano = hijo;
}
 
int cantidad_de_hermanos_mayores(Persona *p)
{
  	if(p == null) return 0;
	Persona *hermanos = p->sgte_hermano;
	int mayores = 0;
	while(hermanos != null)
	{
		mayores++;
		hermanos=hermanos->sgte_hermano;
	}
	return mayores;
}
  
int cantidad_de_hermanos_mayores_desc(Persona *p)
{
  	if(p == null) return 0;
	Persona *papa = p->padre;
	Persona *hermanos;
	int mayores = 0;
	if(papa != null)
	{
		hermanos = papa->primer_hijo;
	}
	else return -1;//Error del sistema, persona sin padre.
	while(hermanos != null && hermanos->nombre != p->nombre)
	{
		mayores++;
		hermanos = hermanos->sgte_hermano;
	}
	return mayores;
}

 
int cantidad_de_primos(Persona *p)
{
  	if(p == null) return 0;
  	int primos = 0;
  	if(p->padre == null) return -1;//No tiene padre.
  	string padre = p->padre->nombre;
  	if(p->padre->padre == null) return -1;//No tiene abuelo.
  	Persona *tios = p->padre->padre->primer_hijo; //Primer hijo de mi abuelo, que seria mi tio.
  	while(tios != null) 
  	{
  		if(tios->nombre != padre)//Siempre que el tio no sea mi padre.
  		{
  			primos = primos + cantidad_hijos(tios);
  		}
  		tios = tios->sgte_hermano;
  	}
  	return primos; 
}
  
//Funciones extras
int cantidad_hijos(Persona *p)
{
  	if(p == null) return 0;
	Persona hijos = p->primer_hijo;
	int cont = 0;
	while(hijos != null)
	{
		cont++;
		hijos = hijos->sgte_hermano;
	}
	return cont;
}
};