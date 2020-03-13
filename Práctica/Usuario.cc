#include "Usuario.hh"

Usuario::Usuario(){
	antiguo = -1;
}

void Usuario::anadir_proceso(Proceso &p){
	if(antiguo == -1) antiguo = p.id_p();
	pend.push(p);
}

bool Usuario::pendientes(){
	return pend.empty();
}

void Usuario::quitar_proceso_pendientes(){
    pend.pop();
    if(not pend.empty()) {
    	Proceso p = pend.front();
    	antiguo = p.id_p();
    }

    else antiguo = -1;
}

void Usuario::consulta_usu(){
	if(antiguo != -1) cout << "  " << pend.size() << ' ' << antiguo << endl;

	else cout << "  " << 0 << endl;
}

int Usuario::consulta_pendientes(){
	return pend.size();
}

Proceso Usuario::agarrar_proceso(){
	Proceso p = pend.front();
	quitar_proceso_pendientes();
	return p;
}