#include "miniMap.h"

SDL_Surface *LOAD_IMG(char fileName[20])
{
    SDL_Surface *img=NULL;
    img=IMG_Load(fileName);
    if(img==NULL)
        printf("ERROR /> %s\n",SDL_GetError());
    return img;
}
void Init_miniMap(Map *miniMap)
{
    miniMap->img=LOAD_IMG("miniMap.jpg");
    miniMap->posMap.x=0;
    miniMap->posMap.y=0;
    miniMap->posMap.w=400;
    miniMap->posMap.h=200;
}
void Draw_MiniMap(Map miniMap,SDL_Surface *Screen)
{
    SDL_BlitSurface(miniMap.img,NULL,Screen,&miniMap.posMap);
}


int collisionBB(SDL_Rect *perso,SDL_Rect bloc)
{
    if(perso->x + perso->w > bloc.x && perso->x < bloc.x + bloc.w && perso->y + perso->h > bloc.y && perso->y < bloc.y + bloc.h)
    {
        printf("collision detected\n");
        return 1;
    }

    else
    {
        printf("no collision detected\n");
        return 0;
    }
}

void gravity(SDL_Rect *perso, SDL_Rect bloc, int direction)
{
    if(collisionBB(perso,bloc)!=1&&direction!=1)
    {
        printf("famma gravity\n");
        perso->y++;
    }
}

void MAJminiMap(SDL_Rect *entity_flm,SDL_Rect hero,int direction)
{
    if(direction==1)
    {
        entity_flm->y-=8;
        entity_flm->x+=2;
    }   

    else if(direction==2)
        entity_flm->y+=2;

    else if(direction==3)
        entity_flm->x+=2;
    else
        entity_flm->x-=2;
}