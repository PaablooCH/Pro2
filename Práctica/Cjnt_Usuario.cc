#include "Cjnt_Usuario.hh"

Cjnt_Usuario::Cjnt_Usuario(){

}

void Cjnt_Usuario::poner_usuario(string id_usu){
	Usuario u;
	id.insert(make_pair(id_usu,u));
}

void Cjnt_Usuario::quitar_usuario(string id_usu){
	if(id[id_usu].pendientes()) id.erase(id_usu);
}

bool Cjnt_Usuario::existe_usuario(string id_usu){
	map<string, Usuario>::iterator it = id.find(id_usu);
	return it!=id.end();
}

Usuario Cjnt_Usuario::obtener_usuario(string usu){
    return id[usu];
}

void Cjnt_Usuario::consultar_usuario(string s){
	id[s].consulta_usu();
}

void Cjnt_Usuario::enviar_proceso_a_usuario(Proceso& p){
	id[p.usuario()].anadir_proceso(p);
}

void Cjnt_Usuario::enviar_procesos_a_cluster(int n, Cluster& c){
	bool puesto, existe_proceso;
	int id_pro;
	list<Proceso> no_aceptados;
	list<Proceso>::iterator it = no_aceptados.end();
	int i = 0;
	while (i<n){
		puesto = false;
		existe_proceso = false;
		Proceso p;
		Usuario u;
		map<string, Usuario>::iterator it2 = busqueda_usuario_ideal();
		u = it2->second;
		if(u.consulta_pendientes() != 0){
			p = u.agarrar_proceso();
			it2->second = u;
			existe_proceso = true;
			id_pro = c.procesador_optimo(p.mem());
			if (id_pro != -1) c.poner_proceso_en_procesador(id_pro, p, puesto);
		}

		if (not puesto and existe_proceso){
			no_aceptados.insert(it, p);
		}

		else i++;
	}

	it = no_aceptados.begin();

	while (it != no_aceptados.end()){
		Proceso p = *it;
		enviar_proceso_a_usuario(p);
		++it;
	}
}

map<string, Usuario>::iterator Cjnt_Usuario::busqueda_usuario_ideal(){
	map<string, Usuario>::iterator it = id.begin();
	map<string, Usuario>::iterator it2 = id.begin();
	Usuario u;
	Usuario u2;
	while(it2 != id.end()){
		u = it-> second;
		u2 = it2-> second;
		if (u.consulta_pendientes() < u2.consulta_pendientes()) it = it2;
		++it2;
	}
	return it;
}
