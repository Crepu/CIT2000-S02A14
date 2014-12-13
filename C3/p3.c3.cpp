class Persona{
  string name;
  int rut;
  int edad;
};

class Resort{
  
  int **buses;
  
  Resort(){
    buses = new int[40];
    for(int i = 0; i<40; i++)
    {
      buses[i] = new Persona[29]; //Quedan 29 espacios. Las tias ya tienen asignado.
      //Del 0 al 27 van niños y en el 28 va el apoderado.
      for(int j = 0; j<29; j++)
      {
        buses[i][j] = null;
      }
    }
  }
  
  int queBus(Persona *x){
	int equis = x->rut;
	return (42*(equis%997))%40;
  }
  
  int quedaEspacio(int i){
    for(int j = 0; j<28; j++){
      if(buses[i][j] == null) return j;
    }
    return -1;
  }
  
  int insertarNino(Nino *x){
    int i = queBus(x);
    if(int j = quedaEspacio(i) != -1){
      buses[i][j] = x;
    }
    //Encontrar bus con espacio.
    while((int j = quedaEspacio(i)) == -1)){
      if(i == 39) i = 0;
      else i++;
    }
    buses[i][j] = x;
    return;
  }
      
  void insertarNinoApoderado(Persona *nino, Persona *apoderado){
    int i = queBus(nino);
    if(buses[i][28] == null){
      if((int j = quedaEspacio(i)) != -1){
        buses[i][j] = nino;
        buses[i][28] = apoderado;
        return;
      }
    }
    //Busco bus donde no  haiga apoderado y quede espacio pal cabro chico.
    while((int j = quedaEspacio(i)) == -1) || buses[i][28] != null){
      if(i == 39) i = 0;
      else i++;
    }
    buses[i][j] = nino;
    buses[i][28] = apoderado;
    return;
  }
};
        

