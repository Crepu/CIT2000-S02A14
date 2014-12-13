clas Nodo{
  int valor;
  Nodo *der, *izq;
};

calss Arbol{
  Nodo*root;
  
  int padre(int x){
    if(root == null) return -1;
    if(x == root->valor) return -1;
    Nodo *padre = root;
    Nodo *hijo;
    if(x > root->valor){
      hijo = root->der;
    }
    else{
      hijo = root->izq;
    }
    while(hijo != null){
      if(x == hijo->valor){
        return padre->valor;
      }
      if(x > padre->valor){
        hijo = padre->der;
      }
      else{
        hijo = padre->izq;
      }
    }
    
    return -1;
  }
  
  int contarNodos(Nodo *p){
    return 1 + contarNodos(p->der) 
      			contarNodos(p->izq);
  }
  
  int cantidadDescendientes(int x){
    Nodo *aux = root;
    if(aux == null) return 0;
    while(aux != null && aux->valor != x){
      if(x > aux->valor){
        aux = aux->der;
      }
      else{
        aux = aux->izq;
      }
    }
    if(aux != null){
      return contarNodos(aux);
    }
    else{
      return 0;
    } 
  }
  
  bool existeCamino(int r, int s){
    //Asumo que el camino es desde r a s y solo bajando.
    if(s > r) return false;
    Nodo *p = root;
    if(root == null) return false;
    while(p != null)
    {
      if(r == p->valor) break;
      if(r > p->valor){
        p = p->der;
      }
      else{
        p = p->izq;
      }
    }
    if(p == null) return false;
    while(p != null){
      if(s == p->valor) return true;
      if(s > p->valor){
        p = p->der;
      }
      else{
        p = p->izq;
      }
    }
    if(p == null) return false;
  }
  
  int eliminaMinimo()
  {
    (if root == null) return -999;
    Nodo *p = root, *padre = p;
    while(p != null)
    {
      padre = p;
      if(p->izq == null) break;
      p = p->izq;
    }
    
    padre->izq = null;
    return p->valor;
  }
