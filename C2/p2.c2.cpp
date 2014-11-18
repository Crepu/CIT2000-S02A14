int altura (Nodo *p)
{
  if(p == null) return 0;
  return 1 + max(altura(p->der),
                 altura(p->izq));
}

int contadorNodos(Nodo *p)
{
  if(p == null) return 0;
  return 1 + contadorNodos(p->izq)
    	   + contadorNodos(p->der);
}

bool isBalanced(Nodo *p)
{
  if(p == null) return true;
  return (altura(p->der)-altura(p->izq) <= 1) &&
    	 isBalanced(p->der) &&
    	 isBalanced(p->izq);
}

bool isStable(Nodo *p)
{
  if(p == null) return true;
  return (contadorNodos(p->der) == contadorNodos(p->izq)) &&
    	 isStable(p->der) && 
    	 isStable(p->izp);
  
}