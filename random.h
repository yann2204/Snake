#ifndef RANDOM
#include<ctime>
#include<iostream>
#define RANDOM

int GetRandomInteger(int binf,int bsup) {
    int delta = bsup-binf;
    srand(time(nullptr));
    int s = rand()%delta+binf;
    return s;
}
#endif