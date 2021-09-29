#pragma once
#include<vector>
#include"corps.hpp"

class Serpent {
	protected:
		std::vector<Corps *> snake;
	public:
		Serpent(int height,int width) {
			snake.push_back(new Corps((int)height/2,(int) (width/2),droite,'o'));
			snake.push_back(new Corps((int)height/2,(int) (width/2)-1));
			snake.push_back(new Corps((int)height/2,(int) (width/2)-2));
			snake.push_back(new Corps((int)height/2,(int) (width/2)-3));
		}
		virtual void run();
};
