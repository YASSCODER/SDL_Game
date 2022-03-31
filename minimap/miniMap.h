#ifndef MINIMAP_H
#define MINIMAP_H

#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    SDL_Surface *img,*surtext;;
    SDL_Rect posMap,posPlayer;
    Uint32 color;
    int timer;
}Map;

SDL_Surface *LOAD_IMG(char fileName[20]);
void Init_miniMap(Map *miniMap);
void Draw_MiniMap(Map miniMap, SDL_Surface *Screen);
int collisionBB(SDL_Rect *perso,SDL_Rect bloc);
void gravity(SDL_Rect *perso, SDL_Rect bloc, int direction);
void MAJminiMap(SDL_Rect *entity_flm,SDL_Rect hero,int direction);



#endif//MINIMAP_H