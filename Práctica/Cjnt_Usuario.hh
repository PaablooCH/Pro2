#ifndef _CJNT_USUARIO_HH_
#define _CJNT_USUARIO_HH_

#include "Usuario.hh"
#include "Cluster.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <list>
#endif

/*
 * Clase procesador
 */ 
   
class Cjnt_Usuario {
 
/* Descripción: contiene todos los usuarios. */

private:
 
  /* Un Cjnt_Usuario se representa mediante un diccionario con todos los usuarios que hay. */
 
  map<string, Usuario> id;


public:
 
  // Constructora

  /** @Brief crea el cjnt
  \ Pre: cierto 
  \ Post: El resultado es un Cjnt_Usuario vacio 
  */
  Cjnt_Usuario(); 
   
  // Modificadoras

  /** @Brief introduce el usuario
  \ Pre: cierto 
  \ Post: se introduce un usuario con solo id,
  si ya estaba no se hace nada. 
  */
  void poner_usuario(string id_usu);
   
  /** @Brief quita usuario
  \ Pre: cierto 
  \ Post: el usuario con ese id queda eliminado, 
  si este tenia procesos pendientes o no existia no hace 
  nada. 
  */
  void quitar_usuario(string id_usu);
  
  /** @Brief comprobar si existe el usuario pasado por parametro
  \ Pre: cierto
  \ Post: Se comprueba si existe el usuario, si existe devuelve true, de lo contrario false
  */ 
  bool existe_usuario(string id_usu);
  
  /** @Brief envia proceso a usuario
  \ Pre: El usuario al que va dirijido el proceso existe 
  \ Post: el proceso pasa a estar en la cola de pendientes. 
  */
  void enviar_proceso_a_usuario(Proceso& p);
  
  /** @Brief envia proceso al cluster
  \ Pre: cierto
  \ Post: los procesos son introducidos en los procesadores correspondientes
  siguiendo la regla del más antiguo 
  */ 
  void enviar_procesos_a_cluster(int n, Cluster& c);
  
  // Consultoras
  
  /** @Brief consulta usuario
  \ Pre: usuario existe en el conjunto
  \ Post: muestra toda la inforamación de ese usuario por pantalla. 
  */ 
  void consultar_usuario(string s);

  /** @Brief obtención de usuario
  \ Pre: El usuario esta en el conjunto
  \ Post: Devuelve el usuario buscado
  */ 
  Usuario obtener_usuario(string usu);

 // Entrada / Salida

private:

  map<string, Usuario>::iterator busqueda_usuario_ideal();
   
};
#endif
