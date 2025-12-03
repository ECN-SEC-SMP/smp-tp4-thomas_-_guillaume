EXEC=tp4
CXXFLAGS= -g -O0 -Wall -std=c++17

$(EXEC) : utilitaire_generation.o main.o utilitaires.o
	g++ -o $(EXEC) utilitaire_generation.o main.o utilitaires.o

main.o : main.cpp utilitaires.h utilitaire_generation.h type_def.h
	g++ -c $(CXXFLAGS) main.cpp

utilitaire_generation.o : utilitaire_generation.cpp utilitaire_generation.h
	g++ -c $(CXXFLAGS) utilitaire_generation.cpp

utilitaires.o : utilitaires.cpp  utilitaires.h
	g++ -c $(CXXFLAGS) utilitaires.cpp

clean :
	rm -f $(EXEC) *.o