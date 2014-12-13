class Nodo
{
  int valor;
  Nodo *der, *izq;
};

class Arbol
{
  Nodo *root;
 
  int cantidadDeNodos(int ini, int end)
  {
	return cantidadDeNodosRec(ini,end,root);
  }
 
  int cantidadDeNodosRec(int ini, int end, Nodo *p)
  {
	if(p == null) return 0;
	if(ini < p->valor && p->valor > end)
  	return    cantidadDeNodosRec(ini,end,p->izq) +
 				 cantidadDeNodosRec(ini,end,p->der) +
 				 1;
	if(p->valor < ini) return cantidadDeNodosRec(ini,end,p->der);
	if(p->valor > end) return cantidadDeNodosRec(ini,end,p->izq);
  }
 
  int  sumaValoresTotal(int ini, int end)
  {
	return sumaValoresTotalRec(ini, end, root);
  }
 
  int sumaValoresTotalRec(int ini, int end, Nodo *p)
  {
	if(p == null) return 0;
	if(ini < p->valor && p->valor > end)
  	return    sumaValoresTotalRec(ini,end,p) +
 				 sumaValoresTotalRec(ini,end,p) +
 				 1;
	if(p->valor < ini) return sumaValoresTotalRec(ini,end,p->der);
	if(p->valor > end) return sumaValoresTotalRec(ini,end,p->izq);
      }
 
  doble promedio(int ini, int end)
  {
	return (double) sumaValoresTotal(ini,end)/cantidadDeNodos(ini,end);
  }
 
  int minimo()
  {
	if(root == null) return -999;
	Nodo *p = root;
	while(p->izq != null)
  	p = p->izq;
    
	return p->valor;
  }
