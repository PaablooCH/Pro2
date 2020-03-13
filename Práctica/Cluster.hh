#ifndef _CLUSTER_HH_
#define _CLUSTER_HH_

#include "Procesador.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <vector>
#endif

/*
 * Clase cluster
 */ 
   
class Cluster {
 
// Descripción: contiene los diferentes procesadores de la maquina

private:
 
  /* Un Cluster se representa mediante sus procesadores, incluidos en un vector,
  y sus id en un árbol */
 
  BinTree<int> id; // 
  vector<Procesador> proc;
  int n;  //número procesadores

public:
 
  // Constructora

  /** @Brief Creadora por defecto; 
  \ Pre: cert 
  \ Post: El resultado es un cluster sin ningún procesador */ 
  Cluster(); //usada
    
  // Modificadoras
  
  /** @Brief configura el cluster
  \ Pre: cierto 
  \ Post: Se leerá el número de procesadores, sus conexiones 
  y la memoria de cada uno de ellos en orden creciente de id
  Si se vuelve a configurar más adelante, los procesos activos
  se eliminan, pero los procesos pendientes de los usuarios se
  conservan para el siguiente
  cluster.
  */
  void configurar_cluster(); 
  
  /** @Brief avanzar tiempo
  \ Pre: cierto
  \ Post: se ha avanzado n unidades de tiempo
  */
  void avanzar_tiempo(int ti); 
  
  /** @Brief quitar un proceso a un procesador
  \ Pre: cierto
  \ Post: El proceso ya no esta en ese procesador, si nunca lo ha estado no ocurre nada.
  */ 
  void quitar_proceso_de_procesador(int id_pro, int id_p); 

  /** @Brief poner proceso en procesador
  \ Pre: cierto
  \ Post: el proceso solo se incluira si este cabe en la memoria del procesador
  */ 
  void poner_proceso_en_procesador(int id_pro, Proceso& p, bool& puesto); 
  
  // Consultoras
  
  /** @Brief consulta el procesador
  \ Pre: cierto
  \ Post: datos del procesador
  */ 
  void consultar_procesador(int id_pro); 

  /** @Brief busca el procesador optimo para la funcion enviar proceso al cluster
  \ Pre: cierto
  \ Post: devuelve el id del procesador q cumple las características de enviar proceso 
  */
  int procesador_optimo(int mem_p);

  int busqueda_memoria_ajustada(int mem_p);
 
 // Entrada / Salida
   
private:
  
  void crear_cluster(BinTree<int>& id1);

  int consultar_profundidad(const BinTree<int>& id1, int id_pro, bool& encontrado); 

  void i_procesador_optimo(const BinTree<int>& id1, int& pr, int mem_p, bool& primero); 

};
#endif
