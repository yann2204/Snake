#pragma once
typedef enum {haut,bas,gauche,droite} Direction;

struct Corps {
	char caracter;
	Direction dir;
	int position_x,position_y;
	Corps(int pos_x,int pos_y,Direction d = droite, char c = 'o') {
		dir = d;
		caracter = c;
		position_x = pos_x;
		position_y = pos_y;
	}
};
