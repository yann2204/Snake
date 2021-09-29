#include"affichage.hpp"
#include"serpent.hpp"
#include<ncurses.h>
#include<unistd.h>

#define TIME_OUT 1

void Affichage::print_snake() {
	int size = snake.size();
	for (int i = 0; i<size;i++) {
		//printw("boucle :%c\n",snake[i]->caracter);
		SetElement(snake[i]->position_x,snake[i]->position_y,snake[i]->caracter);
	}
}

void Affichage::SetElement(int i, int j,char c) {
	this->tab[i*(width)+j]=c;
}

char Affichage::GetElement(int i, int j) {
	return this->tab[i*(width)+j];
}

void Affichage::run() {
	int size = snake.size();
	//supprime le serpent de l'affichage
	for (int i = 0;i<size;i++) {
		this->tab[snake[i]->position_x*width+snake[i]->position_y] = ' ';
		if (i!=size-1) {
			snake[i+1]->dir = snake[i]->dir;
		}
		timeout(TIME_OUT);
		noecho();
		char ch = getch();
		if (ch == 'z') {
			printw("up");
			snake[0]->dir=haut;
		}
		else if(ch == 's') {
			snake[0]->dir = bas;
		}
		else if(ch == 'd') {
			snake[0]->dir = droite;
		}
		else if(ch == 'q') {
			snake[0]->dir = gauche;
		}
		else {
			snake[0]->dir = snake[1]->dir;
		}
	}
	Serpent::run();
	print_snake();
	
}

void Affichage::affiche() {
	for (int i = 0;i<height;i++) {
		for (int j = 0;j<width;j++) {
			printw("%c",GetElement(i,j));
		}
		printw("\n");
	}
}
