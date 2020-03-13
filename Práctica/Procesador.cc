#include "Procesador.hh"

Procesador::Procesador(){
    mem = -1;
    mem_res = -1;
}

void Procesador::reduccion_tiempos(int n){
    bool sacar;
    map<int, Proceso>::iterator it = p.begin();
   
    while (it != p.end()){
        sacar = false;
        
        (it->second).reducir_t(n, sacar);
        if(sacar) borrar2(it);
        else ++it;
    }
}

void Procesador::borrar(int id){
    Proceso k;
    map<int, Proceso>::iterator it = p.begin();
   
    while (it != p.end()){
        k = it->second;
        
        if(k.id_p() == id){
            mem_res+=k.mem();
            it = p.erase(it);
        }
        
        else ++it;
    }
    
}

void Procesador::borrar2(map<int, Proceso>::iterator& it){
    mem_res+=(it->second).mem();
    it = p.erase(it);
}

void Procesador::consulta_max(){
    map<int, Proceso>::iterator it = p.begin();
    while (it != p.end()){
        cout << "  " << it->first << ' ' << (it->second).usuario() << ' ' << (it->second).id_p();
        cout << ' ' << (it->second).mem() << ' ' << (it->second).tiem() << endl;
        it++;
    }
}

bool Procesador::incluir(Proceso& pr){
    bool puesto = false;
    map<int, Proceso>::iterator it = p.begin();
    int mem_p = pr.mem();
    int pos;
    if(not p.empty()){
        int pos_aux = it->first, pos_aux2, espacio_libre = mem + 1;
        if (pos_aux != 0 and pos_aux >= mem_p){
            pos = 0;
        } 
        pos_aux2 = pos_aux + it->second.mem();
        int espacio_libre2;
        ++it;
        while(it != p.end()){
            pos_aux = (*it).first;
            espacio_libre2 = pos_aux - pos_aux2;
            if(espacio_libre2 >= mem_p and espacio_libre > espacio_libre2){
                pos = pos_aux2;
                espacio_libre = espacio_libre2;
            }
            pos_aux2 = pos_aux + it->second.mem();
            ++it;
        }
        espacio_libre2 = mem - pos_aux2;
        if (espacio_libre2 >= mem_p and espacio_libre > espacio_libre2){
            pos = pos_aux2;
            espacio_libre = espacio_libre2;
        }
        if (espacio_libre < mem + 1){
            p.insert(make_pair(pos,pr));
            mem_res -= pr.mem();
            puesto = true;
        }
    }
    else if (pr.mem() <= mem) {
        p.insert(make_pair(0, pr));
        mem_res -= pr.mem();
        puesto = true;
    }  
    return puesto;
}

int Procesador::consulta_mem_res(){
    return mem_res;
}

void Procesador::leer_memoria(){
    cin >> mem;
    mem_res = mem;
}

int Procesador::consulta_mem(){
    return mem;
}

bool Procesador::hueco(int mem_p){
    bool hueco = false;
    map<int, Proceso>::iterator it = p.begin();
    if(not p.empty()){
        int pos_aux = it->first, pos_aux2, espacio_libre = mem + 1;
        if (pos_aux != 0 and pos_aux >= mem_p){
            espacio_libre = pos_aux;
        } 
        pos_aux2 = pos_aux + it->second.mem();
        int espacio_libre2;
        ++it;
        while(it != p.end()){
            pos_aux = (*it).first;
            espacio_libre2 = pos_aux - pos_aux2;
            if(espacio_libre2 >= mem_p and espacio_libre > espacio_libre2){
                espacio_libre = espacio_libre2;
            }
            pos_aux2 = pos_aux + it->second.mem();
            ++it;
        }
        espacio_libre2 = mem - pos_aux2;
        if (espacio_libre2 >= mem_p and espacio_libre > espacio_libre2){;
            espacio_libre = espacio_libre2;
        }
        if (espacio_libre < mem + 1){
            hueco = true;
        }
    }
    else if (mem_p <= mem) {
        hueco = true;
    }  
    return hueco;
}