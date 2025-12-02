EXEC=tp4
CXXFLAGS= -g -O0 -Wall -std=c++17

$(EXEC) : utilitaire_generation.o main.o
	g++ -o $(EXEC) utilitaire_generation.o main.o

main.o : main.cpp utilitaire_generation.h
	g++ -c $(CXXFLAGS) main.cpp

utilitaire_generation.o : utilitaire_generation.cpp utilitaire_generation.h
	g++ -c $(CXXFLAGS) utilitaire_generation.cpp

clean :
	rm -f $(EXEC) *.o