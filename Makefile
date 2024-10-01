
CPPFLAG += -lncurses -Wall
OBJS = main.o affichage.o serpent.o 
all : jouer
.c.o : 
	g++ $(CPPFLAG) -c $< $(CPPFLAG) 
jouer : $(OBJS)
	g++ -o $@ $(OBJS) $(CPPFLAG) 
clean:
	rm *.o jouer

