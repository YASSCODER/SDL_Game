#ifndef BACKGROUND_H
#define BACKGROUND_H
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include<stdio.h>
#include<stdlib.h>
#define CAMERA_W 1200
#define CAMERA_H 800
typedef struct
{   
    SDL_Surface *img;
    SDL_Rect src,dist,scroll;
    Mix_Music *music;
}background;

void init_background1(background *BK);
void init_background2(background *BK);
void init_background3(background *BK);
void Afficher_Background(background BK, SDL_Surface *screen);
void annimer_background(background *e);
int collisionPP(SDL_Rect perso,SDL_Rect maske1);
void scrolling(background *BK, int direction, int keyD, int keyQ);

#endif //BACKGROUND_H