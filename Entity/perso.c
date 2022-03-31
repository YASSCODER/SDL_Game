#include"perso.h"

void init_perso(Player *hero, SDL_Surface *screen)
{
    hero->color=SDL_MapRGB(screen->format,255,0,0);

    hero->position.x=hero->position.y=500;
    hero->position.w=hero->position.h=64;

    hero->direction=0;
}
void afficher_perso(SDL_Surface *Screen,Player hero)
{
    SDL_FillRect(Screen,&hero.position,hero.color);
}
void deplacer_perso(Player *Hero)
{
    if(Hero->direction==1)
        Hero->position.x++;
    if(Hero->direction==2)
        Hero->position.x--;
    if(Hero->direction==3)
        Hero->position.y++;
    if(Hero->direction==4)
        Hero->position.y--;
    
}