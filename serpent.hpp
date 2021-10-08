#pragma once
#include<vector>
#include"corps.hpp"

class Serpent {
	protected:
		std::vector<Corps *> snake;
		Corps * tail;
	public:
		Serpent(int height,int width) {
			snake.push_back(new Corps((int)height/2,(int) (width/2)));
			snake.push_back(new Corps((int)height/2,(int) (width/2)-1));
			snake.push_back(new Corps((int)height/2,(int) (width/2)-2));
			snake.push_back(new Corps((int)height/2,(int) (width/2)-3));
			tail = new Corps((int)height/2,(int) (width/2)-3);
		}
		void MoveSnake();
		void GrowUp();
		bool IsBiting();//renvoie true si le sermpent se mord la queue
};
