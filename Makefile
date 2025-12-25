EXEC=tp4
CXXFLAGS= -g -O0 -Wall -std=c++17

$(EXEC) : utilitaire_generation.o main.o utilitaires.o repertoire.o
	g++ -o $(EXEC) utilitaire_generation.o main.o utilitaires.o repertoire.o

main.o : main.cpp utilitaire_generation.h type_def.h utilitaires.h repertoire.h
	g++ -c $(CXXFLAGS) main.cpp

utilitaire_generation.o : utilitaire_generation.cpp utilitaire_generation.h 
	g++ -c $(CXXFLAGS) utilitaire_generation.cpp

utilitaires.o : utilitaires.cpp  utilitaires.h type_def.h utilitaire_generation.h 
	g++ -c $(CXXFLAGS) utilitaires.cpp

repertoire.o : repertoire.cpp repertoire.h utilitaires.h type_def.h 
	g++ -c $(CXXFLAGS) repertoire.cpp


clean :
	rm -f $(EXEC) *.o