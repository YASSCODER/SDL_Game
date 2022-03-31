#ifndef PP_H
#define PP_H

#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    SDL_Surface *sprite;
    SDL_Rect DST,SRC;
    int vie, score,direction,jumpmax;
}Hero;

SDL_Surface *LOAD_IMG(char fileName[20]);
void Init_PP(Hero *myHero);
void Draw_PP(Hero myHero, SDL_Surface *Screen);
void movment_PP(Hero *myHero);
int CollisionBB(Hero *myHero, SDL_Rect entity);
void Gravity(Hero *myHero, SDL_Rect entity, int keyZ);
int Jump_PP(Hero *myHero,int jumpmax);


#endif