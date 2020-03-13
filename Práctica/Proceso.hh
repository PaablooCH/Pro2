#ifndef _PROCESO_HH_
#define _PROCESO_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
using namespace std;
#endif

/*
 * Clase proceso
 */ 
   
class Proceso {
 
/* Descripción: contiene su id, el id de usuario al que pertenece,
la memoria que ocupa y el tiempo de ejecucion. */

private:
 
  /* Un proceso se representa mediante su id, el tamaño que ocupa el id del usuario y 
  el tiempo de ejecución. */
 
  int id; 
  int mem_oc;  //tamaño que ocupa
  string id_us; //el id de su usuario
  int t;  //tiempo en ejecutarse
  int pos; //posicion en el procesador


public:
 
  // Constructora

  /** @Brief contrucción de Proceso 
  \ Pre: cert
  \ Post: El resultado es un proceso vacio
  */
  Proceso(); 

  // Modificadoras
   
  /** @Brief Reduce el tiempo que el proceso esta en ejecución
  \ Pre: cierto
  \ Post: Se ha reducido su tiempo en ti unidades
  */
  void reducir_t(int ti, bool& sacar);
   
  // Consultoras

  /** @Brief Consulta id del proceso
  \ Pre: cierto
  \ Post: El resultado es el id del proceso
  */
  int id_p();

  /** @Brief Consulta id del usuario
  \ Pre: cierto
  \ Post: Devuelve el id del usuario
  */
  string usuario();
  
  /** @Brief Consulta la memoria que ocupa
  \ Pre: cierto
  \ Post: Devuelve el espacio que ocupa
  */
  int mem();
  
  /** @Brief Consulta el tiempo que le queda para acabar de ejecutarse
  \ Pre: cierto
  \ Post: Devuelve el tiempo restante
  */
  int tiem();

  int cons_pos();
   
  // Entrada / Salida

  /** @Brief Lectura de todos los parametros del proceso
  \ Pre: cierto
  \ Post: El resultado es un proceso al completo
  */
  void leer();

  void leer_posicion(int n);
 
private:

};
#endif
