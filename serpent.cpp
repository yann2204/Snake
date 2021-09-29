#include"serpent.hpp"

void Serpent::run() {
	for(auto x : snake) {
		switch(x->dir) {
			case droite : x->position_x++;break;
			case gauche : x->position_x--;break;
			case haut : x->position_y++;break;
			case bas : x->position_y--;break;
		}
	}
	
}
