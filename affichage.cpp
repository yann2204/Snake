#include"affichage.hpp"
#include"serpent.hpp"
#include<ncurses.h>
#include<unistd.h>
#include<assert.h>
#include<iostream>
#include<string.h>
#include"random.h"

static int time_out  = 500;

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
	//Met à jour la queue du serpent
	tail->position_x = snake[size-1]->position_x;
	tail->position_y = snake[size-1]->position_y;
	tail->dir = snake[size-1]->dir;
	//supprime le serpent de l'affichage
	for (int i = 0;i<size;i++) this->tab[snake[i]->position_x*width+snake[i]->position_y] = ' ';
	for (int i = size-1;i>0;i--) snake[i]->dir = snake[i-1]->dir;
	timeout(time_out);
	noecho();
	char ch = getch();
	if (ch == 'z') {
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
	MoveSnake();
	//test la situation du serpent
	if (GetElement(snake[0]->position_x,snake[0]->position_y)=='@') {
		time_out-=10;
		
		GrowUp();//ajoute la queue du serpent 
		
		print_snake();
		Add_Food();
	}
	else if ((GetElement(snake[0]->position_x,snake[0]->position_y)=='-') || (GetElement(snake[0]->position_x,snake[0]->position_y)=='|') || IsBiting())  {
		GameOver();
	}
	else {
		
		print_snake();
	}
}

void Affichage::affiche() {
	for (int i = 0;i<height;i++) {
		for (int j = 0;j<width;j++) {
			printw("%c",GetElement(i,j));
		}
		printw("\n");
	}
}
void Affichage::ClearTab() {
	for (int i = 0; i<(height*width);i++) tab[i] = ' ' ;
}

void Affichage::GameOver() {
	assert(width>75 && height>6);
	ClearTab();
    std::string Display = "  ______                      ______         ______          ______  ____   /           /|     /|    /| |              /      \\ \\    | |       |    \\ |           / |    / |   / | |              |      |  \\   | |       |     ||    ___   /__|   /  |  /  | |---           |      |   \\  | |---    |____/ |      |  /   |  /   | /   | |              |      |    \\ | |       |    \\  \\_____| /    | /    |/    | |______        \\______/     \\| |______ |     \\";
    int deltaj = (width-75)/2;
    int deltai = (height-6)/2;
    for (int i = 0; i<6; i++) {
        for (int j = 0;j<75;j++) {
            SetElement(deltai+i,deltaj+j,Display[i*75+j]);
        }
    }
}

void Affichage::Add_Food() {
	int x,y;
	do{
		x = GetRandomInteger(1,height-1);
		y = GetRandomInteger(1,width-1);
	}
	while(GetElement(x,y)=='o');
	SetElement(x,y,'@');
}