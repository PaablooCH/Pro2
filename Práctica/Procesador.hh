#ifndef _PROCESADOR_HH_
#define _PROCESADOR_HH_

#ifndef NO_DIAGRAM
#include <map>
#include "Proceso.hh"
#endif

/*
 * Clase procesador
 */ 
   
class Procesador {
 
// Descripción: contiene su id, la memoria y los procesos ejecutandose.

private:
 
  /* Un procesador se representa mediante su id, el tamaño de su memoria y 
  los procesos que este ejecutando. */
 
  int mem;  //tamaño memoria
  int mem_res; //memoria que queda libre
  map<int, Proceso> p;  //todos los procesos que ejecuta

public:
 
  // Constructora

  /** @Brief crea procesador
  \ Pre: cert
  \ Post: El resultado es un procesador vacio
  */
  Procesador();

  // Modificadoras

  /** @Brief Reduce el tiempo de todos sus procesos
  \ Pre: cierto
  \ Post: Se han reduciod los tiempos n unidades
  */
  void reduccion_tiempos(int n);

  /** @Brief Borra el proceso que se le pasa como referencia con todo lo que eso conlleva
  \ Pre: cierto
  \ Post: El procesador ya no contiene ese proceso y se ha liberado el espacio de memoria
  */
  void borrar(int id);

  /** @Brief Se añade el proceso con todo lo que eso conlleva
  \ Pre: cierto
  \ Post: El procesador ha añadido ese proceso y ha ocupado la memoria
  */
  bool incluir(Proceso& p); 

  // Consultoras
    
  /** @Brief Consulta todo los proceso que contiene el procesador
  \ Pre: cierto
  \ Post: Devulve la posición de cada proceso y toda la información de estos
  */
  void consulta_max();
  
  /** @Brief Consulta la memoria que le queda al procesador
  \ Pre: cierto
  \ Post: Devulve la memoria restante 
  */
  int consulta_mem_res();

  bool hueco(int mem_p);

  /** @Brief Consulta la memoria total
  \ Pre: cierto
  \ Post: Devulve la memoria total
  */
  int consulta_mem();

  // Entrada / Salida

  /** @Brief Se asigna memoria al procesador
  \ Pre: cierto
  \ Post: El procesador tiene memoria
  */
  void leer_memoria();
   
private:

  void borrar2(map<int, Proceso>::iterator& it);

};
#endif
