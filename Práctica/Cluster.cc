#include "Cluster.hh"

Cluster::Cluster(){
    
}

void Cluster::configurar_cluster(){
    cin >> n;
    crear_cluster(id);
    vector<Procesador> aux (n);
    proc = aux;
    for(int i = 0; i < n; i++){
        proc[i].leer_memoria();
    }
}

void Cluster::crear_cluster(BinTree<int>& id1){ 
    int identi;

    cin >> identi;
    if(identi!=0){
        BinTree<int> ide;
        crear_cluster(ide);
        BinTree<int> idr;
        crear_cluster(idr);
        BinTree<int> aux(identi, ide, idr);
        id1 = aux;
    }
}

void Cluster::avanzar_tiempo(int ti){

    for(int i = 0; i < n; i++){
        proc[i].reduccion_tiempos(ti);
    }
}


void Cluster::consultar_procesador(int id_pro){
        proc[id_pro-1].consulta_max();
}

void Cluster::poner_proceso_en_procesador(int id_pro, Proceso& p, bool& puesto){
    if(proc[id_pro-1].consulta_mem_res() >= p.mem()){
        puesto = proc[id_pro-1].incluir(p);
    }
}


void Cluster::quitar_proceso_de_procesador(int id_pro, int id_p){
    proc[id_pro-1].borrar(id_p);
}

int Cluster::procesador_optimo(int mem_p){
    int pr = 1;
    bool primero = true;
    i_procesador_optimo(id, pr, mem_p, primero);
    return pr;
}

void Cluster::i_procesador_optimo(const BinTree<int>& id1, int& pr, int mem_p, bool& primero){
    if(not id1.empty()){
        int identi = id1.value();

        if(primero or proc[identi-1].hueco(mem_p)){

            if(primero){
                if(proc[identi-1].hueco(mem_p)){
                    pr = identi;
                    primero = false;
                }
            }

            else if (proc[identi-1].consulta_mem_res() >= proc[pr].consulta_mem_res()) pr = identi;
            
            else {
                int profundidad_pr;
                int profundidad_id;
                bool encontrado = false;
                profundidad_pr = consultar_profundidad(id, pr, encontrado);
                encontrado = false;
                profundidad_id = consultar_profundidad(id, identi, encontrado);

                if(profundidad_id < profundidad_pr) pr = identi;
            }
        }
        i_procesador_optimo(id1.left(), pr, mem_p, primero);
        i_procesador_optimo(id1.right(), pr, mem_p, primero); 
    }
}

int Cluster::consultar_profundidad(const BinTree<int>& id1, int id_pro, bool& encontrado){
    int n = 0;

    if(not id1.empty()){
        int identi = id1.value();

        if(identi == id_pro){
            ++n;
            encontrado = true;
        }

        else if(not encontrado){
            n = 1 + consultar_profundidad(id1.left(), id_pro, encontrado);
            if(not encontrado) n = 1 + consultar_profundidad(id1.right(), id_pro, encontrado);
        }
    }

    return n;
}

/*
bool Processador::poner_proceso_en_procesador(Proceso& p){
        int memproces = p.mem();
        if(not n > 0){
            map<int, Proces>::iterator it = memoriaindex.begin();
            int x = INT_MAX, inici_aux, inici = (*it).first, fi;
            if (inici != 0 and inici >= memproces){
                inici_aux = 0;
                x = inici;
            } 
            fi = inici + (*it).second.consultar_memoria();
            ++it;
            for(; it != memoriaindex.end(); ++it){
                inici = (*it).first;
                int resta1 = inici-fi;
                if(resta1 >= memproces and x > resta1){
                    inici_aux = fi;
                    x = resta1;
                }
                fi = inici + (*it).second.consultar_memoria();
            }
            if (memoriatotal > fi){
                int resta2 = memoriatotal-fi;
                if (resta2 >= memproces and resta2 < x){
                    inici_aux = fi;
                    x = resta2;
                }
            }
            if (x != INT_MAX){
                memoriaindex.insert(make_pair(inici_aux,p));
                memoriatotal_lliure -= p.consultar_memoria();
                return true;
            }
            else return false;
        }
        else if (memoriaindex.empty() and memproces <= memoriatotal) {
            memoriaindex.insert(make_pair(0, p));
            memoriatotal_lliure -= p.consultar_memoria();
            return true;
        }  
        else return false;
    }
    */