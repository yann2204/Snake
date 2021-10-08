#include"serpent.hpp"
#include"affichage.hpp"

void Serpent::MoveSnake() {
	//xtail = snake[size-1]->position_x;
	//ytail = snake[size-1]->position_y;
	for(auto x : snake) {
		switch(x->dir) {
			case droite : x->position_y++;break;
			case gauche : x->position_y--;break;
			case haut : x->position_x--;break;
			case bas : x->position_x++;break;
		}
	}
}

void Serpent::GrowUp() {
	snake.push_back(new Corps(tail->position_x,tail->position_y,tail->dir,'o'));
	//zzzzzzzzzzzzzztime_out--;ddzsqzdsqzdqsqdzqdqsds
}

bool Serpent::IsBiting() {
	int size = snake.size();
	for (int i = 1;i<size;i++) {
		if ((snake[0]->position_x == snake[i]->position_x) && (snake[0]->position_y==snake[i]->position_y)) {
			return true;
		}
	}
	return false;
}