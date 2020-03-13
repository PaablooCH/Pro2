#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#ifndef NO_DIAGRAM
#include "Proceso.hh"
#include <queue>
#endif

/*
 * Clase usuario
 */ 
   
class Usuario {
 
/* Descripción: contiene su id y una cola con los procesos pendientes. */

private:
  /* Un usuario se representa mediante la cola con los procesos pendinetes y su usuario más
  antiguo. */
  
  queue<Proceso> pend;  // estados pendientes.
  int antiguo; //id del proceso más antiguo

public:
 
  // Constructora

  /** @Brief contrucción de Usuario
  \ Pre: cert 
  \ Post: El resultado es un usuario sin procesos pendientes 
  */
  Usuario(); 

  // Modificadoras

  /** @Brief añade proceso a usuario
  \ Pre: cierto
  \ Post: añade proceso a pendientes.
  */
  void anadir_proceso(Proceso &p);

  /** @Brief quita el primer proceso de pendientes
  \ Pre: cierto
  \ Post: pendientes ahora no tiene su primer elemento */
  void quitar_proceso_pendientes();

  /** @Brief obtiene el primer proceso de pendientes
  \ Pre: cierto
  \ Post: devuelve el proceso que estaba el primero */
  Proceso agarrar_proceso();

  // Consultoras

  /** @Brief consulta si hay procesos pendientes
  \ Pre: cierto
  \ Post: Devuelve false si los hay, true si no. 
  */ 
  bool pendientes();

  /** @Brief imprime el número de procesos pendientes y el id del más antiguo
  \ Pre: cierto
  \ Post: si existen procesos pendientes se imprime cuantos hay y el id del más antiguo, 
  si no tiene ninguno se imprime 0
  */
  void consulta_usu();

  /** @Brief Devuelve el número de procesos pendientes
  \ Pre: cierto
  \ Post: Devuelve el número de procesos pendientes del Usuario
  */
  int consulta_pendientes();
  
  // Entrada / Salida
  
private:


  
};
#endif
