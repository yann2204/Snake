#include<ncurses.h>
#include<unistd.h>
#include<cstdlib>
#include<iostream>
#include"affichage.hpp"
//-lcurses


int main() {
	initscr();
	Affichage aff = Affichage(52,210);
	while(1) {
		aff.affiche();
		refresh();
		aff.run();
		sleep(1);
		clear();
	}
	endwin();
	return EXIT_SUCCESS;
}


