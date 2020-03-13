OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

#
program.exe: Cjnt_Usuario.o Cluster.o program.o Procesador.o Proceso.o Usuario.o
	g++ -o program.exe *.o

#
Cjnt_Usuario.o: Cjnt_Usuario.cc
	g++ -c Cjnt_Usuario.cc $(OPCIONS)

#
Cluster.o: Cluster.cc BinTree.hh
	g++ -c Cluster.cc $(OPCIONS)

#
program.o: program.cc Procesador.cc Proceso.cc Usuario.cc Cluster.cc Cjnt_Usuario.cc
	g++ -c program.cc $(OPCIONS)

#
Procesador.o: Procesador.cc
	g++ -c Procesador.cc $(OPCIONS)

#
Proceso.o: Proceso.cc
	g++ -c Proceso.cc $(OPCIONS)

#
Usuario.o: Usuario.cc
	g++ -c Usuario.cc $(OPCIONS)

clean:
	rm -f *.o 
	rm -f *.exe
