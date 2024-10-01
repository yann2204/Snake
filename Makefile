
jouer: main.cpp affichage.cpp serpent.cpp
	g++ -Wall main.cpp affichage.cpp serpent.cpp -lncurses -o jouer 
clean:
	rm *.o jouer

