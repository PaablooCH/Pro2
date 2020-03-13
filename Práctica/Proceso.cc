#include "Proceso.hh"

Proceso::Proceso(){
	id = 0;
  mem_oc = 0;
	id_us = "0";
  t = 0;
  pos = -1;
}

void Proceso::leer(){
	cin >> id_us >> id >> mem_oc >> t;
}

string Proceso::usuario(){
	return id_us;
}

int Proceso::id_p(){
	return id;
}

void Proceso::reducir_t(int ti, bool& sacar){
  t-=ti;
  if(t <= 0) sacar = true;
}

int Proceso::mem(){
  return mem_oc;
}

int Proceso::tiem(){
  return t;
}

void Proceso::leer_posicion(int n){
  pos = n;
}

int Proceso::cons_pos(){
  return pos;
}