class Carta
{
  string nombre;
  string apellido1;
  string apellido2;
  int edad;
  char sexo;
  string direccion;
 
};

class Enano
{
  Cola hombresMenores;
  Cola hombresMayores;
  Cola mujeresMenores;
  Cola mujeresMayores;
}

class Division
{
  Enano *enanos;
 
  Division()
  {
	enanos = new Enano[28];
  }
 
  int quien_leyo(Carta *x)
  {
	int x = stoi(x->nombre) +  stoi(x->apellido1) + stoi(x->apellido2) + x->edad;
	return (42*(x%23))%28;
  }
    
  void llega_carta(Carta *x)
  {
	int i = quien_leyo(x);
    
	if(x->sexo == 'M')
	{
  	if(x->edad > 6) (enanos[i]->hombresMayores).agregar(x);
  	else (enanos[i]->hombresMenores).agregar(x);
	}
	else
	{
  	if(x->edad > 4) (enanos[i]->mujeresMayores).agregar(x);
  	else (enanos[i]->mujeresMenores).agregar(x);
	}
  }
 
  void lee_carta(Enano *x)
  {
	if(!((x->hombresMayores).estaVacio()))
	{
  	(x->hombresMayores).eliminar()
	}    
	if(!((x->hombresMenores).estaVacio()))
	{
  	(x->hombresMenores).eliminar()
	}    
	if(!((x->mujeresMayores).estaVacio()))
	{
  	(x->mujeresMayores).eliminar()
	}    
	if(!((x->mujeresMenores).estaVacio()))
	{
  	(x->mujeresMenores).eliminar()
	}
  }
 
