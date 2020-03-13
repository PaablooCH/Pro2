#include "Cluster.hh"
#include "Cjnt_Usuario.hh"

#include <iostream>
#include <string>
using namespace std;

int main (){
    string s;
    int n;
    Cluster c;
    Cjnt_Usuario c_u;
    
    while(cin >> s and s != "acabar"){
        
        if(s == "configurar_cluster"){
            c.configurar_cluster();
        }
 
        else if(s == "consultar_procesador"){
            cin >> n;
            cout << "Procesador " << n << endl;
            c.consultar_procesador(n);
        }
 
        else if(s == "poner_usuario"){
            cin >> s;
            c_u.poner_usuario(s);
        }
 
        else if(s == "quitar_usuario"){
            cin >> s;
            c_u.quitar_usuario(s);
        }
        
        else if(s == "poner_proceso_en_procesador"){
            Proceso p;
            Usuario u;
            cin >> n;  //id de procesador
            p.leer();
            if(c_u.existe_usuario(p.usuario())){
                bool puesto=false;
                c.poner_proceso_en_procesador(n, p, puesto);
                if(not puesto) c_u.enviar_proceso_a_usuario(p);
            }
        }
        
        else if(s == "quitar_proceso_de_procesador"){
            cin >> n;
            int aux = n;   // id procesador
            cin >> n;    // id proceso
            c.quitar_proceso_de_procesador(aux, n); 
        }
        
        else if(s == "enviar_proceso_a_usuario"){
            Proceso p;
            p.leer();
            if(c_u.existe_usuario(p.usuario())) c_u.enviar_proceso_a_usuario(p);
        }
        
        else if(s == "consultar_usuario"){
            cin >> s;
            cout << "Usuario " << s << endl;
            
            if(c_u.existe_usuario(s)){
                c_u.consultar_usuario(s);
            }
        }
        
        else if(s == "avanzar_tiempo"){
            cin >> n;  //unidades de tiempo
            c.avanzar_tiempo(n);
        }
        
        else if(s == "enviar_procesos_a_cluster"){
            cin >> n;  //num de procesos
            c_u.enviar_procesos_a_cluster(n, c);
        }
 
    }
 
}
