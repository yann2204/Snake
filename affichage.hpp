#include<iostream>
#include<cstdlib>
#include<ncurses.h>
#include<unistd.h>
#include"serpent.hpp"
#include"corps.hpp"
#pragma once



class Affichage : public Serpent{
	private:
		int height,width;
		char * tab;

	public:
		Affichage(int m,int n) : Serpent(m,n),height(m), width(n), tab(new char[height*width]) {
			for(int i =0;i<height;i++) {
				for (int j = 0;j<width;j++) {
					if ((j==width-1) || (j==0)) SetElement(i,j,'|');
					else if ((i==height-1) || (i==0)) SetElement(i,j,'-');
					else SetElement(i,j,' ');
				}
			}
			Add_Food();
			print_snake();
		}
		void affiche();
		void Add_Food();
		void print_snake();
		void SetElement(int i, int j,char c);
		char GetElement(int i, int j);
		void run();
		void ClearTab();
		void GameOver();
};
